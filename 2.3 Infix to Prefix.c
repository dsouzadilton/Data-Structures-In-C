#include<stdio.h>
#include<string.h>
#include<conio.h>
#define S 10 

typedef struct stack{
    int top;
    int a[S];
}stack;

void push (stack *s, int x){
    s->a[++s->top] = x;
}

int pop (stack *s){
    int x;
    x = s->a[s->top--];
    return x;
}

int isempty (stack *s){
    if (s->top == -1)
        return (1);
    return (0);
}

int isoperand (char ch){
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int precedence (char x){
    if (x == '(')
        return (0);
    if (x == '+' || x == '-')
        return (1);
    if (x == '*' || x == '/' || x == '%')
        return (2);
    return (3);
}

void infix_to_prefix (char infix[], char prefix[]){
    stack s;
    s.top = -1;
    char x, ele;
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++){
        ele = infix[i];
        if (isoperand (ele))
            prefix[j++] = ele;
        else if (ele == '(')
            push (&s, '(');
        else if (ele == ')')
            while ((x = pop (&s)) != '(')
            prefix[j++] = x;
        else{
            while (precedence (ele) <= precedence (peek (&s)) && !isempty (&s)){
                x = pop (&s);
                prefix[j++] = x;
            }
        push (&s, ele);
        }
    }
    while (!isempty (&s)){
        x = pop (&s);
        prefix[j++] = x;
    }
    prefix[j] = '\0';
    }
    
int peek (stack *s){
    return (s->a[s->top]);
}

int main (){
    char infix[20], prefix[20], input[20],temp;
    printf (" Enter an infix expression: ");
    gets (input);
    int i=0,j=strlen(input)-1;
    for(i=0;i!='\0';i++){
        temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
    infix_to_prefix (input, prefix);
    i=0,j=strlen(prefix)-1;
    while(i<j){
        temp=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=temp;
        i++;
        j--;
    }    
    puts (prefix);
    return 0;
}