#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a new element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Assuming -1 is not a valid element in the queue
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = temp->next;
    }

    free(temp);
    return data;
}

// Function to display the elements of the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to get the front element of the queue without dequeuing
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Assuming -1 is not a valid element in the queue
    }
    return queue->front->data;
}

// Function to get the rear element of the queue without dequeuing
int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Assuming -1 is not a valid element in the queue
    }
    return queue->rear->data;
}

// Function to free the memory allocated for the queue
void deleteQ(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Queue elements: ");
    displayQueue(&myQueue);

    printf("Front element: %d\n", front(&myQueue));
    printf("Rear element: %d\n", rear(&myQueue));

    dequeue(&myQueue);

    printf("After dequeueing one element:\n");
    printf("Front element: %d\n", front(&myQueue));
    printf("Rear element: %d\n", rear(&myQueue));

    deleteQ(&myQueue);

    return 0;
}
