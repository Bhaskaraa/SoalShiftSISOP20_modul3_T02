# SoalShiftSISOP20_modul3_T02
Repository Sebagai Laporan Resmi Soal Shift Modul 3 Praktikum Sistem Operasi 2020\
Disusun oleh : 
- I Gde Made Bhaskara Jala Dhananjaya (05311840000007)
- Azmi (05311840000047)

# Daftar Isi
## [Soal 1]()
- [Penyelesaian Soal Pokezone]()
- [Penyelesaian Soal Traizone]()
- [Dokumentasi Output yang Dihasilkan]()

## [Soal 2]()
- [Penyelesaian Soal 2 - Client]()
- [Penyelesaian Soal 2 - Server]()
- [Dokumentasi Output yang Dihasilkan]()

## [Soal 3]()
- [Penyelesaian Soal 3]()
- [Dokumentasi Output yang Dihasilkan]()

## [Soal 4]()
- [Penyelesaian Soal 4a]()
- [Dokumentasi Output yang Dihasilkan 4a]()
- [Penyelesaian Soal 4b]()
- [Dokumentasi Output yang Dihasilkan 4b]()
- [Penyelesaian Soal 4c]()
- [Dokumentasi Output yang Dihasilkan 4c]()

# Soal 1 - Pokezone dan Traizone

File untuk penyelesaian soal ini ada disini : [Source Code Soal 1]()

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 1.
![]()

# Soal 2  

File untuk penyelesaian soal ini ada disini : [Source Code Soal 2]()

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 2.
![]()

# Soal 3 

File untuk penyelesaian soal ini ada disini : [Source Code Soal 3]()

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 3.
![]()

# Soal 4 - Norland The Explorer!

File untuk penyelesaian soal ini ada disini : [Source Code Soal 4](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/tree/master/Soal%204)

## Soal 4a - Emerald the Multiply of Matrix
```
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
```
- ljbjk
```
struct bagi{
    int status;
    int data[50];
  };
```
- lkln
```
    int mks1[4][2] = {{1, 1}, {2, 1}, {2, 1}, {1, 2}};
    int mks2[2][5] = {{1, 2, 1, 1, 1}, {1, 1, 2, 1, 1}};
    int mks3[4][5];
    int a,b,c;
    int line = 0;
```
- lkn
```
void* multiply(void* arg){
    int a = line++;
    for (int b=0; b<5; b++){
    for(int c=0; c<2; c++){
    mks3[a][b] += mks1[a][c] * mks2[c][b];
  	}
  }
}
```
- ljb
```
int main(){

	pthread_t tid[4];
	for (int a=0; a<4; a++){
		pthread_create(&(tid[a]), NULL, &multiply, NULL);
	}

	for (int a=0; a<4; a++){
		pthread_join((tid[a]), NULL);
	}
```
- lj
```
  printf("Hasil perkalian matriks A dan B :\n");
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 5; b++) {
      printf("%4d", mks3[a][b]);
    }
  printf("\n");
}
```
- kk
```
  key_t shmkey;
  int shmid;
  struct bagi *shmptr;

  shmkey = ftok("key",50);
  shmid = shmget(shmkey,sizeof(struct bagi),IPC_CREAT|0666);
  if(shmid < 0){
    printf("ERROR!\n");
    exit(1);
  }
```
- jkbk
```
  shmptr = (struct bagi *) shmat(shmid, NULL, 0);
  shmptr->status = BELUM_SIAP;
  int b = 0;
  int c = 0;

  for(int a = 0; a < 20; a++){
    shmptr->data[a] = mks3[b][c];
    c++;
  }
```
- kmpk
```
    shmptr->status = SIAP;

    while (shmptr->status != TERAMBIL)
    sleep(1);
    shmdt((void *) shmptr);
    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
    printf("\n");

    return 0;
  }
  ```
- kn

## Dokumentasi Penyelesaian Soal 4a
![]()

## Soal 4b - Amethyst the Factorial of Matrix
```
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
```
- js
```
typedef long long banyak;
struct bagi{
    int status;
    int data[50];
};
    int line = 0;
    int row = 0;
    int mks3[4][5];
```
-dDXA
```
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
```
- asda
```
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
```
- dsads
```
  //Jika attachment berhasil
	ShmPTR = (struct bagi*) shmat(ShmID, NULL, 0);
	while (ShmPTR->status != SIAP)
	;
```
- das
```
	printf("Matriks (C) hasil perkalian A dan B adalah sebagai berikut : \n");
		memcpy(mks3, &ShmPTR->data, 50 * sizeof(int));
		for(int b=0; b<4; b++){
			for(int c=0; c<5; c++){
      		printf("%4d", mks3[b][c]);
			}
		printf("\n");
		}
```
- jlbj
```
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
```
- lkj
```
	ShmPTR->status = TERAMBIL;
	shmdt((void *) ShmPTR);
	printf("\n");

	return 0;
}
```
- jb

## Dokumentasi Penyelesaian Soal 4b
![]()

## Soal 4c - Onyx the Sum of File
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
```
- ssss
```
int main()
{
    int fd1[2]; //membuat dua ujung pipe
    pid_t p;

    //Kondisi jika pipe gagal
    if (pipe(fd1)==-1){
        exit(1);
    }
```
- ljn
```
    p = fork();
    //Kondisi jika proses anak gagal
    if (p < 0){
        exit(EXIT_FAILURE);
    }
```
-l
```
    else if (p > 0){
        //selesai menulis
        close(1);
        //menulis
        dup(fd1[1]);
        //selesai membaca
        close(fd1[0]);
        execlp("ls","ls",NULL);
    }
```
-mk
```
    else{
        //close reading
        close(0);
        //membaca
        dup(fd1[0]);
        //selesai menulis
        close(fd1[1]);
        execlp("wc","wc", "-l", NULL);
    }
}
```
-klakns

## Dokumentasi Penyelesaian Soal 4c
![]()

## Kendala yang Dialami
***1.*** Penulis masih menyesuaikan diri dengan sistem operasi LINUX/Ubuntu sehingga ada beberapa kendala dalam menggunakan terminal. \
***2.*** Soal jauh diatas kemampuan penulis terutama nomor 1. \
***3.*** Banyak command baru yang penulis belum pernah dengar maupun gunakan sebelumnya. \
***4.*** Penulis belum memahami dengan penuh yang diberikan pada modul 3. \
***5.*** Karena keadaan yang WFH, penulis sulit berdiskusi dengan anggota kelompok. \
