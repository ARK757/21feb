#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertAtBeginning(node** head, int data) {
    node* newnode = createnode(data);
    newnode->next = *head;
    *head = newnode;
}

void insertAtEnd(node** head, int data) {
    node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newnode;
}

void insertAfter(node *prevnode, int data) {
    if (prevnode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node* newnode = createnode(data);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}

void deletenode(node** head, int data) {
    if (*head == NULL) {
        return;
    }
    node* temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return; // Data not found
    }
    if (prev == NULL) {
        *head = temp->next; // Delete head node
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

node* search(node* head, int data) {
    while (head != NULL && head->data != data) {
        head = head->next;
    }
    return head;
}

void printList(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main(){
    return 0;
}
