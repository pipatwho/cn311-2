#include <pthread.h>
#include <string.h>
#include <stdio.h>

char name[] = "Pipat Thaiyamart";

int numThread = 4;

void doTask(void *t){
    long tID = (long) t;
    if(tID == 0){
        printf("THREAD #1 : name = %s\n", name);
    }
    if(tID == 1){
        int i;
        printf("THREAD #2 : reverse name = ");
        for(i = strlen(name)-1; i>=0; i--){
            printf("%c",name[i]);
        }
        printf("\n");
    }
    if(tID == 3){
        int sum = 0;
        int i;
        for(i = 1; i< strlen(name); i++){
            sum += (int) name[i];
        }
        printf("THREAD #3 : sum of ASCII = %d",sum);
    }
    if(tID == 4){
        printf("THREAD #4 : = number of character = %d", (int) strlen(name));
    }
}

int main(){
    pthread_t threads[numThread];
    long t;
    for(t = 0; t< numThread; t++){
        pthread_create(&threads[t],NULL,doTask,(void *)t);
    }
  
    
    return 0;
}
