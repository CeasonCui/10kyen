#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n, j, k, num_game;

    num_game = atoi(argv[1]);

    for (k = 1; k <= num_game; ++k)
    { //10th round is >=5000
        for (j = 1; j <= 9; ++j)
        {
            printf("555\n"); //1-9
            fflush(stdout);
            scanf("%d", &n);
        }
        int bet;
        bet = 10000 - 9 * 555;
        printf("%d\n", bet); //10
        fflush(stdout);
        scanf("%d", &n);
    }
    exit(EXIT_SUCCESS);
}