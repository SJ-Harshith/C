#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main(){
    int n;
    void consumer();
    void producer();
    int wait(int);
    int signal(int);
    for(;;){
        printf("enter n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:if((mutex==1)&& empty!=0)
        producer();
        else
        printf("Buffer is full");
            break;
        case 2:if((mutex==1)&& full!=0)
            consumer();
            else
            printf("buffer is empty");
            break;
        case 3:exit(0);
        }

        }
    }
    int wait(int s){
        return(--s);
    }
    int signal(int s){
        return(++s);
    }
    void producer(){
        mutex=wait(mutex);
        empty=wait(empty);
        full=signal(full);
        x++;
        printf("producer produces the item %d",x);
        mutex=signal(mutex);
    }
    void consumer(){
        mutex=wait(mutex);
        full=wait(full);
        empty=signal(empty);
        printf("consumer consumes the item %d",x);
        x--;
        mutex=signal(mutex);
    }
