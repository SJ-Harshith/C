#include<stdio.h>
#include<stdlib.h>
int count=0;//count the nodes
//structure 
typedef struct dll{
    char name[50];
    char ssn[50];
    char department[50];
    char designation[50];
    int salary;
    int phoneno;
    struct dll *next;
    struct dll *prev;
}node;
node *start=NULL;
//create
node* createnode(){
    node *newnode=(node*)malloc(sizeof(node));
    printf("ENTER THE NAME ,SSN ,DEPT ,DESIGNATION ,SALARY ,PHONENO\n");
    scanf("%s %s %s %s %d %d",newnode->name,newnode->ssn,newnode->department,newnode->designation,&newnode->salary,&newnode->phoneno);
   newnode->prev=NULL;
   newnode->next=NULL;
   return newnode;//return 
}
//INSERTBEGIN
void insertbegin(){
    node *newnode=createnode();
    if(start==NULL){
        start=newnode;
        count++;
        return;
    }
    newnode->next=start;
    start->prev=newnode;
    start=newnode;
    count++;
}
//INSERTEND
void insertend(){
    node *temp=start;
    node *newnode=createnode();
    if(start==NULL){
        start=newnode;
        count++;
        return;
    }
     while(temp->next!=NULL){
        temp=temp->next;
     }
     temp->next=newnode;
     newnode->prev=temp;
     count++;
}
//deletebegin
void deletebegin(){
    node *temp=start;
    if(start==NULL){
        printf("list is empty,nothing to delete\n");
        return;
    }
    if(start->next==NULL){
        printf("THE deleted name is %s\n",temp->name);
        free(temp);
        start=NULL;
        count--;
        return;
    }
    start=temp->next;
    start->prev=NULL;
    printf("The deleted name is %s\n",temp->name);
    free(temp);
    count--;
}
//deletend
void deleteend(){
     node *temp=start;
     if(start==NULL){
        printf("list is empty,nothing to delte\n");
        return;
     }
     while((temp->next)->next!=NULL){
        temp=temp->next;
     }
     printf("the delted name is %s\n",(temp->next)->name);
     free(temp->next);
     temp->next=NULL;
     count--;
}
//display
void display(){
    node *temp=start;
    if(start==  NULL){
        printf("the list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("NAME: %s ,SSN: %s ,DEPATMENT: %s ,DESIGNATION: %s ,SALARY: %d ,PHONENO: %d\n",temp->name,temp->ssn,temp->department,temp->designation,temp->salary,temp->phoneno);
        temp=temp->next;
    }
    printf("THE no of nodes =%d\n",count);
}
int main(){
    int choice ,i,n;
    for(;;){
        printf("enter 1 for insertbegin \n 2 for insertend\n 3 for deletebegin \n4 for deleteend \n5 for display\n 6 for exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("enter no of employee\n");
               scanf("%d",&n);
               for(i=0;i<n;i++){
                insertbegin();
               }
            break;
        case 2:printf("enter no of employee\n");
               scanf("%d",&n);
               for(i=0;i<n;i++){
                insertend();
               }
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