#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//polynomial using 3 variable
typedef struct polynomial{
    int coeff,xexpo,yexpo,zexpo,flag;
    struct polynomial *next;//self referential structure to keep tract of next node
}node;
void insertend(node *head,int c,int x,int y,int z){//we got coeff ,x,y,zexpo for each time each term 
//each time createing new node and asssigning x,y,z expo
node *newnode=(node*)malloc(sizeof(node));
newnode->coeff=c;
newnode->xexpo=x;
newnode->yexpo=y;
newnode->zexpo=z;
newnode->flag=0;
newnode->next=NULL;
//inserted for single term
//create circular for newnode using insertend
node *temp=head;//                                   in main function head->next points to head so temp points to head only if no nodes are inserted
while(temp->next!=head){
    temp=temp->next;//go to last node
}
temp->next=newnode;//insert at last //then go to first like circular
newnode->next=head;
}
//read the term of polynomial p
void read(node *head){   //in main function we are only passing head that keep track of that polynomial
//in this we need to read expo of x ,y,z and coeff of  that for n terms 
//after reading pass it to insertend function to create a linked list of those terms
    int n,coef,x_expo,y_expo,z_expo;
    printf("enter the no of terms\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the coeff,X_expo,Y_expo,z_expo\n");
        scanf("%d%d%d%d",&coef,&x_expo,&y_expo,&z_expo);
        insertend(head,coef,x_expo,y_expo,z_expo);
    }
}
//display
void display(node *head){
    node *temp=head->next;
    while(temp->next!=head){
        printf("%dx^%dy^%dz^%d +",temp->coeff,temp->xexpo,temp->yexpo,temp->zexpo);//prints till last 2nd
        temp=temp->next;//go to last
    }
    printf("%dx^%dy^%dz^%d\n",temp->coeff,temp->xexpo,temp->yexpo,temp->zexpo);//prints last
}
//evaluate
void evaluate(node* head) {
  node *temp = head->next;//from 1st term
  int sum= 0,x,y,z;
  printf("enter the value of x y and z\n");
  scanf("%d%d%d",&x,&y,&z);
  while(temp!=head){
    sum=sum+temp->coeff*pow(x,temp->xexpo)*pow(y,temp->yexpo)*pow(z,temp->zexpo);
    temp = temp->next;
  }
  printf("the result of a polynomial is %d\n", sum);
}
//add poly
void addpoly(node *head1,node *head2,node *head3){
    int c;
    node *temp=head1->next;
    node *temp1;
    while(temp!=head1){
        temp1=head2->next;
        {
            while(temp1!=head2){
                if(temp->xexpo==temp1->xexpo && temp->yexpo==temp1->yexpo && temp->zexpo==temp1->zexpo){
                    c=temp1->coeff+temp->coeff;
                    insertend(head3,c,temp->xexpo,temp->yexpo,temp->zexpo);
                    temp1->flag=1;
                    temp->flag=1;
                }
                temp1=temp1->next;
            }
            temp=temp->next;
        }
    }
    temp=head1->next;
    temp1=head2->next;
    while(temp!=head1){
        if(temp->flag==0){
            insertend(head3,temp->coeff,temp->xexpo,temp->yexpo,temp->zexpo);
        }
        temp=temp->next;
    }
    while(temp1!=head2){
         if(temp1->flag==0){
            insertend(head3,temp1->coeff,temp1->xexpo,temp1->yexpo,temp1->zexpo);
        }
        temp1=temp1->next;
    }
}

int main(){
    node *head1=(node*)malloc(sizeof(node));//create head to track poly 1
    head1->next=head1;//creating circular list
    node *head2=(node*)malloc(sizeof(node));//create head to track poly 2
    head2->next=head2;//creating circular list for poly2
    node *head3=(node*)malloc(sizeof(node));//create head for poly3 (sum)
    head3->next=head3;//creating circular list
    printf("read 1st polynomial\n");
    read(head1);
    printf("read 2nd polynomial\n");
    read(head2);
    display(head1);
    display(head2);
    addpoly(head1,head2,head3);
    display(head3);
    evaluate(head3);

}