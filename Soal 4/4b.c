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

	key_t shmkey;
	int shmid;
	struct bagi *shmptr;

	shmkey = ftok("key",50);
	shmid = shmget(shmkey,sizeof(struct bagi),0666);
	if(shmid < 0){
		printf(" ERROR \n");
		exit(1);
	}
  
	shmptr = (struct bagi*) shmat(shmid, NULL, 0);
	while (shmptr->status != SIAP)
	;

	printf("Matriks (C) hasil perkalian A dan B adalah sebagai berikut : \n");
		memcpy(mks3, &shmptr->data, 50 * sizeof(int));
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

		*x = shmptr->data[a];
		pthread_create(&(tid[a]), NULL, &factorial, x);
		pthread_join(tid[a], NULL);
	}

	shmptr->status = TERAMBIL;
	shmdt((void *) shmptr);
	printf("\n");

	return 0;
}
