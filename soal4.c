#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid;
int n;

void* faktorial(void *arg){

	int i;
	unsigned long long bilangan=1;
	pthread_t id=pthread_self();
	scanf("%d",&n);
	
	if(pthread_equal(id,tid)){
		if(n < 0) printf("Error.\n");
		else {
			for(i=1; i<=n; i++){
				bilangan = bilangan * i;
			} printf("Hasil %d! = %llu\n",n,bilangan);
		}
	}
	else {
		pthread_exit(0);
	}
	
	return NULL;
}

int main(void){
	
	pthread_create(&(tid),NULL,&faktorial,NULL);
	pthread_join(tid,NULL);
	
/*	int i;
	int hasil;
	void *status = 0;
	
	scanf("%d",&n);
			
	pthread_create(&tid,NULL,faktorial,&hasil);
	pthread_join(tid,&hasil);
	
	if(status != 0){
		printf("%d\n",hasil);
	} else {
		printf("Can't create thread.\n");
	}	*/
	
	
	return 0;
	
}
