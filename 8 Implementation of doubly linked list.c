#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node{
    int data;
    struct node *prev;
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
        link->prev=NULL;
        link->next = NULL;
        front = link;
        rear = link;
    }
    else {
        link->prev=NULL;
        link->next = front;
        front->prev=link;
        front = link;
    }
}

void insertlast(int data){
    node *link = getnode();
    link->data = data;
    link->next = NULL;
    if(isEmpty()) {
        link->prev=NULL;
        link->next = NULL;
        front = link;
        rear = link;
    }else   {
        rear->next = link;
        link->prev=rear;
        rear = link;
        rear->next=NULL;
    }
}

void insertAfter(int data){
    node *link = getnode();
    link->data = data;
    int ele;
    printf("Enter the value after which node to be inserted: ");
    scanf("%d",&ele);
    node *ptr = front;
    while(ptr->data != ele){
        ptr=ptr->next;
    }
    if(ptr==rear){
        rear->next=link;
        link->prev=rear;
        rear=link;
        link->next=NULL;
    }else{
        link->next=ptr->next;
        ptr->next->prev=link;
        ptr->next=link;
        link->prev=ptr;
    }
}

void insertBefore(int data){
    node *link = getnode();
    link->data = data;
    int ele;
    printf("Enter the value before which node to be inserted: ");
    scanf("%d",&ele);
    node *ptr = front;
    while(ptr->data != ele){
        ptr=ptr->next;
    }
    if(front->data==ele){
        link->prev=NULL;
        front->prev=link;
        link->next = front;
        front = link;
    }else {
        ptr->prev->next=link;
        link->prev=ptr->prev;
        link->next=ptr;
        ptr->prev=link;
    }
}

void deleteFirst() {
    if(isEmpty()){
        printf("List is Empty!");
    }else {
        front = front->next;
        front->prev=NULL;    }
}

void deletelast(){
    if(isEmpty()) {
        printf("LIst is Empty!");
    }else {
        rear = rear->prev;
        rear->next=NULL;
    }
}

void deleteBefore(){
    int ele;
    printf("Enter the value before which node to be deleted: ");
    scanf("%d",&ele);
    node *ptr = front;
    while(ptr->next->data != ele){
        ptr=ptr->next;
    }if(front->next->data == ele){
        front = front->next;
        front->prev=NULL;
    }else if(front->data == ele){
    }else{
        ptr->prev->next = ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
}

void deleteAfter(){
    int ele;
    printf("Enter the value after which node to be deleted: ");
    scanf("%d",&ele);
    node *ptr = front;
    while(ptr->data != ele){
        ptr=ptr->next;
    }
    ptr=ptr->next;
    if(ptr == rear){
        rear=ptr->prev;
        rear->next=NULL;
    }else if(rear->data==ele){
    }else{
        ptr->prev->next = ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
    
}
void display() {
    if(isEmpty()){
        printf("List is Empty!");
    }else {
        node *ptr = front;
        printf("Doubly Linked List:");
        while(ptr->next != NULL) {
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