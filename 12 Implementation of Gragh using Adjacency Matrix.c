#include<stdio.h>
#include<stdlib.h>
#define S 50

typedef struct{
    int b[S];
    int tos;
}Stack;

void push(Stack *s, int e){
    s->tos++;
    s->b[s->tos]=e;
}

int pop(Stack *s){
    int x=s->b[s->tos];
    s->tos--;
    return x;
}

typedef struct{
    int a[S];
    int front, rear;
}Queue;

void enqueue(Queue *q, int e){
    q->rear++;
    q->a[q->rear]=e;
    if(q->front==-1)
        q->front=0;
}

int dequeue(Queue *q){
    int x=q->a[q->front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front++;
    return x;
}

int isEmpty(int front){
    if(front==-1)
        return 1;
    else
        return 0;
}

typedef struct{
    int adj[S][S];
    int e,v;
}Graph;

void intializeGraph(Graph *g){
    for(int i=0;i<g->v;i++){
        for(int j=0;j<g->v;j++){
            g->adj[i][j]=0;
        }
    }
}

void add(Graph *g, int src, int dest){
    g->adj[src][dest]=1;
}

//DFS traversal using recursion method
void dfsTraversal(int root, Graph g){
    int visitedArray[g.v];
    for(int i=0;i<g.v;i++)
        visitedArray[i]=0;
    dfsRecursion(root,visitedArray,g); //Recursion method
}

void dfsRecursion(int root, int visitedArray[], Graph g){
    visitedArray[root]=1;
    printf("%d ",root);
    for(int j=0;j<g.v;j++)    {
        if(g.adj[root][j]==1 && visitedArray[j]!=1)        {
        dfsRecursion(j,visitedArray,g);
        }
    }
}

//DFS traversal using iterative method
void dfsIterative(Stack *s, int root, Graph g){
    int visitedArray[g.v];
    for(int i=0;i<g.v;i++)
        visitedArray[i]=0;
    push(s,root);
    while(!isEmpty(s->tos)){
        int x=pop(s);
        if(visitedArray[x]!=1){
            printf("%d ",x);
            visitedArray[x]=1;
            for(int j=0;j<g.v;j++){
                if(g.adj[x][j]==1 && visitedArray[j]!=1){
                    push(s,j);
                }
            }
        }
    }
}

//BFS traversal using iterative method
void bfsTraversal(Queue *q, int root, Graph g){
    int visitedArray[g.v];
    for(int i=0;i<g.v;i++)
        visitedArray[i]=0;
    enqueue(q,root);
    visitedArray[root]=1;
    while(!isEmpty(q->front)){
        int x=dequeue(q);
        printf("%d ",x);
        for(int j=0;j<g.v;j++){
            if(g.adj[x][j]==1 && visitedArray[j]!=1){
                enqueue(q,j);
                visitedArray[j]=1;
            }
        }
    }
}

void printadjmatrix(Graph g){
    for(int i=0;i<g.v;i++){
        for(int j=0;j<g.v;j++){
            printf("%d ",g.adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Graph g;
    Queue q;
    Stack s;
    s.tos=-1;
    int c;
    q.front=q.rear=-1;
    int root,src,dest;
    printf("Enter the no. of vertices for directed graph : ");
    scanf("%d",&g.v);
    printf("\nEnter the no. of edges for directed graph : ");
    scanf("%d",&g.e);
    intializeGraph(&g);
    //Entering the source node & destination node
    for(int i=1;i<=g.e;i++){
        printf("\nEnter the source node value : ");
        scanf("%d",&src);
        printf("\nEnter the destination node value : ");
        scanf("%d",&dest);
        add(&g,src,dest); //Adding elements into the graph
    }
    printf("\n***** Adjacency Matrix ******\n");
    printadjmatrix(g);
    do{
        printf("\nChoose your operation: 1.DFS Recursive 2.DFS Iterative 3.BFS Traversal 4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 1: printf("\nEnter the root : ");
                    scanf("%d",&root);
                    printf("\n***** DFS Recursive *****\n");
                    dfsTraversal(root,g);
                    printf("\n");
                    break;
            case 2: printf("\nEnter the root : ");
                    scanf("%d",&root);
                    printf("\n***** DFS Iterative *****\n");
                    dfsIterative(&s,root,g);
                    printf("\n");
                    break;
            case 3: printf("\nEnter the root : ");
                    scanf("%d",&root);
                    printf("\n***** BFS Traversal *****\n");
                    bfsTraversal(&q,root,g);
                    printf("\n");
                    break;
            case 4: exit(0);
        }
    }while(1);
    return 0;
}