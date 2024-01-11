#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
float stack[100];
int top=-1;
void push(float ele){
    stack[++top]=ele;
}
float pop(){
    return (stack[top--]);
}
void evaluate(char *postfix){
    char sym;
    int i;
    float result,op1,op2;
    for(i=0;i<strlen(postfix);i++){
        sym=postfix[i];
        if(isdigit(sym))
        push(sym-'0');
        else{
            op2=pop();
            op1=pop();
            switch(sym){
                case '+':push(op1+op2);
                       break;
                case '-':push(op1-op2);
                         break;
                case '*':push(op1*op2);
                       break;
                case '/':push(op1/op2);
                       break;
                case '%':push((int)op1%(int)op2);
                       break;
                case '^':push(pow(op1,op2));
                       break;
                default:printf("Invalid");                      
            }
        }
    }
    result=pop();
    printf("The result is %f",result);
    }
    int main(){
        char postfix[200];
        printf("Enter the postfix expression \n");
        gets(postfix);
        evaluate(postfix);
        return 0;
    }