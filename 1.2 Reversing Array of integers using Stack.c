#include <stdio.h>
int stk[10],top=-1;
void push(int val){
    stk[++top] = val;
}

int pop(){
    return(stk[top--]);
}

int main(){
     int val, n, i, arr[10];
     printf("\n Enter the number of elements in the Array : ");
     scanf("%d", &n);
     printf("\n Enter the elements of the Array : ");
     for(i=0;i<n;i++){
       scanf("%d", &arr[i]);
       push(arr[i]); 
     }
     printf("\n The reversed array is : ");
     for(i=0;i<n;i++){
       arr[i] = pop();
       printf("\n%d", arr[i]);
     }
     return 0;
}

