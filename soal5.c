#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void* findstring(void *arg){
	int count = 0;
	printf("%s: %d\n", arg, count);
}

int main(int argc, char *argv[]){

	pthread_t tid[5];

	int i=0;

	if(argc<2){
		printf("Masukan minimal 2 argument\n");
	}

	//for(i=1;i<argc;i++){
	//	printf("%s\n",argv[i]);
	//}

	for(i=1;i<argc;i++){
		int err;
		err = pthread_create(&(tid[i]),NULL,&findstring,(void*) argv[i]);
		if(err!=0)printf("Gagal create thread\n");
		else printf("Berhasil membuat thread\n");
	}
	for(i=1;i<argc;i++)pthread_join(tid[i],NULL);
}
