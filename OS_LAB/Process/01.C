// Question 1-Process
// Write a C program that creates a child process using fork(). Print:
// •	Parent PID 
// •	Child PID 
// •	Parent Process ID (PPID) of child


#include <stdio.h>
 #include<unistd.h>
int main(){

    int Pid = fork();
    if(Pid == 0){
        printf("Child ID : %d \n",getpid());
        printf("Child Parent ID : %d \n",getppid());
    }
    else if(Pid == 1){
        printf("Parend ID : %d \n",getpid());
        printf("Child ID : %d",Pid);
    }
    else{
        printf("Child Not Created");}
    }

