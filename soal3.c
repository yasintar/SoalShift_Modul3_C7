#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];

void* playandcount(void *arg) {
    pthread_t id=pthread_self();
    int mkn, stat[2]={100,100}; // 0 = Lohan, 1 = Kepiting
    if(pthread_equal(id,tid[0])){//thread untuk menjalankan counter
    while(1){
	printf("Lohan %d\n", stat[0]);
	printf("Kepiting %d\n", stat[1]);
	printf("1. Beri Makan Kepiting\n");
	printf("2. Beri Makan Lohan\n");
	scanf("%d", &mkn);
	if(mkn==1)stat[1]+=10;
	if(mkn==2)stat[0]+=10;
	//if(stat[0]>100||stat[0]<0||stat[1]>100||stat[1]<0)break;
	}
    }
    else if(pthread_equal(id,tid[1])){
    while(1){
	sleep(10);
	stat[0]-=15;
	sleep(10);
	stat[1]-=10;
	stat[0]-=15;	
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
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
