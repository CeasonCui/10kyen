#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
  int n,j,k,num_game;

  num_game=atoi(argv[1]);
  int aite[10]={4999,2499,1249,624,311,155,77,38,18,30};
  for(k=1;k<=num_game;++k)
    for(j=1;j<=10;++j){
      printf("%d\n", aite[j-1]);
      fflush(stdout);
      scanf("%d",&n);
    }

  exit(EXIT_SUCCESS);
}