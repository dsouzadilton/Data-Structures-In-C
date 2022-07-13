#include<stdio.h>
#include<conio.h>
#define MAX 5
typedef struct queue{
    int queue_array[MAX];
    int rear;
    int front;
}queue;

void enqueue( queue *q)
{
    int ele;
    if (q->rear == MAX - 1)
        printf("Overflow \n");
    else
    {
        if (q->front == - 1)
            q->front = 0;
        printf("Enter the element: ");
        scanf("%d", &ele);
        q->rear = q->rear + 1;
        q->queue_array[q->rear] = ele;
    }
}
void dequeue(queue *q)
{
    if (q->rear < q->front)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q->queue_array[q->front]);
        q->front = q->front + 1;
    }
}
void display(queue *q)
{
    int i;
    if (q->front == -1 || q->rear < q->front)
        printf("Queue is Empty! \n");
    else
    {
        printf("Queue is: ");
        for (i = q->front; i <= q->rear; i++)
            printf("%d ", q->queue_array[i]);
        printf("\n");
    }
} 

int main()
{
    int choice;
    queue q;
    q.front =-1;
    q.rear = -1;
    while (1)
    {
        printf("\n1.Insert    2.Delete    3.Display   4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(1);
            case 5:
                isEmpty(&q);
                break;
            case 6:
                isFull(&q);
                break;
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
} 
