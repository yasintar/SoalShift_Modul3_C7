#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];
int mkn, stat[2]={100,100}; // 0 = Lohan, 1 = Kepiting
int loop=1;

void* playandcount(void *arg) {
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0])){//thread untuk menjalankan counter
    while(1){
	system("clear");
	printf("Kepiting %d\n", stat[1]);
	printf("Lohan %d\n", stat[0]);
	printf("1. Beri Makan Kepiting\n");
	printf("2. Beri Makan Lohan\n");
	scanf("%d", &mkn);
	if(mkn==1)stat[1]+=10;
	if(mkn==2)stat[0]+=10;
	if(stat[0]>100||stat[0]<0||stat[1]>100||stat[1]<0){
		if(stat[0]>stat[1]){
			system("clear");
			printf("Lohan Win\n");			
			exit(0);
		}
		if(stat[1]>stat[0]){
			system("clear");
			printf("Kepiting Win\n");	
			exit(0);		
		}
	}
    }
}
    else if(pthread_equal(id,tid[1])){
    while(1){
	sleep(10);
	stat[0]-=15;
	if(stat[0]>100||stat[0]<0||stat[1]>100||stat[1]<0){
		if(stat[0]>stat[1]){
			system("clear");
			printf("Lohan Win\n");			
			exit(0);
		}
		if(stat[1]>stat[0]){
			system("clear");
			printf("Kepiting Win\n");	
			exit(0);		
		}
	}
	system("clear");
	printf("Kepiting %d\n", stat[1]);
	printf("Lohan %d\n", stat[0]);
	printf("1. Beri Makan Kepiting\n");
	printf("2. Beri Makan Lohan\n");
	sleep(10);
	stat[1]-=10;
	stat[0]-=15;
	if(stat[0]>100||stat[0]<0||stat[1]>100||stat[1]<0){
		if(stat[0]>stat[1]){
			system("clear");
			printf("Lohan Win\n");			
			exit(0);
		}
		if(stat[1]>stat[0]){
			system("clear");
			printf("Kepiting Win\n");	
			exit(0);		
		}
	}
	system("clear");
	printf("Kepiting %d\n", stat[1]);
	printf("Lohan %d\n", stat[0]);
	printf("1. Beri Makan Kepiting\n");
	printf("2. Beri Makan Lohan\n");
	}
    }
    return NULL;
}

int main(void)
{
    int i=0;
    int err;
    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
