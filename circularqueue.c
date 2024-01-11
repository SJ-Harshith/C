#include<stdio.h>
#include<stdlib.h>
#define max 4
char queue[20];
int rear=-1,front=0,count;         //positions
void enqueue(char ele){
    if(count==max){
        printf("Queue over flow\n");
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=ele;
        count++;
    }
}
void dequeue(){
    if(count==0){
        printf("Queue underflow \n ");
    }
    else{
        front=(front+1)%max;
        count--;
    }
}
void display(){
    int i,temp;
    temp=front;                //use temp for go to next while front will remain at its index;
    if(count==0)
    printf("Queue is empty\n");
    else{
    for(i=0;i<count;i++){         // why not i<=count because count start from 1
        printf("%c",queue[temp]);
        temp=(temp+1)%max;
    }
    printf("\n");
}}
int main(){
    int choice;
    char ele;
    while(1){
        printf("Enter the choice 1for enqueue 2 for dequeue 3 for display 4 for exit\n");
        scanf("%d",&choice);
        switch(choice){
          case 1:printf("Enter the ele \n ");
                  scanf(" %c",&ele);      //Added space before %c to skip leading whitespace
                  enqueue(ele);
                  break;
        case 2:dequeue();
                break;
        case 3:display();
               break;
        case 4:exit(0);
        default:printf("Invalid \n");
        }
    }
    return 0;
}