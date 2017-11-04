#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
	key_t key = 1234;
	int menu, *stok, shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	stok=shmat(shmid, NULL, 0);
	memset(stok, 0, 6*sizeof(int));
	char *senjata[6];
	senjata[0] = "MP4A1";
	senjata[1] = "PM2-V1";
	senjata[2] = "SPR-3";
	senjata[3] = "SS2-V5";
	senjata[4] = "SPG1-V3";
	senjata[5] = "MINE";
	while(1){
		printf("Selamat datang di toko Hawari\n");
		printf("1. Lihat Stock Senjata\n");
		printf("2. Tambah Stock Senjata\n");
		scanf("%d", &menu);
		if(menu==1){
			printf("[Nama]\t[Stok]\n");
			if(stok[0]==0&&stok[1]==0&&stok[2]==0&&stok[3]==0&&stok[4]==0&&stok[5]==0)printf("Empty.\n");
			for(int i=0;i<6;i++){
				if(stok[i]>0)printf("%s\t  %d\n",senjata[i],stok[i]);
			}
		} else if(menu==2){
			char nama[10];
			int jmlh;
			printf("Masukan stok dengan format:\n");
			printf("[NAMA] [JUMLAH STOK]\n");
			scanf("%s %d", &nama, &jmlh);
			for(int i=0;i<6;i++){
				if(strcmp(nama,senjata[i])==0)stok[i]+=jmlh;
			}
		
		} 

	}

}
