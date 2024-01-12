#include<stdio.h>
#include<stdlib.h>
struct itemexpiry{
    int dd,mm,yy;
};
typedef struct{
    char *itemcode,*itemname;
    int itemprice;
    struct itemexpiry itemexpire;
}item;
item* create(int n){
       return((item*)malloc(n*sizeof(item)));
}
void read(item *mark,int n){
    int i;
    for(i=0;i<n;i++){
        mark[i].itemcode=(char *)malloc(20*sizeof(char));
        mark[i].itemname=(char *)malloc(20*sizeof(char));
    printf("Enter the item name,itemcode,itemprice,itemexpirydate with dd/mm/yy\n");
    scanf("%s%s%d%d%d%d",mark[i].itemname,mark[i].itemcode,&mark[i].itemprice,&mark[i].itemexpire.dd,&mark[i].itemexpire.mm,&mark[i].itemexpire.yy);
}
}
void display(item *mark,int n){
       int i;
       printf("Item Details are\n");
    for(i=0;i<n;i++){
        printf("Item name=%s (Item id=%s) \tItem price =%d \tItemExpiryDate=%d/%d/%d\n",mark[i].itemname,mark[i].itemcode,mark[i].itemprice,mark[i].itemexpire.dd,mark[i].itemexpire.mm,mark[i].itemexpire.yy);
}
}
void deallocate(item *mark,int n){
    int i;
    for(i=0;i<n;i++){
        free(mark[i].itemcode);
        free(mark[i].itemname);
    }
    free(mark);
}
int main(){ int n;
printf("enter the number of items");
scanf("%d",&n);
    item *mark=create(n);
    read(mark,n);
    display(mark,n);
    deallocate(mark,n);
}