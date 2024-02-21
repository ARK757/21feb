#include <stdio.h>
#include <limits.h>

typedef struct queue
{
    int value;
    int prty;
} queue;

int size = -1;

void enqueue(queue pr[], int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].prty = priority;
}

int peek(queue pr[])
{
    int highPrty = INT_MIN;
    int ind = -1;
    for (int i = 0; i <= size; i++)
    {
        if (pr[i].prty > highPrty)
        {
            highPrty = pr[i].prty;
            ind = i;
        }
        else if (pr[i].prty == highPrty && pr[i].value > pr[ind].value && ind > -1)
        {
            highPrty = pr[i].prty;
            ind = i;
        }
    }
    return ind;
}

void dequeue(queue pr[])
{
    int ind = peek(pr);
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    }
    size--;
}

int main()
{

    queue pr[10];
    enqueue(pr, 10, 2);
    enqueue(pr, 16, 4);
    enqueue(pr, 14, 4);
    enqueue(pr, 12, 3);

    int ind = peek(pr);
    printf("%d\n", pr[ind].value);
    
    dequeue(pr);
    printf("%d\n", pr[ind].value);
    
    dequeue(pr);
    printf("%d\n", pr[ind].value);
    

    return 0;
}
