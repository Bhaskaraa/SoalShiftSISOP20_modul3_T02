#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define BELUM_SIAP -1
#define SIAP 0
#define TERAMBIL 1
#define MAX 50

typedef long long banyak;
struct bagi{
    int status;
    int data[50];
};
    int line = 0;
    int row = 0;
    int mks3[4][5];

void* factorial(void* arg){
	int a = *((int*)arg);
	free(arg);;
	banyak total = 0;
	for(int b = a; b > 0 ;b--){
		total += b;
	}
	if(row > 4){
		printf("\n");
		row = 0;
	}
	printf("%15llu", total);
	row++;
}


int main(){

	key_t ShmKEY;
	int ShmID;
	struct bagi *ShmPTR;

	ShmKEY = ftok("key",50);
	ShmID = shmget(ShmKEY,sizeof(struct bagi),0666);
	if(ShmID < 0){
		printf(" ERROR \n");
		exit(1);
	}

  //Jika attachment berhasil
	ShmPTR = (struct bagi*) shmat(ShmID, NULL, 0);
	while (ShmPTR->status != SIAP)
	;

	printf("Matriks (C) hasil perkalian A dan B adalah sebagai berikut : \n");
		memcpy(mks3, &ShmPTR->data, 50 * sizeof(int));
		for(int b=0; b<4; b++){
			for(int c=0; c<5; c++){
      		printf("%4d", mks3[b][c]);
			}
		printf("\n");
		}

	printf("Jumlah faktorial dari variabel matriks C : \n");
	pthread_t tid[20];
	for(int a = 0; a < 20;a++){
		int *x =  malloc(sizeof(*x));
		if( x == NULL){
			printf("TIDAK BISA MEMBUAT RUANG\n");
			exit(1);
		}

		*x = ShmPTR->data[a];
		pthread_create(&(tid[a]), NULL, &factorial, x);
		pthread_join(tid[a], NULL);
	}

	ShmPTR->status = TERAMBIL;
	shmdt((void *) ShmPTR);
	printf("\n");

	return 0;
}
