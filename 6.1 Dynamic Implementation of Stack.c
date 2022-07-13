#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *top = NULL;

node* getnode(){
	node *link = (node*)malloc(sizeof(node));
    return link;
}
void Push(int data) {
     node *link = getnode();
     link->data = data;
    if(isEmpty()){
        link->next = NULL;
        top = link;
    }
    else{
        link->next = top;
        top = link;
    }
}
void Pop() {
    if(!isEmpty()){
    printf("Popped: %d",top->data);
    free(top);
    top = top->next;
    }
    else
        printf("Stack is Empty!");
}
int isEmpty(){
    if(top == NULL)
        return 1;
    else return 0;
}
void Peek(){
    if(!isEmpty()){
    printf("Element at top: %d",top->data);
    }
    else
        printf("Stack is Empty!");
}
void Display(){
 if(!isEmpty()){
     node *ptr = top;
   printf("Stack:");
   while(ptr != NULL) {
      printf(" %d",ptr->data);
      ptr = ptr->next;
   }
  }
    else
        printf("Stack is Empty!");
}
int main()
{
    int ch,ele;
    while(1){
        printf("\n1.Push    2.Pop      3.Peek     4.Display  0.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&ele);
                Push(ele);
                break;
            case 2:
                Pop();
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