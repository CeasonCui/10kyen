#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
  int n,j,k,num_game;

  num_game=atoi(argv[1]);

  for(k=1;k<=num_game;++k)
    for(j=1;j<=10;++j){
      printf("1000\n");
      fflush(stdout);
      scanf("%d",&n);
    }

  exit(EXIT_SUCCESS);
}