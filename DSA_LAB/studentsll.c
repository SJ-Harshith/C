#include <stdio.h>
#include <stdlib.h>
typedef struct student {
    char USN[10];
    char name[20];
    char programme[10];
    int sem;
    char phno[10];
    struct student *next;
}node;
//create structure for students
node *start=NULL;
node* createnode(){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the USN, name, programme, sem and phno of the student\n");
    scanf("%s%s%s%d%s", newnode->USN, newnode->name, newnode->programme, &newnode->sem, newnode->phno);
    newnode->next=NULL;
    return newnode;
}
//insert begin
void insertbegin(){
    node *newnode=createnode();
    if(start==NULL){
        start=newnode;
        return;
    }
    newnode->next=start;
    start=newnode;
}
//insert end
void insertend(){
    node *newnode=createnode();
    node *temp=start;
    if(start==NULL){
        start=newnode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
//delete begin
void deletebegin(){
    node *temp=start;
    if(start==NULL){
        printf("invalid\n");
        return;
    }
    start=temp->next;
    printf("deleted node is %s\n",temp->USN);
    free(temp);
}
//dlete end
void deleteend(){
 node *temp=start;
if(start==NULL){
    printf("invalid\n");
    return;
}
else if(start->next==NULL){
    printf("deleted node is %s\n",temp->USN);
    return;
}
while(temp->next->next!=NULL){
    temp=temp->next;
}
printf("deleted node is %s\n",temp->USN);
free(temp->next);
temp->next=NULL;
}
void display(){
    node *temp=start;
    if(start==NULL){
        printf("invalid\n");
        return;
    }
     while(temp!=NULL){
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, Phno: %s\n", temp->USN, temp->name, temp->programme, temp->sem, temp->phno);
        temp = temp->next;
     }
}
int main(){
    int choice ,i,n;
    for(;;){
        printf("enter 1 for insertbegin \n 2 for insertend\n 3 for deletebegin \n4 for deleteend \n5 for display\n 6 for exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("enter no of students\n");
               scanf("%d",&n);
               for(i=0;i<n;i++){
                insertbegin();
               }
            break;
        case 2:insertend();
              break;
        case 3:deletebegin();
                break;
        case 4:deleteend();
               break;
        case 5:display();
               break;
        case 6:exit(0);
        default:printf("invalid choice\n");
        }
    }
}
