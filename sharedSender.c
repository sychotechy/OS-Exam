//Interprocess communication sender-program
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
    void *sharedMemory;
    char buffer[100];
    int shmid;
    shmid = shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("Key of the shared memory : %d\n",shmid);
    sharedMemory = shmat(shmid,NULL,0);
    printf("Process attached at %p\n",sharedMemory);
    printf("Enter some data to write : \n");
    read(0,buffer,100);
    strcpy(sharedMemory,buffer);
    printf("You wrote at shared memory : %s",(char *)sharedMemory);
    return 0;
}