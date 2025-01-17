#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv)
{
    int n, i, j;
    int num_game;
    int bet = 0;
    int history[3][10];
    num_game = atoi(argv[1]);
    srand(time(NULL));
    for (int a = 0; a < 2; a++) //the first two games to check if random
    {
        for (i = 0; i < 10; i++)
        {
            printf("1000\n");   //print 1000
            fflush(stdout);
            scanf("%d", &n);
            history[a][i] = n;  //record history
        }
    }
    int b = 0;
    for (b = 0; b < 10; b++)
    {
        if (history[0][b] != history[1][b]) //check if random
            break;
    }
    if (b == 10)    //not random mode 
    {
        int remain = 10000;
        for (i = 1; i <= 9; ++i)    //the third game to check if constant
        {
            bet = random() % remain;    //the third game is random
            printf("%d\n", bet); //1-9
            fflush(stdout);
            remain -= bet;
            scanf("%d", &n);
            history[2][i - 1] = n;
        }
        bet = remain;
        printf("%d\n", bet); //10
        fflush(stdout);
        scanf("%d", &n);
        history[2][9] = n;
        int c = 0;
        for (c = 0; c < 10; c++)
        {
            if (history[1][c] != history[2][c]) //check if constant
                break;
        }
        if (c == 10)    //constant mode 
        {
            for (j = 4; j <= num_game; ++j)
            {
                int sum = 0;
                if (history[2][9] > 5000)   //if 10th round over 5000, we should give up the first round
                {
                    bet = 10000;
                    for (int d = 2; d <= 10; ++d)
                    {
                        if (history[2][d - 1] != 0)
                            bet = bet - history[2][d - 1] + 1;
                        else
                            bet = bet - history[2][d - 1];
                    }

                    printf("%d\n", bet); //1
                    fflush(stdout);
                    scanf("%d", &n);
                    for (i = 1; i < 10; i++)
                    {
                        if (history[2][i] == 0)
                            bet = 0;
                        else
                            bet = history[2][i] - 1;
                        printf("%d\n", bet); //2-10
                        fflush(stdout);
                        sum += bet;
                        scanf("%d", &n);
                    }
                }
                else    //history-1
                {
                    for (i = 0; i < 9; i++)
                    {
                        if (history[2][i] == 0)
                            bet = 0;
                        else
                            bet = history[2][i] - 1;
                        printf("%d\n", bet); //2-9
                        fflush(stdout);
                        sum += bet;
                        scanf("%d", &n);
                    }
                    bet = 10000 - sum;
                    printf("%d\n", bet); //10
                    fflush(stdout);
                    sum += bet;
                    scanf("%d", &n);
                }
            }
        }
        else    //predict mode 
        { 
            for (j = 4; j <= num_game; ++j)
            {
                int sum = 0;
                int d = -2; 
                int m = 10; 
                //bet = (10000 * 2 / m - (m - 1) * d) / 2;    //equal difference series
                bet=1;
                printf("%d\n", bet); //1
                fflush(stdout);
                sum += bet;
                scanf("%d", &n);
                for (i = 2; i <= 9; ++i)
                {
                    bet -= 2;
                    bet=bet>0?bet:0;
                    printf("%d\n", bet); //2-9
                    fflush(stdout);
                    sum += bet;
                    scanf("%d", &n);
                }
                bet = 10000 - sum;
                printf("%d\n", bet); //10
                fflush(stdout);
                sum += bet;
                scanf("%d", &n);
            }
        }
    }
    else //random mode 
    {
        double history_exp[10];
        double history_sum = 0.0;
        for (int a = 0; a < 10; a++)
        {
            history_exp[a] = (history[0][a] + history[1][a]) / 2;   //average value to compute mathematical expectation
            //history_sum += history_exp[a];
        }

        for (j = 3; j <= num_game; ++j)
        {
            int sum = 0;
            for (int b = 0; b < 9; b++)
            {
                bet = history_exp[b] - 1;
                bet = bet > 0 ? bet : 0; // prevent minus
                printf("%d\n", bet); //1-9
                fflush(stdout);
                sum += bet;
                scanf("%d", &n);
                history_exp[b] = (history_exp[b] * (j - 1) + n) / j;    //average value to compute mathematical expectation
            }
            bet = 10000 - sum;
            printf("%d\n", bet); //10
            fflush(stdout);
            scanf("%d", &n);
            history_exp[9] = (history_exp[b] * (j - 1) + n) / j;    //average value to compute mathematical expectation
        }
    }
    exit(EXIT_SUCCESS);
}