#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int mkn, stat[2]={100,100};
	while(1){
		printf("Lohan %d\n", stat[0]);
		printf("Kepiting %d\n", stat[1]);
		printf("1. Beri Makan Kepiting\n");
		printf("2. Beri Makan Lohan\n");
		scanf("%d", &mkn);
		if(mkn==1)stat[0]+=10;
		if(mkn==2)stat[1]+=10;
		if(stat[0]>100||stat[0]<0||stat[1]>100||stat[1]<0)break;
	}
}
