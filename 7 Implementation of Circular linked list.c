#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

void insertFirst(int data) {
    node *link = getnode();
    link->data = data;
    if(isEmpty()) {
        link->next = link;
        front = link;
        rear = link;
    }
    else {
        link->next = front;
        front = link;
    }
}

void insertlast(int data){
    node *link = getnode();
    link->data = data;
    link->next = front;
    if(isEmpty()) {
        link->next = link;
        front = link;
        rear = link;
    }else   {
        rear->next = link;
        rear = link;
    }
}

void insertAfter(int data){
    node *link = getnode();
    link->data = data;
    if(isEmpty()){
        link->next = link;
        front = link;
        rear = link;
    }else {
        int ele;
        printf("Enter the value after which node to be inserted: ");
        scanf("%d",&ele);
        node *ptr = front;
        while(ptr->data != ele){
            ptr=ptr->next;
        }
        if(ptr == rear){
            ptr->next=link;
            rear = link;
            link->next = front;
        }else {
            node *temp=ptr->next;
            ptr->next=link;
        link->next=temp;
        }
    }
}

void insertBefore(int data){
    node *link = getnode();
    link->data = data;
    if(isEmpty()) {
        link->next = link;
        front = link;
        rear = link;
    }else {
        int ele;
        printf("Enter the value before which node to be inserted: ");
        scanf("%d",&ele);
        node *ptr = front;
        node *prev = NULL;
        while(ptr->data != ele){
            prev = ptr;
            ptr=ptr->next;
        }
        if(front->data==ele){
            link->next = front;
            front = link;
        }else {
            prev->next=link;
            link->next=ptr;
        }
    }
}

void deleteFirst() {
    if(isEmpty()){
        printf("Queue is Empty!");
    }else {
        printf("Deleted Node: %d",front->data);
        rear->next = front->next;
        free(front);
        front = rear->next;
    }
}

void deletelast(){
    if(isEmpty()) {
        printf("Queue is Empty!");
    }else {
        node *prev = NULL;
        node *ptr = front;
        while(ptr->next != front) {
            prev = ptr;
            ptr = ptr->next;
        }
        printf("Deleted Node: %d",ptr->data);
        free(ptr);
        rear = prev;
        rear->next = front;
    }
}

void deleteBefore(){
    int ele;
    printf("Enter the value before which node to be deleted: ");
    scanf("%d",&ele);
    node *ptr = front;
    node *prev = NULL;
    while(ptr->next->data != ele){
        prev = ptr;
        ptr=ptr->next;
    }if(front->next==rear && rear->data == ele){
        prev=front;
        front=rear;
        free(prev);
    }else{
    prev->next = ptr->next;
    free(ptr);
    }
}

void deleteAfter(){
    int ele;
    printf("Enter the value after which node to be deleted: ");
    scanf("%d",&ele);
    node *ptr = front->next;
    node *prev = front;
    while(prev->data != ele){
        prev = ptr;
        ptr=ptr->next;
    }
    if(ptr==rear){
        rear = prev;
        prev->next = front;
        free(ptr);
    }else if(prev == front){
        rear=front->next;
        front=front->next;
        free(prev);
    }else if(ptr==front){
        prev->next = front->next;
        rear = prev;
        front = front->next;
        free(ptr);
    }else{
        prev->next= ptr->next;
        free(ptr);
    }
    
}
void display() {
    if(isEmpty()){
        printf("Queue is Empty!");
    }else if(front == rear){
        printf("Only One element in Queue: %d",front->data);
    }else {
        node *ptr = front;
        printf("Circular Queue:");
        while(ptr->next != front) {
            printf(" %d",ptr->data);
            ptr = ptr->next;
        }
        printf(" %d",ptr->data);
    }
}
int isEmpty() {
  if (front == NULL) 
    return 1;
  return 0;
}
int main()
{
    int ch,ele;
    while(1){
        printf("\n1.Insert_beg    2.Insert_end      3.Insert_before     4.Insert_after  5.Delete_beg    6.Delete_end    7.Delete_after      8.Delete_before     9.Display    0.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&ele);
                insertFirst(ele);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&ele);
                insertlast(ele);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d",&ele);
                insertBefore(ele);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d",&ele);
                insertAfter(ele);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deletelast();
                break;
            case 7:
                deleteAfter();
                break;
            case 8:
                deleteBefore();
                break;
            case 9:
                display();
                break;
            case 0:
                exit(0);
        }
    }
}