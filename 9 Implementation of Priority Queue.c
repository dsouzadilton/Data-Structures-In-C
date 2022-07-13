#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int priority;
    struct node *next;
}node;
node *front = NULL;

node* getnode(){
	node *link = (node*)malloc(sizeof(node));
    return link;
}

void insert(int data, int priority){
    node *link = getnode();
    link->data=data;
    link->priority=priority;
    if(front == NULL || front->priority > priority){
        link->next=front;
        front=link;
    }else{
        node *ptr = front;
        node *prev =NULL;
        while(ptr!=NULL){
            if(ptr->priority == priority){
                link->next=ptr->next;
                ptr->next=link;
                break;
            }else if(ptr->next ==NULL && (priority > ptr->priority || priority==ptr->priority)){
                ptr->next = link;
                link->next=NULL;
                break;
            }else if(ptr->priority > priority){
                prev->next=link;
                link->next=ptr;
                break;
            }
            prev=ptr;
            ptr=ptr->next;
        }
    }
}

void delete() {
    node *ptr = front;
    if(ptr == NULL){
       printf("Empty!");
    }else{
    printf("Deleted Element: %d",ptr->data);
    front = front->next;
    free(ptr);
    }
}

void display() {
   node *ptr = front;
   if(ptr == NULL){
       printf("Empty!");
   }else{
   printf("Priority Queue:");
      while(ptr != NULL) {
      printf(" %d",ptr->data);
      ptr = ptr->next;
   }
   }
}

int main()
{
    int ch,ele,pr;
    while(1){
        printf("\n1.Insert  2.Delete    3.Display   0.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&ele);
                printf("Enter Priority: ");
                scanf("%d",&pr);
                insert(ele,pr);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
        }
    }
}