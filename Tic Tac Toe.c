#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

void game();
int check(char );
void display();
void input(int, char);
char p1='X', p2='O';
int check_draw();
char board[3][3]={'1','2','3',
                  '4','5','6',
                  '7','8','9'};
int main()
{
    game();
    getch();
}

void game()
{   int move,i;
    char player;
    for(i=0;i<9;i++)
    {    system("cls");
         printf("\n\t\t\t TIC TAC TOE\t\t\n");
         display();
         fflush(stdin);
         if ( i % 2 == 0 )
         {
            printf("\n Please enter a move player 1");
            scanf("%d", &move);
            player=p1;
            input(move, player);
            check(player);
         }
        else
        {
            printf("\n Please enter a move player 2");
            scanf("%d", &move);
            player=p2;
            input(move, player);
            check(player);
        }
    }
    printf ( "Draw!\n\n");
    display();
}

void input(int n, char p)
{
    while ( !(isdigit ( board[(n-1)/3][(n-1)%3])) )
    {
        printf ( "Wrong option!\nEnter again!\n" );
        scanf ( "%d", &n );
    }
    int i,j;
    for(i=0;i<3;i++)
    {for(j=0;j<3;j++)
   if(p==p1)
        board[(n-1)/3][(n-1)%3] = 'X';
    else
        board[(n-1)/3][(n-1)%3] = 'O';
}
}
void display()
{
    printf("\n\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int check(char player)
{ char winner;
    int c;
    int line = 0;
           if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
           (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
               {   if(board[1][1] == 'X')
                  {     printf("\n\n Game Over Player 1 won");
                        display();
                        getch();
                        exit(0);
                  }
                   else
                  {
                   printf("\n\n Game Over Player 2 won");
                   display();
                   getch();
                   exit(0);
                  }
               }

                else
            {
                for(line = 0; line <= 2; line ++)
                {if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
                   (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                   {
                        winner=player;
                        if(player=='X')
                            {c=1;
                             printf("\n Game Over player %d won", c);
                             display();
                             getch();
                             exit(0);
                            }
                        else
                           {c=2;
                            printf("\n Game Over Player %d Won", c);
                            display();
                            getch();
                            exit(0);
                           }
                   }
}
}
}

