#include<stdio.h>
#include<stdlib.h>
#define S 5
typedef struct stack{
int a[S];
int top;
}stack;
void push(stack *s,int val){
if (s->top == S-1)
 printf("OVERFLOW!");
else{
   s->top++;
   s->a[s->top] = val;
}
}
void pop(stack *s){  
 if(s->top==-1){
      printf("UNDERFLOW!");
  }
 else{
  printf( "Popped Element: %d",s->a[s->top--]);
}
}
void display(stack *s){
 if(s->top==-1)
  {
      printf("UNDERFLOW!");
   
  }
 else{
   for (int i=s->top;i>=0;i--)
   printf("%d\n",s->a[i]);
 }
}
int isfull(stack *s){
 if( s->top==S-1)
       return 1;
   else
        return 0;
}
int isempty(stack *s){
 if( s->top==-1)
       return 1;
   else
       return 0 ;
}
int peek(stack *s){
    if(s->top==-1){
        printf("UNDERFLOW!");
        return -1;
    }
    else
        return s->a[s->top];
}
int size(stack *s){
    if(s->top==-1)
  {
      printf("UNDERFLOW!");
        return 0;
  }
 else
    return s->top+1;
}
int main()
{
 stack s1;
 s1.top=-1;
 int ele,n;
   while(1)
   {
       printf("\n1.Push 2.Pop 3.Display 4.Peek 5.Size 6.Exit\n");
       printf("\nEnter choice: ");
       scanf("%d",&n);
       switch(n)
       {
           case 1:
               printf("Enter Element: ");
               scanf("%2d",&ele);
               push(&s1,ele);
               break;
           case 2:
               pop(&s1);
               break;
           case 3:
               printf("Elements in the Stack are:\n");
               display(&s1);
               break;
           case 4:
               printf("\nTopmost Element: %d",peek(&s1));
               break;
           case 5:
               printf("\nSize of the Stack is %d",size(&s1));
               break;
           case 6:
               printf("Exit!");
               exit(0);
           default:
               printf("\nInvalid choice!");
               break;
       }
   }
 return 0;
 }
