/*
 f |   |   
---|---|---
   |   |   
---|---|---
   |   |   
 */
 // FINISHED ON 15/05/2024
 #include<stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char p1, p2;

char board[3][3];
// we initialize board globally because any changes to board will change board in any function
void initializeboard()
{
   for(int i=0; i<3; i++)
   {
      for(int j=0; j<3; j++)
      {
         board[i][j] = ' '; // initially all cells must be empty
      }
   }
}

// Function to print the board
void printboard()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (board[i][j] == 'X') {
                printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, board[i][j]); // Print 'X' in red color
            } else if (board[i][j] == 'O') {
                printf(ANSI_COLOR_GREEN " %c " ANSI_COLOR_RESET, board[i][j]); // Print 'O' in green color
            } else {
                printf(" %c ", board[i][j]); // Print empty cell
            }
            if(j != 2)
                printf("|");
        }
        printf("\n");
        if(i != 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int gameover(); // this function is used before defining (used in move()) so we call it before 
void playgame();
// Function to make a move
void move(int row, int column, char sym)
{
    int r,c; char s;
    if (board[row][column] == ' ')//to not overwrite other players or himselve's symbol
    {
        board[row][column] = sym;
        printf("The symbol %c is successfully entered\n", sym);
        printboard();
    }
    else
    {
        printf("The cell is already occupied. Please choose another cell.\n");
        // Prompt the player to enter row and column again
        printf("Enter row, column, and symbol again: ");
        scanf("%d %d %c", &r, &c, &s);
        r--;c--;
        move(r,c,s);
    }
}


int gameover()
{
      for(int i=0; i<3; i++)
      {
         if(board[i][0] != ' ' && board[i][0] == board[i][1] &&   board[i][0] == board[i][2])
         {
         if (board[i][0] == p1)
            printf("Player-1 wins!!! CONGRATULATIONS :)\n");
        else if (board[i][0] == p2)
            printf("Player-2 wins!!! CONGRATULATIONS :)\n");
         return 0;// checking that there are no spaces (i.e any element is not entered) in any row
         }
      }

      for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] ==  board[1][j] && board[0][j] == board[2][j])
        {
            if (board[0][j] == p1)
            printf("Player-1 wins!!! CONGRATULATIONS :)\n");
        else if (board[0][j] == p2)
            printf("Player-2 wins!!! CONGRATULATIONS :)\n");
        return 0;// checking that there are no spaces (i.e any element is not entered) in any coloumn
        }
      }

    if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        if (board[1][1] == p1)
        printf("Player-1 wins!!! CONGRATULATIONS :)\n");
    else if (board[1][1] == p2)
        printf("Player-2 wins!!! CONGRATULATIONS :)\n");
    return 0;
    }
   return 1;
}

int draw() 
{
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<3; j++) 
        {
            if(board[i][j] == ' ') 
                return 1; 
        }
    }
    printf("Game draws!! No one wins :( :) \n"); 
    return 0; 
}

void playgame()
{
   printf("Entering playgame()\n");
   while(1)
   {
      int a,b;
      char c;
      printf("player - 1's turn : ");
      scanf("%d %d %c",&a, &b, &c);
      while(c!=p1)
      {
        printf("Invalid symbol. Player 1 must choose his/her symbol.\n");
        printf("player - 1's turn : ");
        scanf("%d %d %c",&a, &b, &c);
      }
      while(a>3 || b>3)
      {
        printf("Invalid place. There are only 3 rows and 3 coloumns in the game!!!\n");
        printf("player - 1's turn : ");
        scanf("%d %d %c",&a, &b, &c);
      }
      a--;
      b--;
      move(a, b, c);
      if(!gameover() || !draw())
      break;

      printf("player - 2's turn : ");
      scanf("%d %d %c",&a, &b, &c);
      while(c!=p2)
      {
        printf("Invalid symbol. Player 2 must choose his/her symbol.\n");
        printf("player - 2's turn : ");
        scanf("%d %d %c",&a, &b, &c);
      }
      while(a>3 || b>3)
      {
        printf("Invalid place. There are only 3 rows and 3 coloumns in the game!!!\n");
        printf("player - 2's turn : ");
        scanf("%d %d %c",&a, &b, &c);
      }
      a--;
      b--;
      move(a, b, c);
      if(!gameover() || !draw())
      break;
   }
}


int main() {
    printf("Player 1, choose your symbol (X or O): ");
    scanf(" %c", &p1);
    if (p1 != 'X' && p1 != 'O')
    {
        printf("Invalid symbol. Player 1 must choose either 'X' or 'O'.\n");
        printf("Player 1, choose your symbol (X or O): ");
        scanf(" %c", &p1);
    }
    p2 = (p1 == 'X') ? 'O' : 'X';

    initializeboard();
    printboard();
    playgame();
    return 0;
}