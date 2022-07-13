#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;
node* getnode(){
	node *link = (node*)malloc(sizeof(node));
    return link;
}
void Enqueue(int data){
    node *link = getnode();
     link->data = data;
     link->next = NULL;
     rear = link;
     if(isEmpty()){
        front = link;
    }
    else{
    node *ptr = front;
    node *prev = NULL;
    while(ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
   }
   prev->next = link;
  }
}
void Dequeue() {
    if(!isEmpty()){
   printf("Dequeued element: %d",front->data);
    free(front);
    front = front->next;
    }
    else
        printf("Queue is Empty!");
}
int isEmpty(){
    if(front == NULL)
        return 1;
    else return 0;
}
void Peek(){
    if(!isEmpty()){
    printf("Element at front: %d",front->data);
    }
    else
        printf("Queue is Empty!");
}
void Display(){
    if(!isEmpty()){
        node *ptr = front;
   printf("Queue:");
   while(ptr != NULL) {
      printf(" %d",ptr->data);
      ptr = ptr->next;
   }
    }
    else
        printf("Queue is Empty!");
}
void DestroyQueue(){
    front=rear=NULL;
    printf("Queue Destroyed!");
}
int main()
{
    int ch,ele;
    while(1){
        printf("\n1.Enqueue    2.Dequeue      3.Peek     4.Display  0.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&ele);
                Enqueue(ele);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 0:
                exit(0);
        }
    }
}

