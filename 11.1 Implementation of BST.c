#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *left,*right;
}node;

node *root;

node *getnode(int x){
    node *n = (node *)malloc(sizeof(node));
    n->info=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void insert(int x){
    node * newnode = getnode(x);
    node *p,*parent;
    p=root;
    parent=NULL;
    if(root==NULL){
        root=newnode;
    }else{
        while(p!=NULL)  {
            if(newnode->info < p->info){
                parent=p;
                p=p->left;
            }else{
                parent=p;
                p=p->right;
            }
        }
        if(newnode->info < parent->info)  {
            parent->left=newnode;
        }else{
            parent->right=newnode;
        }
    }
}

void search(int val){
    node *ptr,*parent;
    ptr=root;
    parent=NULL;
    int flag=0;
    if(root==NULL){
        printf("B.S.T. is EMPTY!");
        return;
    }else{
        while(ptr!=NULL){
            if(ptr->info==val){
                flag=1;
                break;
            }else{
                if(val<ptr->info){
                    parent = ptr;
                    ptr=ptr->left;
                }else{
                    parent=ptr;
                    ptr=ptr->right;
                }
            }
        }
        if(flag==1)
            printf("Node found ");
        else
        printf("Node not found ");
    }
}

void delete(int val){  
    node *ptr,*parent;
    ptr=root;
    parent=NULL;
    int flag=0;
    if(root==NULL){
        printf("B.S.T. is EMPTY!\n");
        return;
    }else{ 
        while(ptr!=NULL){  
            if (ptr->info==val){ 
                flag=1;
                break;
            }else{
                if(val<ptr->info){ 
                    parent= ptr;   
                    ptr=ptr->left;   
                }else{ 
                    parent=ptr;
                    ptr=ptr->right; 
                }
            }
        }
        if(flag==1){ 
            if(ptr->left==NULL && ptr->right==NULL){ 
                if(parent->right==ptr)
                    parent->right=NULL;
                else
                    parent->left=NULL;
                free(ptr);
            }else if(ptr->left!=NULL&& ptr->right==NULL){ 
                if(ptr==parent->left)
                    parent->left=ptr->left;
                else 
                    parent->right=ptr->left;
                free(ptr);
            }else if(ptr->left==NULL && ptr->right!=NULL){  
                if(ptr==parent->right)
                    parent->right=ptr->right;
                else
                    parent->left=ptr->right;
            }else{ 
                int n;
                node *r;
                r=ptr->left;
                while(r->right!=NULL)
                    r=r->right; 
                n=r->info; 
                delete(n);
                ptr->info=n;
            }
        }
    }
}
	
void preorder(node *root){
    if(root==NULL)
        return;
    printf("%d ",root->info);
    preorder(root->left);
    preorder(root->right);
}
	
void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->info);
    inorder(root->right);
}

void postorder(node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->info);
}

int main(){
    int val; 
    int ch;
    while(1){
        printf("\n 1.Insert\t2.Delete\t3.Search\t4.Preorder\t5.Inorder\t6.Postorder\t7.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf(" Enter the value for the Node to be Inserted : ");
                scanf("%d",&val);
                insert(val);
                break;
            case 2: 
                printf(" Enter the value of the node to be Deleted : ");
                scanf("%d",&val);
                delete(val);
                break;
            case 3:
                printf("\n Enter element to be searched: ");
                scanf("%d",&val);
                search(val);    
            case 4: 
                printf("\n Preorder traversal: ");
                preorder(root);
                break;
            case 5: 
                printf("\n Inorder traversal: ");
                inorder(root);
                break;
            case 6: 
                printf("\n Postorder traversal: ");
                postorder(root);
                break;
            case 7: 
                exit(0);
                break;
        } 
    }
    return 0;
}