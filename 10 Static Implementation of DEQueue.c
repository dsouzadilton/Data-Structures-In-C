#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int arr[MAX];
int front=-1;
int rear=-1;

void insertFront(int data){
    if( isFull() ){
        printf("\nQueue is Full!\n");
        return;
    }if( front ==-1 ){
        front=0;
        rear=0;
    }else if(front==0)
        front=MAX-1;
    else
        front=front-1;
    arr[front]=data ;
}

void insertRear(int data){
    if( isFull() ){
        printf("\nQueue is Full!\n");
        return;
    }if(front==-1)  {
        front=0;
        rear=0;
    }else if(rear==MAX-1)  
        rear=0;
    else
        rear=rear+1;
    arr[rear]=data ;
}
 
int deleteFront(){
    int data;
    if( front == -1){
        printf("\nQueue is Empty!\n");
    }else{
    data = arr[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }else
        if(front==MAX-1)
            front=0;
        else
            front=front+1;
    printf("Element Deleted: %d",data);
    }
}
 
void deleteRear(){
    int data;
    if( front ==-1){
        printf("\nQueue is Empty!\n");
    }else{
    data = arr[rear];
    if(front==rear) {
        front=-1;
        rear=-1;
    }else if(rear==0)
        rear=MAX-1;
    else
        rear=rear-1;
    printf("Element Deleted: %d",data);
    }
}

 void display(){
    if( front == -1){
        printf("\nQueue is Empty!\n");
        return;
    }else{
    printf("\nQueue: ");
        if( front<=rear ){
            for(int i=front;i<=rear;i++)
                printf("%d ",arr[i]);
        }else{
            for(int i=front;i<=MAX-1;i++)
               printf("%d ",arr[i]);
            for(int i=0;i<=rear;i++)
                printf("%d ",arr[i]);
        }
    }
}

int isFull(){
    if ( (front==0 && rear==MAX-1) || (front==rear+1) )
        return 1;
    else
        return 0;
}

    int main(){
    int ch,ch1,ch2,ele;
    while(1){
        printf("\n1.Input restricted    2.Output restricted     3.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                while(ch1!=5){
                    printf("\n1.Insert Rear    2.Delete Front     3.Delete Rear    4.Display     5.Exit\n");
                    scanf("%d",&ch1);   
                    switch(ch1){
                        case 1:
                            printf("Enter the Element: ");
                            scanf("%d",&ele);
                            insertRear(ele);
                            break;
                        case 2:
                            deleteFront();
                            break;
                        case 3:
                            deleteRear();
                            break;
                        case 4:
                            display();
                            break;
                        case 5:
                            printf("Exiting from Input restricted DEQue...");
                    }
                }
                break;
            case 2:
                while(ch2!=5){
                    printf("\n1.Insert front    2.Insert Rear   3.Delete front  4.Display    5.Exit\n");
                    scanf("%d",&ch2);
                    switch(ch2){
                        case 1:
                            printf("Enter the Element: ");
                            scanf("%d",&ele);
                            insertFront(ele);
                            break;
                        case 2:
                            printf("Enter the Element : ");
                            scanf("%d",&ele);
                            insertRear(ele);
                            break;
                        case 3:
                            deleteFront();
                            break;
                        case 4:
                            display();
                            break;
                        case 5:
                            printf("Exiting from Output restricted DEQue...");
                    }
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice!");
        }
    }
    return 0;
}