#include <stdio.h>
#include <stdlib.h> 
#define MAX 100 
typedef struct node {
    int row;
    int col;
    int data; 
    struct node *next; 
}node;

node *head = NULL;

void traverse() { 
   node *temp; 
   temp = head; 
   printf("Representation: \n");
   while(temp != NULL) { 
      printf("%d %d %d", temp->row, temp->col, temp->data);
      printf("\n");
      temp = temp->next; 
   } 
}

node* getnode(int row, int col, int val) {
    node *newnode = (node*)malloc(sizeof(node*));  
    newnode->data = val; 
    newnode->row = row;
    newnode->col = col;
    newnode->next = NULL;
}

void add_ele(int row, int col, int x) { 
    node *newnode;
    newnode = getnode(row, col, x);
    node *temp; 
    temp = head; 
    if(head == NULL) { 
       head = newnode; 
       return; 
    } 
    while(temp->next != NULL) 
       temp = temp->next; 
    temp->next = newnode; 
}

void matrix() {
    int row, col;
    printf("\nEnter the no. of rows and columns : ");
    scanf("%d %d", &row, &col);
    printf("\nEnter elements : \n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int val;
            scanf("%d", &val);
            if(val != 0) {
                add_ele(i, j, val);
            }
        }
    }
}

int main()
{
    matrix();
    printf("\n");
    traverse();
    return 0;
}