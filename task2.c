#include <pthread.h>
#include <string.h>
#include <stdio.h>

int MAX_VALUE = 1000;

int numThread = 16;

long rank[16];

int numOfWinner = 0;

void doTask(int t){
    int sum = 0;
    int i;
    for(i = 0; i<MAX_VALUE;i++){
        sum = sum + 1;
    }
    rank[numOfWinner++] = (long) t;
}

int main(){
    pthread_t threads[numThread];
    long t;
    for(t = 0; t< numThread; t++){
        pthread_create(&threads[t],NULL,doTask,(void *)t);
    }
    int i = 0;
    for(i = 0; i<3 ;i++){
        printf("The winner No.%d = ",i+1);
        printf("THREAD #%d\n", (int) rank[i]);
    }
    
    return 0;
}