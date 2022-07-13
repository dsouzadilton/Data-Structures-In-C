#include<stdio.h>
#include<conio.h>
# define MAX 5
typedef struct queue{
    int cqueue_arr[MAX];
    int front;
    int rear;
}queue;
void enqueue(queue *q)
{
    int ele;
    if((q->front == 0 && q->rear == MAX-1) || (q->front == q->rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        if(q->rear == MAX-1)
            q->rear = 0;
        else
            q->rear = q->rear+1;
    }
    printf("Enter the element: ");
    scanf("%d", &ele);
    q->cqueue_arr[q->rear] = ele;
}
void dequeue(queue *q)
{
    if(q->front == -1)
    {
        printf("Queue Underflow!\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",q->cqueue_arr[q->front]);
    if(q->front == q->rear)
    {   
        q->front = -1;
        q->rear=-1;
    }
    else
    {
        if(q->front == MAX-1)
            q->front = 0;
    else
        q->front = q->front+1;
    }
}
void display(queue *q)
{
    int front_pos = q->front,rear_pos = q->rear;
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    if( front_pos <= rear_pos )
        while(front_pos <= rear_pos)
        {
            printf("%d ",q->cqueue_arr[front_pos]);
            front_pos++;
        }
    else
    {
        while(front_pos <= MAX-1)
        {
            printf("%d ",q->cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {
            printf("%d ",q->cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
int main()
{
    queue q;
    q.front =-1;
    q.rear = -1;
    int choice;
    while (1)
    {
        printf("1.Insert    2.Delete    3.Display   4.Quit\n");
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
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}
