#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[100];
int n;

void* faktorial(){

	int bilangan=1;
	for(int a=1; a<=n; a++){
		bilangan = bilangan * a;
	}
}

int main(void){
	
	

	
	
	return 0;
	
}
