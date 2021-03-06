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

struct bagi{
    int status;
    int data[50];
  };

    int mks1[4][2] = {{1, 1}, {2, 1}, {2, 1}, {1, 2}};
    int mks2[2][5] = {{1, 2, 1, 1, 1}, {1, 1, 2, 1, 1}};
    int mks3[4][5];
    int a,b,c;
    int line = 0;

void* multiply(void* arg){
    int a = line++;
    for (int b=0; b<5; b++){
    for(int c=0; c<2; c++){
    mks3[a][b] += mks1[a][c] * mks2[c][b];
  	}
  }
}

int main(){

	pthread_t tid[4];
	for (int a=0; a<4; a++){
		pthread_create(&(tid[a]), NULL, &multiply, NULL);
	}

	for (int a=0; a<4; a++){
		pthread_join((tid[a]), NULL);
	}

  printf("Hasil perkalian matriks A dan B :\n");
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 5; b++) {
      printf("%4d", mks3[a][b]);
    }
  printf("\n");
}

  key_t shmkey;
  int shmid;
  struct bagi *shmptr;

  shmkey = ftok("key",50);
  shmid = shmget(shmkey,sizeof(struct bagi),IPC_CREAT|0666);
  if(shmid < 0){
    printf("ERROR!\n");
    exit(1);
  }

  shmptr = (struct bagi *) shmat(shmid, NULL, 0);
  shmptr->status = BELUM_SIAP;
  int b = 0;
  int c = 0;

  for(int a = 0; a < 20; a++){
    shmptr->data[a] = mks3[b][c];
    c++;
  }
    shmptr->status = SIAP;

    while (shmptr->status != TERAMBIL)
    sleep(1);
    shmdt((void *) shmptr);
    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
    printf("\n");

    return 0;
  }
