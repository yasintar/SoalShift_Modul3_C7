#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void* findstring(void *arg){
	int count=0;
	char *string=(char*)arg;
	FILE *fp=fopen("novel.txt","r");
	char len[256];
	if(fp==NULL){
	printf("File not found!\n");
	} else {
	while(fscanf(fp,"%s",len)!=EOF)
	if(!strncmp(len,string,strlen(string)))count++;
	printf("%s : %d \n", arg, count);
	}
}

int main(int argc, char *argv[]){

	pthread_t tid[5];

	int i=0;

	if(argc<2){
		printf("Masukan minimal 2 argument\n");
	}

	for(i=1;i<argc;i++)pthread_create(&(tid[i]),NULL,&findstring,(void*) argv[i]);
	for(i=1;i<argc;i++)pthread_join(tid[i],NULL);
}
