#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid;

void* faktorial(void *arg){
	int i;
	int asu = (int)arg;
	unsigned long long bilangan=1;
	for(i=1; i<=asu; i++)bilangan = bilangan * i;
	printf("Hasil %d! = %llu\n",arg,bilangan);
}

int main(int argc, char *argv[]){

	pthread_t tid[5];
	
	int i=0;

	if(argc<2){
		printf("Masukan minimal 2 argument\n");
	}

	for(i=1;i<argc;i++){		
     		char* s = argv[i];
     		char* num_ptr = s;
     		while(*num_ptr < '0' || *num_ptr > '9')++num_ptr;
		int number = atoi(num_ptr);
		pthread_create(&(tid[i]),NULL,&faktorial,(void*)number);
		//err = pthread_create(&(tid[i]),NULL,&faktorial,(void*)number);
		//int err;		
		//if(err!=0)printf("Gagal create thread\n");
		//else printf("Berhasil membuat thread\n");
	}
	for(i=1;i<argc;i++)pthread_join(tid[i],NULL);
}
