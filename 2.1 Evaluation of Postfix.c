#include<stdio.h>
#include<conio.h>
#define S 30 

typedef struct stack{ 
    int arr[S]; 
    int top; 
}stack; 

void push(stack *s,int val) { 
if(isfull(s)) 
    return; 
else 
    s->arr[++s->top] = val; 
} 

int pop(stack *s) { 
if(isempty(s)) 
    return -1; 
else 
    return s->arr[s->top--]; 
} 

int peek(stack *s) {
    return(s->arr[s->top]);
}
 
int isfull(stack *s) { 
if(s->top == S-1) 
    return 1; 
else 
    return 0;
}

int isempty(stack *s) { 
if(s->top == -1) 
    return 1; 
else 
    return 0; 
} 

int isoperand(char ch) { 
if(ch >= '0' && ch <= '9') 
    return 1; 
else 
    return 0; 
}

int main() {
    stack s1; 
    int ele,i,a,b,eval; 
    s1.top=-1; 
    char exp[50]; 
    printf("\n Enter the postfix expression: "); 
    gets(exp); 
    for( i=0; exp[i] != '\0'; i++) {
        if(isoperand(exp[i])) 
            push(&s1,exp[i]-'0'); 
        else {
            b = pop(&s1); 
            a=pop(&s1); 
            switch(exp[i]) { 
                case '+':
                    eval=a+b; 
                    push(&s1,eval); 
                    break; 
                case '-':
                    eval=a-b; 
                    push(&s1,eval); 
                    break; 
                case '*':
                    eval=a*b; 
                    push(&s1,eval); 
                    break; 
                case '/':
                 	eval=a/b; 
                    push(&s1,eval); 
                    break; 
                default:printf("Invalid Input\n"); 
            } 
        } 
    } 
    eval = pop(&s1); 
    printf("\n After Evaluation: %d\n",eval); 
    return 0; 
}
