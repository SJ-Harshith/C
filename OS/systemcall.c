#include<stdio.h>
#include<sys/types.h>//these for fork() and execlp() is used to run another program in our c program 
/* . When the pid value is zero, it means that this is the child process created by the fork() system call. The execlp() system call then replaces the current running process by the new child process, and the new program starts executing */
#include<unistd.h>//fork() creates a new process that is copy of current process with value of return type of pid_t
// wait() system call, which suspends the execution of the current process until one of its child processes terminates.
#include<stdlib.h>
//#include<sys/wait.h>
int main(){
    pid_t pid;//create a pid variable with type pid_t which storess process id
    pid=fork();//create a new process id
    if(pid<0){
        printf("fork failed");
        exit(0);
    }
    else if(pid==0){
        printf("child process created\n");
        execlp("ls","ls","-l",NULL);
    }
    else{
        wait(NULL);//it suspend current process till one of its child process terminates
        printf("child completed");
        exit(0); 
        }
}
