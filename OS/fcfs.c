#include<stdlib.h>
#include<stdio.h>
int main(){
    int p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,n,temp=0;//n is no of process ,i and jfor loop
    float awt=0,atat=0;
    //read no of process
    printf("enter no of process\n");
    scanf("%d",&n);
    //read process id for n process 
    printf("enter pid of process in sorted arrival time order\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    //read arival time 
    printf("enter the arrival time in sorted order\n");
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    //read burst time
    printf("enter the burst time based on process\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    //completion time
    //intialize for 0th one
ct[0]=at[0]+bt[0];
 for (i = 1; i < n; i++) {
    if (ct[i - 1] < at[i]) {
        temp = at[i] - ct[i - 1];
    } else {
        temp = 0;
    }
    ct[i] = temp + ct[i - 1] + bt[i];
}
 //calculate tat and wt   tat=ct-at   wt=tat-bt
for(i=0;i<n;i++){
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
atat+=tat[i];
awt+=wt[i];
}
//display
 printf("In p \t AT \t BT \t CT \t TAT \t WT \t");
for(i=0;i<n;i++){
    printf("\n %d \t %d \t %d \t %d \t %d \t %d\t",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\n aveg wt=%f",(float)awt/n);
printf("\n avwg tat =%f",(float)atat/n);
}