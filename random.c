#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char **argv){
  int n,i,j;
  int num_game;
  struct timespec spec;
  clock_gettime(CLOCK_REALTIME, &spec);

  num_game=atoi(argv[1]);

  srand(spec.tv_nsec);

  for(j=1;j<=num_game;++j){
    int bet;
    int remain=10000;

    for(i=1;i<=9;++i){
      bet=random()%remain;
      printf("%d\n",bet); //1-9
      fflush(stdout);
      remain-=bet;
      scanf("%d",&n);
    }

    bet=remain;
    printf("%d\n",bet); //10
    fflush(stdout);
    scanf("%d",&n);
  }

  exit(EXIT_SUCCESS);
}