#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int date;
    char *day,*activity;
}cal;
cal* create(){
    return ((cal *)malloc(7*sizeof(cal)));
}
void read(cal *d){
    int i,flag;
    char temp[20];
    for(i=0;i<7;i++){
        d[i].date=-1;
        d[i].day=d[i].activity=NULL;
    }
    do{
    printf("Enter the date \n");
    scanf("%d",&i);
    if(i<0 || i>6){
        printf("Invalid\t Enter date between 1 and 6 \n");
    }
    d[i].date=i;
    printf("Enter the day name \n");
    scanf("%s",temp);
    d[i].day=strdup(temp);
    printf("Enter the activity\n");
    scanf("%s",temp);
    d[i].activity=strdup(temp);
    printf("Enter 1 for continue or other for stop \n");
    scanf("%d",&flag);
    
    }while(flag==1);}

    void display(cal *d){int i;
     printf("DATE\tDAYNAME\tACTIVITY\n");
        for(i=0;i<7;i++){
            if(d[i].date!=-1)
            printf("%d\t%s\t%s\t\n",d[i].date,d[i].day,d[i].activity);
        }
    }
    void deallocate(cal *d){int i;
        for(i=0;i<7;i++){
            free(d[i].activity);
            free(d[i].day);
        }
        free(d);
    }
    int main(){
        cal *d=create();
        read(d);
        display(d);
        deallocate(d);
        return 0;

    }


