#include<stdio.h>
#include<stdlib.h>
//structure of sll
typedef struct sll{
    int data;
    struct sll *next;
}node;
node *start=NULL;
node* createnode(){
    node *newnode=(node*)malloc(sizeof(node));
    printf("enter the data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
return newnode;
}
//insert begin
void insertbegin(){
    node *newnode=createnode();
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    newnode->next=start->next;
    start=newnode;
}
//insert end
void insertend(){
    node *newnode=createnode();
    node *temp=start;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
//deletebegin
void deletebegin(){
    node *temp=start;

     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    printf("deleted node is %d",&temp->data);
    start=temp->next;
    free(temp);
    }
    //deleteend
void deleteend(){
    node *temp=start;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    while((temp->next)->next!=NULL){
        temp=temp->next;
    }
     free(temp->next);
     temp->next=NULL;
}
//DISPLAY
void display(){
    node *temp=start;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
//search key
void searchkey(){
    node *temp=start;
    int key;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    printf("enter the key");
    scanf("%d",&key);
    if(temp!=NULL && temp->data!=key){    //check whether key is present if key not present it reaches null;
        temp=temp->next;
    }
    if(temp==NULL)
    printf("key not found");
    return;
    printf("key found");
}
//insert before key;
void insertbeforekey(){
    node *temp=start,*prevnode;
    node *newnode=createnode();
    int key;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    printf("enter the key");
    while(temp!=NULL && temp->data!=key){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("key not found");
        return;
    }
    newnode->next=prevnode->next;
    prevnode->next=newnode;
}
//insert afterkey
void insertafterkey(){
    node *temp=start;
    node *newnode=createnode();
    int key;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
printf("enter the key");
scanf("%d",&key);
while(temp!=NULL  && temp->data!=key){
    temp=temp->next;
}
newnode->next=temp->next;
temp->next=newnode;
}
//delete key
void deletekey(){
    node *temp=start,*prev;
    int key;
    printf("enter the key");
    scanf("%d",&key);
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    while(temp!=NULL  && temp->data!=key){
        prev=temp;
    temp=temp->next;
}
if(temp==NULL){
    printf("key not found");
    return;
}
     if(temp==start){
        deletebegin();
        return;
     }
     prev->next=temp->next;
     free(temp);
}
//reverse
void reverse(){
    node *temp=start,*prev=NULL;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    while(start!=NULL){
        temp=start;
        start=temp->next;
        temp->next=prev;
        prev=temp;
    }
}
//concate 2 sll
node* concatesll(node *start1,node *start2){
    node *temp=start1;
     if(start1==NULL)
    {
        printf("list is empty concate not possible");
        return;
    }
     if(start2==NULL)
    {
        printf("list is empty concate not possible ");
        return;
    }
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->next=start2;
       return start1;
}
//sort
void sort(){
    int i,j,n,tempd=0;
node *temp=start;
     if(start==NULL)
    {
        printf("list is empty");
        return;
    }
while(temp!=NULL){
    n++;
    temp=temp->next;
}
for(i=0;i<n;i++){
    temp=start;
    {
        for(j=0;j<n-i-1;j++){
            if(temp->data>(temp->next)->data){
            tempd=temp->data;
            temp->data=(temp->next)->data;
            temp->data=tempd;
        }
        temp=temp->data;
    }
}
}
display();
}