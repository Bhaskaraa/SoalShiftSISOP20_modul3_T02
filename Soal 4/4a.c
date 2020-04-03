#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;
    int *value;
    int a,b,c;
    int mks1[4][2] {
      {1, 2},
  		{2, 3},
  		{2, 1},
  		{3, 1}
    };

    int mks2[2][5] {
      {3, 1, 2, 3, 1},
  		{2, 3, 1, 1, 1}
    };
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);
}


for (a = 0; a < 4; a++) {
  for (b = 0; b < 5; b++) {
    for (k = 0; k < 2; k++) {
      sum = sum + m1[c][k]*m2[k][d];
    }

    multiply[c][d] = sum;
    sum = 0;
  }
}
    printf("C = \n");
      for (int a=0; a<4; a++){
        for(int b=0; b<5; b++){
    printf("%4d", mks3[a][b]);
  }
  printf("\n");
}

  sleep(1);
  shmdt(value);
  shmctl(shmid, IPC_RMID, NULL);

return 0;

}
