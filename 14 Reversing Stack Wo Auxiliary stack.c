#include<stdio.h> 
#include<stdlib.h> 
#include<stdlib.h>

typedef struct stack{ 
	int data; 
	struct stack *next; 
}stack;

stack *top = NULL;

stack * getnode(){
	stack *link = (stack*)malloc(sizeof(stack));
    return link;
}

void push(int data) {
    stack *link = getnode();
    link->data = data;
    if(isEmpty())
        link->next = NULL;
    else
        link->next = top;
    top =link;
}

int pop(){ 
    if(!isEmpty()){
		int res = top->data; 
		top = top->next;
		return res;
    }
    else
        return -1;
} 

void print(){
    if(!isEmpty()){
        stack *ptr = top;
        while(ptr != NULL) {
            printf("\n\t| %2d|",ptr->data);
            ptr = ptr->next;
        }
    }else
        printf(" Empty!");
}

int isEmpty() { 
    if(top == NULL)
        return 1;
    else
        return 0; 
}    

//function that reverses the given stack using insertAtBottom() 
void reverse(){ 
	if(isEmpty()!=1){ 
		// Hold all items in Function Call Stack until we reach end of the stack 
		int temp = pop();
		printf("\n Inside Reverse function, popped: %d",temp);
		reverse(); 
    	// Insert all the items (held in Function Call Stack) one by one at the bottom of the stack 
		printf("\n Calling insert at bottom inside reverse, inserting: %d",temp);
		insertAtBottom(temp);
	} 
} 

// Below is the recursive function that inserts an element at the bottom of a stack. 
void insertAtBottom(int item){ 
	if(isEmpty()){
	    printf("\n Empty stack, pushing %d",item);
		push(item); 
	}else{
		// Hold all items in the Function Call Stack until we reach end of the stack.
		// When the stack becomes empty, the above if part is executed and the item is inserted at the bottom.
		int temp = pop(); 
		printf("\n Stack not empty, popping top element: %d",temp);
		insertAtBottom(item); 
		// Once the item is inserted at the bottom, push all the items held in the Function Call Stack.
		push(temp); 
		printf("\n Pushing %d",temp);
	} 
} 
 
int main(){ 
    printf("\n Application of Stack Data Structure: \nThe Stack data structure is employed by various software program systems like Operating systems, virtual machines, etc. for various different uses like, to keep track of of the execution of instructions, sub-routines, memory management etc. \nOne of the  applications of stack data structure is the Call Stack which is used to keep track of the function calls; which function which is currently being run; what other functions are called from within that function, etc.\n Without the call stack keeping track of the function calls and memory management would be difficult and employment of recursive functions would be impossible"); 
	printf("\n This program demonstrates reversing of the elements of a stack using recursion\ni.e. reversing with the help of call stack and w/o using an auxiliary stack\n");
	for(int i=1;i<=10;i++)
        push(i);
	printf("\n Original Stack: "); 
	print(); 
	reverse(); 
	printf("\n Reversed Stack: "); 
	print(); 
	return 0; 
} 