#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

struct timeval start;
struct timeval stop;

void sampleStart(){
    gettimeofday(&start, NULL);

}

void sampleStop(){
    gettimeofday(&stop, NULL);
}

void printTime(){
    stop.tv_sec -= start.tv_sec;
    printf("%f\n", (double) (stop.tv_sec*1000000+stop.tv_usec));
}

void matrixMul(int N, int a[N][N], int b[N][N], int r[N][N]){
  int i, j, k;
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      r[i][j] = 0;
      for(k=0; k<N; k++)
        r[i][j] += a[i][k] * b[k][j];
    }
  }
}

void matrixT(int m, int n, int a[m][n], int r[n][m]){
  int i, j;
  for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      r[j][i] = a[i][j];
}

void matrixInit(int m, int n, int a[m][n]){
  int i, j;
  for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      a[i][j] = rand() % 100 + 1;
}

void matrixPrint(int m, int n, int a[m][n]){
  int i, j;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++)
      printf("\t%d", a[i][j]);
    printf("\n");
  }
}

int main(int argc, char **argv){
  srand(time(NULL));
  int N = (int) atoi(argv[1]);
  int a[N][N];
  int b[N][N];
  int c[N][N];

  matrixInit(N, N, a);
  matrixInit(N, N, b);

  /*
  matrixPrint(N, N, a);
  printf("\n");
  matrixPrint(N, N, b);
  */

  sampleStart();
  matrixMul(N, a, b, c);
  sampleStop();
  /*
  printf("\n");
  matrixPrint(N, N, c);
  */

  printTime();

  return 0;
}
