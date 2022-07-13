#include<stdio.h> 
#include<conio.h> 
#define S 30 

typedef struct stack {
    int arr[S];
    int top;
}stack;

void push (stack *s, int val){
    s->arr[++s->top] = val;
} 

int pop (struct stack *s){
    return s->arr[s->top--];
}

int isempty (struct stack *s){
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int peek (struct stack *s){
    return (s->arr[s->top]);
}

int isoperand (char ch){
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int precedence (char c){
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 2;
}

void infixTopostfix (char infix[], char postfix[]) {
    stack s1;
    s1.top = -1;
    char a, val;
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++){
        val = infix[i];
        if (isoperand (val))
            postfix[j++] = val;
        else if (val == '(')
            push (&s1, '(');
        else if (val == ')'){
            while ((a = pop (&s1)) != '(')
            postfix[j++] = a;
        }
        else{
            while (precedence (val) <= precedence (peek (&s1)) && !isempty (&s1)){
                a = pop (&s1);
                postfix[j] = a;
                j++;
            }
            push (&s1, val);
        }
    }
    while (!isempty (&s1)){
        a = pop (&s1);
        postfix[j++] = a;
    }
    postfix[j] = '\0';
}

int main (){
    char infix[30], postfix[30];
    printf (" Enter Infix expression: ");
    gets (infix);
    infixTopostfix (infix, postfix);
    printf (" Postfix expression: ");
    puts (postfix);
    return 0;
}

