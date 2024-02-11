#include<stdio.h>
int main(){
    int currenttime,bt[10],at[10],tat=0,wt=0,sumbt=0,i,n,smallest;
    printf("enter the no of process\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("enter the arrival time for p%d\n",i+1);
    scanf("%d",&at[i]);
    printf("enter the burst time for p%d\n",i+1);
    scanf("%d",&bt[i]);
    sumbt+=bt[i];
}
bt[9]=9999;
for(currenttime=0;currenttime<sumbt;){
smallest=9;
for(i=0;i<n;i++){
    if(at[i]<=currenttime && bt[i]>0 && bt[i]<bt[smallest])
        smallest=i;
    }
    printf("\n p[%d] | %d\t|%d\t|",smallest+1,currenttime+bt[smallest]-at[smallest],currenttime-at[smallest]);
    tat+=currenttime+bt[smallest]-at[smallest];
    wt+=currenttime-at[smallest];
    currenttime+=bt[smallest];
    bt[smallest]=0;
    }
    printf("avg tat =%f",tat*1.0/n);
    printf("avg wt =%f",wt*1.0/n);
}

