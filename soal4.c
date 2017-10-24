#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[100];
int n;

void* faktorial(void *arg){

//ingatyasdisinikurang 	
	int bilangan=1;
	for(int a=1; a<=n; a++){
		bilangan = bilangan * a;
	}
}

int main(void){
	
	int i=0;
//	int err;
	int input;
	
	scanf("%d",&input);
	
/*	while(i<n){
		err = pthread_create(&(tid[i]),NULL,&faktorial,NULL);
		if(err != 0){
			printf("\nCan't create thread : [%s]",strrerror(err));
		} else {
			printf("\nCreate thread %d success\n",i);
		}
		i++;
	} */
	
	pthread_create(&(tid[i]),NULL,&faktorial);	
	
	pthread_join(tid,NULL);
			

	
	
	return 0;
	
}
