#include<stdio.h>
#include<stdlib.h>
#define size 4
int stack[size],top=-1;
void push(int ele){
	if(top==size-1){
		printf("Stack overflow\n");
	}
	else
	stack[++top]=ele;
}
int pop(){
	if(top==-1){
		printf("Stack underflow\n");
		return -1;
	}
	else
	return (stack[top--]);
}
void display(){
	int i;
	if(top==-1)
	printf("Stack is empty\n");
	else{
	for(i=top;i>=0;i--)
	printf(" %d \t",stack[i]);
}
}
void palindrome(){
int i,flag=1;
display();
for(i=0;i<=top/2;i++){
if(stack[i]!=stack[top-i])
flag=0;
}
if(flag==0)
printf("It is not a palindrome\n");
else
printf("It is a palindrome \n");
}
int main(){
	int ele,choice;
	while(1){
		printf("Enter 1 for push \n 2 for pop\n 3 for display \n4 for palindrome \n5 for exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the ele\n");
			       scanf("%d",&ele);
			       push(ele);
			       break;
			case 2:printf("Poped element is %d\n",stack[top]);
			       pop();
			    break;
			case 3:display();
			       break;
			case 4:palindrome();
			        break;
			case 5:exit(0);
			default:printf("Invalid ");
		return 0;	
			     
		}
	}
}
