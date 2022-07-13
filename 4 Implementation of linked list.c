#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node* getnode(){
	node *link = (node*)malloc(sizeof(node));
    return link;
}
void insertFirst(int data) {
     node *link = getnode();
     link->data = data;
    if(head == NULL){
        link->next = NULL;
        head = link;
    }
    else{
        link->next = head;
        head = link;
    }
}

void insertlast(int data){
    node *link = getnode();
     link->data = data;
     link->next = NULL;
     if(head == NULL){
        head = link;
    }
    else{
    node *ptr = head;
    node *prev = NULL;
    while(ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
   }
   prev->next = link;
  }
}

void insertAfter(int data){
    node *link = getnode();
     link->data = data;
    int ele;
    printf("Enter the value after which node to be inserted: ");
    scanf("%d",&ele);
    node *ptr = head;
    while(ptr->data != ele){
        ptr=ptr->next;
    }
    node *temp=ptr->next;
    ptr->next=link;
    link->next=temp;
}

void insertBefore(int data){
    node *link = getnode();
     link->data = data;
    int ele;
    printf("Enter the value before which node to be inserted: ");
    scanf("%d",&ele);
    node *ptr = head;
    node *prev = NULL;
    while(ptr->data != ele){
        prev = ptr;
        ptr=ptr->next;
    }
    prev->next=link;
    link->next=ptr;
}

void deleteFirst() {
   printf("Deleted Node: %d",head->data);
    free(head);
    head = head->next;
}

void deletelast(){
   node *ptr = head;
   node* prev = NULL;
   while(ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
   }
   prev->next = NULL;
   printf("Deleted Node: %d",ptr->data);
    free(ptr);

}

void deleteParticular(){
     int ele;
    printf("Enter the value of the node to be deleted: ");
    scanf("%d",&ele);
    node *ptr = head;
    node *prev = NULL;
    while(ptr->data != ele){
        prev = ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    free(ptr);
    printf("Deleted Node Successfully\n");
    printList();
}
void printList() {
   node *ptr = head;
   printf("Linked List:");
   while(ptr != NULL) {
      printf(" %d",ptr->data);
      ptr = ptr->next;
   }
}
void count(){
    node *ptr = head;
    int count = 0;
    while(ptr != NULL) {
        ptr=ptr->next;
        count ++;    
    }
    printf("Total Number of Nodes:%d",count);
}
void reverse(node** head_ref) {
   node* prev = NULL;
   node* current = *head_ref;
   node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
   *head_ref = prev;
   printList();
}
int main()
{
    int ch,ele;
    while(1){
        printf("\n1.Insert_beg    2.Insert_end      3.Insert_before     4.Insert_after  5.Delete_beg    6.Delete_end    7.Delete_particular  8.Display    9.Reverse      10.Count   0.Exit\n");
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
                deleteParticular();
                break;
            case 8:
                printList();
                break;
            case 9:
                reverse(&head);
                break;
            case 10:
                count();
                break;
            case 0:
                exit(0);
        }
    }
}
