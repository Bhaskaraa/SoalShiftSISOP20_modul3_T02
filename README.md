# SoalShiftSISOP20_modul3_T02
Repository Sebagai Laporan Resmi Soal Shift Modul 3 Praktikum Sistem Operasi 2020\
Disusun oleh : 
- I Gde Made Bhaskara Jala Dhananjaya (05311840000007)
- Azmi (05311840000047)

# Daftar Isi
## [Soal 1](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-1---pokezone-dan-traizone)
- [Penyelesaian Soal Pokezone]()
- [Penyelesaian Soal Traizone]()
- [Dokumentasi Output yang Dihasilkan](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-1)

## [Soal 2](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-2-1)
- [Penyelesaian Soal 2 - Client]()
- [Penyelesaian Soal 2 - Server]()
- [Dokumentasi Output yang Dihasilkan](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-2)

## [Soal 3](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-3-1)
- [Penyelesaian Soal 3]()
- [Dokumentasi Output yang Dihasilkan](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-3)

## [Soal 4](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-4---norland-the-explorer)
- [Penyelesaian Soal 4a](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-4a---emerald-the-multiply-of-matrix)
- [Dokumentasi Output yang Dihasilkan 4a](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#dokumentasi-penyelesaian-soal-4a)
- [Penyelesaian Soal 4b](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-4b---amethyst-the-factorial-of-matrix)
- [Dokumentasi Output yang Dihasilkan 4b](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#dokumentasi-penyelesaian-soal-4b)
- [Penyelesaian Soal 4c](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#soal-4c---onyx-the-sum-of-file)
- [Dokumentasi Output yang Dihasilkan 4c](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02#dokumentasi-penyelesaian-soal-4c)

# Soal 1 - Pokezone dan Traizone

File untuk penyelesaian soal ini ada disini : [Source Code Soal 1](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/tree/master/Soal%201)

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 1.
![](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/blob/master/Screenshot/1.jpg)

# Soal 2  

File untuk penyelesaian soal ini ada disini : [Source Code Soal 2](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/tree/master/Soal%202)

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 2.
![]()

# Soal 3 

File untuk penyelesaian soal ini ada disini : [Source Code Soal 3](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/tree/master/Soal%203)

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 3.
![]()

# Soal 4 - Norland The Explorer!
Norland adalah seorang penjelajah terkenal. Suatu malam ia menemukan tiga pilar dengan masing-masing terdapat batu dengan teka-teki sebagai berikut. 

***a.*** Emerald = buatlah matriks (4x2) dan (2x5) serta tampilkan hasil hasil perkalian matriks tersebut. (menggunakan shared memory) \
***b.*** Amethyst = tampilkan matriks hasil perkalian dari batu Emerald dan buatlah matriks jumlah nilai faktorial dari setiap angka dalam matriks tersebut. (menggunakan thread) \
***c.*** Onyx = hitunglah jumlah file yang ada dalam direktori tersebut. (menggunakan pipe)

Bantu Norland menyelesaikan teka-teki dari setiap batu yang ia temukan!

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
- Source code diatas merupakan library yang digunakan untuk penyelesaian soal 4a. 
- Terdapat tiga ***define*** untuk status, dimana jika nilainya ***-1*** maka statusnya adalah ***BELUM_SIAP***, jika nilainya ***0*** maka statusnya adalahnya ***SIAP***, dan jika nilainya ***1*** maka statusnya adalah ***TERAMBIL***.
```
struct bagi{
    int status;
    int data[50];
  };
```
- Source code diatas berfungsi untuk membuat variabel ***struct*** dengan nama ***bagi***, dimana di dalamnya mendeklarasikan variabel status bertipe integer dan data bertipe integer dengan ukuran 50 bit.
```
    int mks1[4][2] = {{1, 1}, {2, 1}, {2, 1}, {1, 2}};
    int mks2[2][5] = {{1, 2, 1, 1, 1}, {1, 1, 2, 1, 1}};
    int mks3[4][5];
    int a,b,c;
    int line = 0;
```
- Source code diatas berfungsi untuk mendeklarasikan matriks 1 yang berukuran ***(4x2)*** dengan isinya seperti diatas, matriks 2 yang berukuran ***(2x5)*** dengan isinya seperti diatas, dan matriks 3 dengan ukutan ***(4x5)*** yang merupakan matriks hasil kali matriks 1 dan 2. Kemudian deklarasi variabel a, b, c, dan line yang bertipe integer.
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
- Source code diatas merupakan fungsi untuk mengalikan matriks 1 dan 2.
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
- `pthread_create` diatas berfungsi untuk membuat thread untuk menjalankan fungsi ***multiply*** dengan parameter variabel a.
- `pthread_join` diatas berfungsi untuk join dengan thread yang telah dibuat sebelumnya dan menampilkan hasilnya.
```
  printf("Hasil perkalian matriks A dan B :\n");
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 5; b++) {
      printf("%4d", mks3[a][b]);
    }
  printf("\n");
}
```
- Source diatas berfungsi untuk menampilkan hasil kali matriks 1 dan 2 yang merupakan berbentuk matriks 3 dengan ukuran (4x5).
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
- `shmkey` adalah Shared Memory Key.
- `shmid` adalah Shared Memory ID.
- `shmptr` adalah pointer struct yang akan di passing.
- `shmkey = ftok("key",50)` untuk menetepkan ukuran key yang sama di semua proses yakni 50 bit.
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
- `shmptr = (struct bagi *) shmat(shmid, NULL, 0)` shmptr menunjuk ke struct bagi dan melampirkan segmen Shared Memory.
- `shmptr->data[a] = mks3[b][c` shmptr dipassing dengan parameter variabel a ke matriks 3.
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
- `while (shmptr->status != TERAMBIL)` berarti server menunggu client di terminal baru.
- `shmdt((void *) shmptr)` untuk mendeteksi apakah proses anak telah selesai.
- `shmctl(shmid, IPC_RMID, NULL)` berarti server telah melepas shared memory dan telah dihapus.

## Dokumentasi Penyelesaian Soal 4a
![](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/blob/master/Screenshot/4a.png)

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
- Source code diatas merupakan library yang digunakan untuk menyelesaikan soal 4b. 
- Terdapat tiga ***define*** untuk status, dimana jika nilainya ***-1*** maka statusnya adalah ***BELUM_SIAP***, jika nilainya ***0*** maka statusnya adalahnya ***SIAP***, dan jika nilainya ***1*** maka statusnya adalah ***TERAMBIL***.
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
- `typedef long long banyak` mendefinisikan variabel *banyak* bertipe *long long*.
- Kemdian membuat variabel ***struct*** dengan nama ***bagi***, dimana di dalamnya mendeklarasikan variabel status bertipe integer dan data bertipe integer dengan ukuran 50 bit.
- Kemudian mendeklarasikan variabel line, row, mks3 bertipe integer dan matriks 3 berukuran (4x5).
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
- Source code diatas merupakan fungsi untuk menghitung jumlah faktorial dari variabel yang ada di matriks 3.
```
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
```
- `shmkey` adalah Shared Memory Key.
- `shmid` adalah Shared Memory ID.
- `shmptr` adalah pointer struct yang akan di passing.
- `shmkey = ftok("key",50)` untuk menetepkan ukuran key yang sama di semua proses yakni 50 bit.
```
	ShmPTR = (struct bagi*) shmat(shmid, NULL, 0);
	while (shmptr->status != SIAP)
	;
```
- Source code diatas adalah kondisi ketika ***attachment*** berhasil.
```
	printf("Matriks (C) hasil perkalian A dan B adalah sebagai berikut : \n");
		memcpy(mks3, &shmptr->data, 50 * sizeof(int));
		for(int b=0; b<4; b++){
			for(int c=0; c<5; c++){
      		printf("%4d", mks3[b][c]);
			}
		printf("\n");
		}
```
- Source diatas adalah fungsi untuk menampilkan matriks 3. `memcpy(mks3, &shmptr->data, 50 * sizeof(int)` merupakan memori yang berisi matriks 3 yang disimpan dari soal 4a.
```
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
```
- Source code diatas merupakan fungsi untuk membuat dan menampilkan matriks keempat yang berisi jumlah nilai faktorial dari variabel yang ada di matriks 3. 
- `int *x =  malloc(sizeof(*x)` merupakan ukuran dari matriks 4 yang diambil dari ukuran matriks 3. `if( x == NULL)` jika nilai variabel ***x*** bernilai NULL atau kosong, output yang dihasilkan adalah ***TIDAK BISA MEMBUAT RUANG***.
```
	ShmPTR->status = TERAMBIL;
	shmdt((void *) shmptr);
	printf("\n");

	return 0;
}
```
- `ShmPTR->status = TERAMBIL` server sedang menunggu client di terminal baru.
- `shmdt((void *) shmptr)` berfungsi untuk mendeteksi apakah proses anak telah selesai.

## Dokumentasi Penyelesaian Soal 4b
![](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/blob/master/Screenshot/4b.png)

## Soal 4c - Onyx the Sum of File
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
```
- Source code diatas merupakan library yang digunakan untuk menyelesaikan soal nomor 4c.
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
- `int fd1[2]` mendeklarasikan variabel ***fd1*** bertipe integer dan membuat dua ujung pipe (read and write).
- `pid_t p` mendeklarasikan variabel ***p*** untuk menyimpa parent ID.
```
    p = fork();
    //Kondisi jika proses anak gagal
    if (p < 0){
        exit(EXIT_FAILURE);
    }
```
- Source code diatas merupakan kondisi jika gagal membuat proses anak.
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
- `close(1)` berfungsi untuk close writting atau stop menulis.
- `dup(fd1[1])` berfungsi untuk menulis.
- `close(fd1[0])` berfungsi untuk close reading atau stop membaca.
- `execlp("ls","ls",NULL)` menjalankan fungsi listing.
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
- `close(0)` berfungsi untuk stop membaca.
- `dup(fd1[0])` fungsi reading dilakukan.
- `close(fd1[1])` berfunsi untuk close writting atau stop menulis.
- `execlp("wc","wc", "-l", NULL)` untuk keluar dari pipe dan menuliskan hasil listing.

## Dokumentasi Penyelesaian Soal 4c
![](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul3_T02/blob/master/Screenshot/4c.png)

## Kendala yang Dialami
***1.*** Penulis masih menyesuaikan diri dengan sistem operasi LINUX/Ubuntu sehingga ada beberapa kendala dalam menggunakan terminal. \
***2.*** Soal jauh diatas kemampuan penulis terutama nomor 1. \
***3.*** Banyak command baru yang penulis belum pernah dengar maupun gunakan sebelumnya. \
***4.*** Penulis belum memahami dengan penuh yang diberikan pada modul 3. \
***5.*** Karena keadaan yang WFH, penulis sulit berdiskusi dengan anggota kelompok. \
