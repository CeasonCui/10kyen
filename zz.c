#include <stdio.h>
#include <stdlib.h>

int h(int a, int b)
{
    return b - (b - a) / 2;
};

int main(int argc, char **argv)
{
    int n, i, j;
    int num_game;
    int bet = 0;
    int aite[2] = {0, 0};
    int history[3][10];
    num_game = atoi(argv[1]);
    for (int a = 1; a <= 2; ++a)
    {
        for (i = 1; i <= 10; ++i)
        {
            printf("1000\n");
            fflush(stdout);
            scanf("%d", &n);
            history[a - 1][i - 1]=n;
        }
    }
    int b = 1;
    for (b = 1; b <= 10; ++b)
    {
        if (history[0][b - 1] != history[1][b - 1])
            break;
    }
    if (b == 10)
    {
        int remain = 10000;
        for (i = 1; i <= 9; ++i)
        {
            bet = random() % remain;
            printf("%d\n", bet); //1-9
            fflush(stdout);
            remain -= bet;
            scanf("%d", &n);
        }
        bet = remain;
        printf("%d\n", bet); //10
        fflush(stdout);
        scanf("%d", &n);
        history[2][i - 1];
        int c = 1;
        for (c = 1; c <= 10; ++c)
        {
            if (history[1][c - 1] != history[2][c - 1])
                break;
        }
        if (c == 10) //GUDING
        {
            for (j = 4; j <= num_game; ++j)
            {
                int sum = 0;
                if (history[2][9] > 5000)
                {
                    bet = 10000;
                    for (int d = 1; d <= 10; ++d)
                    {
                        if (history[2][d - 1] != 0)
                            bet = bet - history[2][d - 1] + 1;
                        else
                            bet = bet - history[2][d - 1];
                    }

                    printf("%d\n", bet); //1
                    fflush(stdout);
                    scanf("%d", &n);
                    for (i = 2; i <= 10; ++i)
                    {
                        if (history[2][i - 1] == 0)
                            bet = 0;
                        else
                            bet = history[2][i - 1] - 1;
                        printf("%d\n", bet); //2-10
                        fflush(stdout);
                        sum += bet;
                        scanf("%d", &n);
                    }
                }
                else
                {
                    for (i = 1; i <= 9; ++i)
                    {
                        if (history[2][i - 1] == 0)
                            bet = 0;
                        else
                            bet = history[2][i - 1] - 1;
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
        else
        { //minus1
            for (j = 4; j <= num_game; ++j)
            {
                int sum = 0;                
                //defense mode
                int d = -2;     //Derivation
                int n = 10; //remaining rounds
                bet = (10000 * 2 / n - (n - 1) * d) / 2;
                printf("%d\n", bet); //1
                fflush(stdout);
                sum += bet;
                scanf("%d", &n);
                for (i = 2; i <= 9; ++i)
                {
                    bet -= 2;
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
    else{//random
        double history_exp[10];
        double history_sum = 0.0;
        for(int a=0;a<10;a++){
            history_exp[a]=(history[0][a]+history[1][a])/2;
            history_sum += history_exp[a];
        }
        
        for (j = 3; j <= num_game; ++j){
            int sum = 0;  
            for(int b=0;b<9;b++){
                for(int a=0;a<10;a++){
                    history_exp[a] = history_exp[a] / history_sum * 10000;
                }
                bet=history_exp[b]-1;
                bet=bet>0?bet:0;
                printf("%d\n", bet); //1-9
                fflush(stdout);
                sum += bet;
                scanf("%d", &n);
                history_exp[b]=(history_exp[b]*(j-1)+n)/j;
                history_sum = 0.0;
                for(int a=0;a<10;a++){
                    history_sum += history_exp[a];
                }
                
            }
            bet = 10000 - sum;
            printf("%d\n", bet); //10
            fflush(stdout);
            scanf("%d", &n);
            history_exp[9]=(history_exp[b]*(j-1)+n)/j;
        }
    }
    exit(EXIT_SUCCESS);
}

    // for (j = 1; j <= num_game; ++j)
    // {
    //     int bet = 0;
    //     int sum = 0;
    //     int aite[2] = {0, 0};
    //     printf("%d\n", bet); //1
    //     fflush(stdout);
    //     scanf("%d", &n);
    //     aite[0] = n;
    //     bet = n - 1;
    //     sum += bet;
    //     printf("%d\n", bet); //2
    //     fflush(stdout);
    //     scanf("%d", &n);
    //     aite[1] = n;
    //     if (aite[0] == 0 && aite[1] == 0)
    //     {                   //defense mode
    //         int d = -2;     //Derivation
    //         int n = 10 - 2; //remaining rounds
    //         bet = (10000 * 2 / n - (n - 1) * d) / 2;
    //         printf("%d\n", bet); //3
    //         fflush(stdout);
    //         sum += bet;
    //         scanf("%d", &n);
    //         for (i = 4; i <= 9; ++i)
    //         {
    //             bet -= 2;
    //             printf("%d\n", bet); //4-9
    //             fflush(stdout);
    //             sum += bet;
    //             scanf("%d", &n);
    //         }
    //     }
    //     else
    //     {                            //attack mode, predict opponent's bet
    //         for (i = 3; i <= 9; ++i) //3-9
    //         {
    //             int r = h(aite[0], aite[1]) - 1;
    //             bet = r > 0 ? r : 0;
    //             printf("%d\n", bet);
    //             fflush(stdout);
    //             sum += bet;
    //             scanf("%d", &n);
    //             aite[0] = aite[1];
    //             aite[1] = n;
    //         }
    //     }

    //     bet = 10000 - sum;
    //     printf("%d\n", bet); //10
    //     fflush(stdout);
    //     sum += bet;
    //     scanf("%d", &n);
    // }

   
