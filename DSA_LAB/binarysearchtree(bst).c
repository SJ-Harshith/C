#include<stdio.h>
#include<stdlib.h>
//structure 
typedef struct bst{
    int key;
    struct bst *left,*right;
}node;
//insert
node* insert(node *root,int key){
    node *newnode;
    if(root==NULL){
        newnode=(node*)malloc(sizeof(node));
        newnode->key=key;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    else if(key>root->key){
        root->right=insert(root->right,key);
    }
    else if(key<root->key){
        root->left=insert(root->left,key);
    }
    return root;
}
//inoreder
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
//void preorder
void preorder(node *root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
//void postorder
void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}
//search
void search(node *root,int key){
    if(root==NULL){
        printf("key not found");
        return ;
    }
    else if(key==root->key){
        printf("key found");
        return;
    }
    else if(key<root->key)
        search(root->left,key);
    else
    search(root->right,key);
}
int main(){
    int i,n,choice,key;
    printf("enter no of nodes to insert\n");
    scanf("%d",&n);
    node *root=NULL;
    for(i=0;i<n;i++){
        printf("enter the key\n");
        scanf("%d",&key);
        root=insert(root,key);
    }
    for(;;){
        printf("enter 1 for preorder\n 2 for post order \n 3 for inorder\n 4 for search \n 5 for exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("preorder = ");
              preorder(root);
            break;
        case 2:printf("post order = ");
               postorder(root);
               break;
        case 3:printf("inorder = ");
            inorder(root);
             break;
        case 4:printf("enter the key to be searched =");
              scanf("%d",&key);
              search(root,key);
              break;
        case 5:exit(0);
        
        default:printf("invalid option \n");
                break;
        }
    }
}