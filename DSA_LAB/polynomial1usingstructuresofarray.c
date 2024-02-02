#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//structure
typedef struct polynomial{
    int coeff,expo;  
}poly;
//read
void readpoly(poly p[],int n){     //n is no of terms 
    int i;
    for(i=0;i<n;i++){
        printf("enter the coeff and exponent");
        scanf("%d%d",&p[i].coeff,&p[i].expo);
    }
}
void printpoly(poly p[],int n){
    int i;
    for(i=0;i<n-1;i++){
        printf("%dx^%d+",p[i].coeff,p[i].expo);//prints till lastsecond term along +
    }
    printf("%dx^%d",p[i].coeff,p[i].expo);//print last term
}
int addpolynomial(poly p1[],poly p2[],poly p3[],int n1,int n2){//return type is int we need number of terms to print p3 and evaluate
         int i=0,j=0,k=0;
         while(i<n1 && j<n2){//till end of poly1 and poly 2 terms
            if(p1[i].expo>p2[j].expo){
                p3[k]=p1[i];//copy that  term from p1 to p3
                i++;
                k++;
            }
            else if(p2[j].expo>p1[i].expo){
                p3[k]=p2[j];//copy from p2 to p3
                k++;
                j++;
            }
            else    //when p[i].expo==p[j].expo  add coeff of p1 and p2 and put in p3
            {
                p3[k].coeff=p1[i].coeff+p2[j].coeff;
                p3[k].expo=p1[i].expo;//or p2[j].expo
                k++;
                j++;
                i++;
            }
         }                //loop ends here
            //when remaining terms from p1 if there are left out 
            while(i<n1){
                p3[k]=p1[i];//whatever left out in p1 copy to p3
                k++;
                i++;
            }
            //simiar for p2 also
            while(j<n2){
                p3[k]=p2[j];
                k++;
                j++;
            }
         
         return k;
}
//evaluate at last
void evaluate(poly p[],int n){int i;
    int sum=0,x;//read  x,let sum value intialize with zero such that no error comes during  sum add
    printf("Enter the value of x\n");
    scanf("%d",&x);
    for(i=0;i<n;i++){
    sum=sum+(p[i].coeff*pow(x,p[i].expo));
}
printf("evaluated result :%d",sum);//result 
}
int main(){
    int n1,n2,n3;//no of terms in p1 p2 p3
    poly p1[100],p2[100],p3[200];//declare 
    printf("Enter the no of terms in polynomial1 and polynomial 2\n");
    scanf("%d%d",&n1,&n2);
    printf("enter polynomial 1\n");
    readpoly(p1,n1);
    printf("enter the polynomial 2\n");
    readpoly(p2,n2);
    n3=addpolynomial(p1,p2,p3,n1,n2);//add poly and store number  of terms of p3 in n3
    printf("polynomial 1 is\n");
    printpoly(p1,n1);
    printf("polynomial 2 is\n");
    printpoly(p2,n2);
    printf("polynomial 3 is\n");
    printpoly(p3,n3);
    evaluate(p3,n3);
    return 0;
}