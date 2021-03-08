#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int numThread = 8;

static int MATRIX_SIZE = 1024;

int A[1024][1024];
int B[1024][1024];
int C[1024][1024];

void createMatrixA(int size){
    int i;
    int j;
    for(i = 0; i< size; i++){
        for(j = 0; j< size; j++){
            A[i][j] = rand()%2000;
        }
    }
}

void createMatrixB(int size){
    int i, j;
    for(i = 0; i< size; i++){
        for(j = 0; j< size; j++){
            B[i][j] =  rand()%2000;
        }
    }
}


void doTask(int t){
    int times = MATRIX_SIZE/numThread;
    
    if(MATRIX_SIZE%numThread != 0){
        times++;
    }
    
    C[MATRIX_SIZE-1][MATRIX_SIZE-1] = -1;
    
    int i,j;
    
    int n = (int) t;
    
    for(i = n*times; i< n*times+ times ; i++){
        for(j = 0; j< MATRIX_SIZE; j++){
            C[i][j] = A[i][j]+B[i][j];
        }
        if(C[MATRIX_SIZE-1][MATRIX_SIZE-1] != -1){
            break;
        }
    }
}

int main(){
    pthread_t threads[numThread];
    long t;
    
    createMatrixA(MATRIX_SIZE);
    createMatrixB(MATRIX_SIZE);
    for(t = 0; t< numThread; t++){
        doTask(t);
        //pthread_create(&threads[t],NULL,doTask,(void *)t);
    }
    
    int i = 0, j = 0;
    for(i = 0; i<MATRIX_SIZE;i++){
        for(j = 0; j<MATRIX_SIZE;j++){
            printf("%d    ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

