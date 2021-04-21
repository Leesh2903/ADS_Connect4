#include <stdio.h>
#include <stdlib.h>


//function prototypes for program to run methods correctly
void initialise (char gameB[6][7]);
void print_game (char gameB[6][7]);
void player_turn (char gameB[6][7], char player);

//====================================//
int checkVerticalO (char gameB[6][7]);
int checkVerticalX (char gameB[6][7]);
int checkHorizonO (char gameB[6][7]);
int checkHorizonX (char gameB[6][7]);
int checkDiagonalX(char gameB[6][7]);
int checkDiagonalO(char gameB[6][7]);
//====================================//


int main()
{
    //declares variable to start or exit the game
    char startexit;

    //asks user whether he wishes to start the game or not by printing message to the terminal
    printf("\nThis is my ADS Connect 4 Project, the aim of the game is to match 4 pieces in a row \nhorizontally, diagonally or vertically \n");
    printf("\nWould you like to continue? Enter any Character on your keyboard to start or N to exit.\n");
    printf("Enter Now:");
    //terminal checks user input using scanf
    scanf("%c", &startexit);

    //if user enters n or N the program will exit else program will continue to run 
    while (startexit == 'n' || startexit == 'N')
    {
        printf("Goodbye!");
        exit(0);
    }


    //declares variables for player 1, player 2, game board, turn and game
    //2d array is used to store the game board
    char gameB[6][7]; 
    char player_1='X', player_2='O';
    int turn=0, game=0;

    // used to initialise game board, calls upon intialise method to do this 
    initialise(gameB);

    // game loops to take user inputs 
    while (game==0)
    {
        //if statement used to determine whos turn it is, player 1 will always be even, player 2 will always be odd 
        if(turn%2==0)
        {
            //calls upon player_turn method to allow player 1 to take their turn
            player_turn(gameB, player_1, game);
        }
        else 
        {
            //calls upon player_turn method to allow player 2 to take their turn
            player_turn(gameB, player_2, game);
        }
        turn++;
    }
    return 0;

    
}
    //method used to initialise game board for game, 2d Array is used for the game board 
void initialise (char gameB[6][7])
{
    //declare variables x and y to be used to loop through 2d array (will loop to create a 7x6 game board)  (X and Y axis)
    int x,y; 

    //loops through 2d array to create columns for game
    for(y=5; y>=0; y--)
    {
        for(x=0; x<7; x++)
        {
            gameB[y][x]=NULL;
        }
    }
}

//method used to print the game board for users, 2d Array is used for the game board
void print_game (char gameB[6][7])
{
    //declare variables x and y to be used to loop through 2d array (will loop to create a 7x6 game board)  (X and Y axis)
    int x,y;

    //top of game board
    printf("---C-O-N-N-E-C-T-4---");
    //loops through 2d array to create columns for game 
    for(y=5; y>=0; y--)
    {
        printf("\n");//Next line of the board
        for(x=0; x<7; x++)
        {
            //printf("|") used to create visible columns on game board
            printf("|");
            printf("%c" ,gameB[y][x]); //prints the game board for user
            printf("|");
        }
    }
    //bottom of game board
    printf("\n---------------------");
}

//method used for players to take turns in game 
void player_turn (char gameB[6][7], char player)
{
    //declare variables 
    int y, x, game_column, turn=0;

    while(turn==0)
    {
        //asks user to pick a valid column
        printf("\nPlease select a column! (Valid columns: 1-7) \n");
        //receives user input
        scanf("%d", &game_column);
        //while used to ensure valid column was entered
        while(game_column<1||game_column>7)
        {
            //sends message to terminal that input is invalid, user then can input again using scanf
            printf("Input Invalid, please enter another!.\n");
            scanf("%d", &game_column);
        }
        //Checking to see if that column is full or not 
        game_column--; 
        //if column is full then message sent to user terminal 
        if(gameB[5][game_column]!=NULL)
        {
            printf("That column is full. Please choose another.\n");
            turn=0;
            break;
        }

        //checks the column to find the first empty spot 
        for(y=0; y<6; y++)
        {
            //if space empty / has space for a new counter it will allow player to put counter there
            if(gameB[y][game_column]==NULL)
            {
                gameB[y][game_column]=player;
                //turn=1; used to end players turn, allows next player to begin turn
                turn=1;
                //prints game board, this will now show where the user has put his game piece
                print_game(gameB);
                //uses win checker methods, if return=1; then will send winner message and exit the program
                if(checkVerticalO(gameB)==1)
                {
                    printf("\n\nCongratulations Player %c , you win ADS Connect 4!\n", player);
                    exit(0);
                } 
                else if(checkVerticalX(gameB)==1)
                {
                    printf("\n\nCongratulations Player %c , you win ADS Connect 4!\n", player);
                    exit(0);
                }
                else if(checkHorizonO(gameB)==1)
                {
                    printf("\n\nCongratulations Player %c , you win ADS Connect 4!\n", player);
                    exit(0);
                }
                else if(checkHorizonX(gameB)==1)
                {
                    printf("\n\nCongratulations Player %c , you win ADS Connect 4!\n", player);
                    exit(0);
                }
                else if(checkDiagonalO(gameB)==1)
                {
                    printf("\n\nCongratulations Player %c , you win ADS Connect 4!\n", player);
                    exit(0);
                }
                else if(checkDiagonalX(gameB)==1)
                {
                    printf("\n\nCongratulations Player %c , you win ADS Connect 4!\n", player);
                    exit(0);
                }
                break;
            }
        }
    }
}

//======================================================================================================================================//

//VERTICAL O
//used to check all possible win conditions for vertical O, I understand this is an inefficient way of checking my win condition and will discuss this further within my report
int checkVerticalO(char gameB[6][7])
{
    if (gameB[0][0] == 'O' && gameB[1][0] == 'O' && gameB[2][0] == 'O' && gameB[3][0] == 'O' || gameB[1][0] == 'O' && gameB[2][0] == 'O' && gameB[3][0] == 'O' && gameB[4][0] == 'O' ||
    gameB[2][0] == 'O' && gameB[3][0] == 'O' && gameB[4][0] == 'O' && gameB[5][0] == 'O' || gameB[0][1] == 'O' && gameB[1][1] == 'O' && gameB[2][1] == 'O' && gameB[3][1] == 'O' || 
    gameB[1][1] == 'O' && gameB[2][1] == 'O' && gameB[3][1] == 'O' && gameB[4][1] == 'O' || gameB[2][1] == 'O' && gameB[3][1] == 'O' && gameB[4][1] == 'O' && gameB[5][1] == 'O' || 
    gameB[0][2] == 'O' && gameB[1][2] == 'O' && gameB[2][2] == 'O' && gameB[3][2] == 'O' || gameB[1][2] == 'O' && gameB[2][2] == 'O' && gameB[3][2] == 'O' && gameB[4][2] == 'O' ||
    gameB[2][2] == 'O' && gameB[3][2] == 'O' && gameB[4][2] == 'O' && gameB[5][2] == 'O' || gameB[0][3] == 'O' && gameB[1][3] == 'O' && gameB[2][3] == 'O' && gameB[3][3] == 'O' || 
    gameB[1][3] == 'O' && gameB[2][3] == 'O' && gameB[3][3] == 'O' && gameB[4][3] == 'O' || gameB[2][3] == 'O' && gameB[3][3] == 'O' && gameB[4][3] == 'O' && gameB[5][3] == 'O' ||
    gameB[0][4] == 'O' && gameB[1][4] == 'O' && gameB[2][4] == 'O' && gameB[3][4] == 'O' || gameB[1][4] == 'O' && gameB[2][4] == 'O' && gameB[3][4] == 'O' && gameB[4][4] == 'O' ||
    gameB[2][4] == 'O' && gameB[3][4] == 'O' && gameB[4][4] == 'O' && gameB[5][4] == 'O' || gameB[0][5] == 'O' && gameB[1][5] == 'O' && gameB[2][5] == 'O' && gameB[3][5] == 'O' || 
    gameB[1][5] == 'O' && gameB[2][5] == 'O' && gameB[3][5] == 'O' && gameB[4][5] == 'O' || gameB[2][5] == 'O' && gameB[3][5] == 'O' && gameB[4][5] == 'O' && gameB[5][5] == 'O' ||
    gameB[0][6] == 'O' && gameB[1][6] == 'O' && gameB[2][6] == 'O' && gameB[3][6] == 'O' || gameB[1][6] == 'O' && gameB[2][6] == 'O' && gameB[3][6] == 'O' && gameB[4][6] == 'O'||
    gameB[2][6] == 'O' && gameB[3][6] == 'O' && gameB[4][6] == 'O' && gameB[5][6] == 'O')
    {
        return 1;
    }
    return 0;
}

//======================================================================================================================================//

//VERTICAL X
//used to check all possible win conditions for vertical X, I understand this is an inefficient way of checking my win condition and will discuss this further within my report
int checkVerticalX(char gameB[6][7])
{
    if (gameB[0][0] == 'X' && gameB[1][0] == 'X' && gameB[2][0] == 'X' && gameB[3][0] == 'X' || gameB[1][0] == 'X' && gameB[2][0] == 'X' && gameB[3][0] == 'X' && gameB[4][0] == 'X' ||
    gameB[2][0] == 'X' && gameB[3][0] == 'X' && gameB[4][0] == 'X' && gameB[5][0] == 'X' || gameB[0][1] == 'X' && gameB[1][1] == 'X' && gameB[2][1] == 'X' && gameB[3][1] == 'X' || 
    gameB[1][1] == 'X' && gameB[2][1] == 'X' && gameB[3][1] == 'X' && gameB[4][1] == 'X' || gameB[2][1] == 'X' && gameB[3][1] == 'X' && gameB[4][1] == 'X' && gameB[5][1] == 'X' || 
    gameB[0][2] == 'X' && gameB[1][2] == 'X' && gameB[2][2] == 'X' && gameB[3][2] == 'X' || gameB[1][2] == 'X' && gameB[2][2] == 'X' && gameB[3][2] == 'X' && gameB[4][2] == 'X' ||
    gameB[2][2] == 'X' && gameB[3][2] == 'X' && gameB[4][2] == 'X' && gameB[5][2] == 'X' || gameB[0][3] == 'X' && gameB[1][3] == 'X' && gameB[2][3] == 'X' && gameB[3][3] == 'X' || 
    gameB[1][3] == 'X' && gameB[2][3] == 'X' && gameB[3][3] == 'X' && gameB[4][3] == 'X' || gameB[2][3] == 'X' && gameB[3][3] == 'X' && gameB[4][3] == 'X' && gameB[5][3] == 'X' ||
    gameB[0][4] == 'X' && gameB[1][4] == 'X' && gameB[2][4] == 'X' && gameB[3][4] == 'X' || gameB[1][4] == 'X' && gameB[2][4] == 'X' && gameB[3][4] == 'X' && gameB[4][4] == 'X' ||
    gameB[2][4] == 'X' && gameB[3][4] == 'X' && gameB[4][4] == 'X' && gameB[5][4] == 'X' || gameB[0][5] == 'X' && gameB[1][5] == 'X' && gameB[2][5] == 'X' && gameB[3][5] == 'X' || 
    gameB[1][5] == 'X' && gameB[2][5] == 'X' && gameB[3][5] == 'X' && gameB[4][5] == 'X' || gameB[2][5] == 'X' && gameB[3][5] == 'X' && gameB[4][5] == 'X' && gameB[5][5] == 'X' ||
    gameB[0][6] == 'X' && gameB[1][6] == 'X' && gameB[2][6] == 'X' && gameB[3][6] == 'X' || gameB[1][6] == 'X' && gameB[2][6] == 'X' && gameB[3][6] == 'X' && gameB[4][6] == 'X'||
    gameB[2][6] == 'X' && gameB[3][6] == 'X' && gameB[4][6] == 'X' && gameB[5][6] == 'X')
    {
        return 1;
    }
    return 0;
}

//======================================================================================================================================//

//HORIZONTAL O
//used to check all possible win conditions for horizontal O, I understand this is an inefficient way of checking my win condition and will discuss this further within my report
int checkHorizonO(char gameB[6][7])
{
     if (gameB[0][0] == 'O' && gameB[0][1] == 'O' && gameB[0][2] == 'O' && gameB[0][3] == 'O' || gameB[0][1] == 'O' && gameB[0][2] == 'O' && gameB[0][3] == 'O' && gameB[0][4] == 'O' ||
    gameB[0][2] == 'O' && gameB[0][3] == 'O' && gameB[0][4] == 'O' && gameB[0][5] == 'O' || gameB[0][3] == 'O' && gameB[0][4] == 'O' && gameB[0][5] == 'O' && gameB[0][6] == 'O' ||
    gameB[1][0] == 'O' && gameB[1][1] == 'O' && gameB[1][2] == 'O' && gameB[1][3] == 'O' || gameB[1][1] == 'O' && gameB[1][2] == 'O' && gameB[1][3] == 'O' && gameB[1][4] == 'O' ||
    gameB[1][2] == 'O' && gameB[1][3] == 'O' && gameB[1][4] == 'O' && gameB[1][5] == 'O' || gameB[1][3] == 'O' && gameB[1][4] == 'O' && gameB[1][5] == 'O' && gameB[1][6] == 'O' ||
    gameB[2][0] == 'O' && gameB[2][1] == 'O' && gameB[2][2] == 'O' && gameB[2][3] == 'O' || gameB[2][1] == 'O' && gameB[2][2] == 'O' && gameB[2][3] == 'O' && gameB[2][4] == 'O' ||
    gameB[2][2] == 'O' && gameB[2][3] == 'O' && gameB[2][4] == 'O' && gameB[2][5] == 'O' || gameB[2][3] == 'O' && gameB[2][4] == 'O' && gameB[2][5] == 'O' && gameB[2][6] == 'O' ||
    gameB[3][0] == 'O' && gameB[3][1] == 'O' && gameB[3][2] == 'O' && gameB[3][3] == 'O' || gameB[3][1] == 'O' && gameB[3][2] == 'O' && gameB[3][3] == 'O' && gameB[3][4] == 'O' ||
    gameB[3][2] == 'O' && gameB[3][3] == 'O' && gameB[3][4] == 'O' && gameB[3][5] == 'O' || gameB[3][3] == 'O' && gameB[3][4] == 'O' && gameB[3][5] == 'O' && gameB[3][6] == 'O' ||
    gameB[4][0] == 'O' && gameB[4][1] == 'O' && gameB[4][2] == 'O' && gameB[4][3] == 'O' || gameB[4][1] == 'O' && gameB[4][2] == 'O' && gameB[4][3] == 'O' && gameB[4][4] == 'O' ||
    gameB[4][2] == 'O' && gameB[4][3] == 'O' && gameB[4][4] == 'O' && gameB[4][5] == 'O' || gameB[4][3] == 'O' && gameB[4][4] == 'O' && gameB[4][5] == 'O' && gameB[4][6] == 'O' ||
    gameB[5][0] == 'O' && gameB[5][1] == 'O' && gameB[5][2] == 'O' && gameB[5][3] == 'O' || gameB[5][1] == 'O' && gameB[5][2] == 'O' && gameB[5][3] == 'O' && gameB[5][4] == 'O' ||
    gameB[5][2] == 'O' && gameB[5][3] == 'O' && gameB[5][4] == 'O' && gameB[5][5] == 'O' || gameB[5][3] == 'O' && gameB[5][4] == 'O' && gameB[5][5] == 'O' && gameB[5][6] == 'O' )
    {
        return 1;
    }
    return 0;
}

//======================================================================================================================================//

//HORIZONTAL X
//used to check all possible win conditions for horizontal X, I understand this is an inefficient way of checking my win condition and will discuss this further within my report
int checkHorizonX(char gameB[6][7])
{
     if (gameB[0][0] == 'X' && gameB[0][1] == 'X' && gameB[0][2] == 'X' && gameB[0][3] == 'X' || gameB[0][1] == 'X' && gameB[0][2] == 'X' && gameB[0][3] == 'X' && gameB[0][4] == 'X' ||
    gameB[0][2] == 'X' && gameB[0][3] == 'X' && gameB[0][4] == 'X' && gameB[0][5] == 'X' || gameB[0][3] == 'X' && gameB[0][4] == 'X' && gameB[0][5] == 'X' && gameB[0][6] == 'X' ||
    gameB[1][0] == 'X' && gameB[1][1] == 'X' && gameB[1][2] == 'X' && gameB[1][3] == 'X' || gameB[1][1] == 'X' && gameB[1][2] == 'X' && gameB[1][3] == 'X' && gameB[1][4] == 'X' ||
    gameB[1][2] == 'X' && gameB[1][3] == 'X' && gameB[1][4] == 'X' && gameB[1][5] == 'X' || gameB[1][3] == 'X' && gameB[1][4] == 'X' && gameB[1][5] == 'X' && gameB[1][6] == 'X' ||
    gameB[2][0] == 'X' && gameB[2][1] == 'X' && gameB[2][2] == 'X' && gameB[2][3] == 'X' || gameB[2][1] == 'X' && gameB[2][2] == 'X' && gameB[2][3] == 'X' && gameB[2][4] == 'X' ||
    gameB[2][2] == 'X' && gameB[2][3] == 'X' && gameB[2][4] == 'X' && gameB[2][5] == 'X' || gameB[2][3] == 'X' && gameB[2][4] == 'X' && gameB[2][5] == 'X' && gameB[2][6] == 'X' ||
    gameB[3][0] == 'X' && gameB[3][1] == 'X' && gameB[3][2] == 'X' && gameB[3][3] == 'X' || gameB[3][1] == 'X' && gameB[3][2] == 'X' && gameB[3][3] == 'X' && gameB[3][4] == 'X' ||
    gameB[3][2] == 'X' && gameB[3][3] == 'X' && gameB[3][4] == 'X' && gameB[3][5] == 'X' || gameB[3][3] == 'X' && gameB[3][4] == 'X' && gameB[3][5] == 'X' && gameB[3][6] == 'X' ||
    gameB[4][0] == 'X' && gameB[4][1] == 'X' && gameB[4][2] == 'X' && gameB[4][3] == 'X' || gameB[4][1] == 'X' && gameB[4][2] == 'X' && gameB[4][3] == 'X' && gameB[4][4] == 'X' ||
    gameB[4][2] == 'X' && gameB[4][3] == 'X' && gameB[4][4] == 'X' && gameB[4][5] == 'X' || gameB[4][3] == 'X' && gameB[4][4] == 'X' && gameB[4][5] == 'X' && gameB[4][6] == 'X' ||
    gameB[5][0] == 'X' && gameB[5][1] == 'X' && gameB[5][2] == 'X' && gameB[5][3] == 'X' || gameB[5][1] == 'X' && gameB[5][2] == 'X' && gameB[5][3] == 'X' && gameB[5][4] == 'X' ||
    gameB[5][2] == 'X' && gameB[5][3] == 'X' && gameB[5][4] == 'X' && gameB[5][5] == 'X' || gameB[5][3] == 'X' && gameB[5][4] == 'X' && gameB[5][5] == 'X' && gameB[5][6] == 'X' )
    {
        return 1;
    }
    return 0;
}

//======================================================================================================================================//

//DIAGONAL X
//used to check all possible win conditions, I understand this is an inefficient way of checking my win condition and will discuss this further within my report

//diagonal 
 int checkDiagonalX(char gameB[6][7]){
    if (gameB[2][0] == 'X' && gameB[3][1] == 'X' && gameB[4][2] == 'X' && gameB[5][3] == 'X'|| gameB[1][0] == 'X' && gameB[2][1] == 'X' && gameB[3][2] == 'X' && gameB[4][3] == 'X'||
    gameB[0][0] == 'X' && gameB[1][1] == 'X' && gameB[2][2] == 'X' && gameB[3][3] == 'X'|| gameB[0][1] == 'X' && gameB[1][2] == 'X' && gameB[2][3] == 'X' && gameB[3][4] == 'X'||
    gameB[1][1] == 'X' && gameB[2][2] == 'X' && gameB[3][3] == 'X' && gameB[4][4] == 'X'|| gameB[2][1] == 'X' && gameB[3][2] == 'X' && gameB[4][3] == 'X' && gameB[5][4] == 'X'||
    gameB[0][2] == 'X' && gameB[1][3] == 'X' && gameB[2][4] == 'X' && gameB[3][5] == 'X'|| gameB[1][2] == 'X' && gameB[2][3] == 'X' && gameB[3][4] == 'X' && gameB[4][5] == 'X'||
    gameB[2][2] == 'X' && gameB[3][3] == 'X' && gameB[4][4] == 'X' && gameB[5][5] == 'X'|| gameB[0][3] == 'X' && gameB[1][4] == 'X' && gameB[2][5] == 'X' && gameB[3][6] == 'X'||
    gameB[1][3] == 'X' && gameB[2][4] == 'X' && gameB[3][5] == 'X' && gameB[4][6] == 'X'|| gameB[2][3] == 'X' && gameB[3][4] == 'X' && gameB[4][5] == 'X' && gameB[5][6] == 'X')
    {
        return 1;
    }
//anti diagonal 
    else if (gameB[3][0] == 'X' && gameB[2][1] == 'X' && gameB[1][2] == 'X' && gameB[0][3] == 'X'|| gameB[4][0] == 'X' && gameB[3][1] == 'X' && gameB[2][2] == 'X' && gameB[1][3] == 'X'||
    gameB[3][1] == 'X' && gameB[2][2] == 'X' && gameB[1][3] == 'X' && gameB[0][4] == 'X'|| gameB[5][0] == 'X' && gameB[4][1] == 'X' && gameB[3][2] == 'X' && gameB[2][3] == 'X'||        
    gameB[4][1] == 'X' && gameB[3][2] == 'X' && gameB[2][3] == 'X' && gameB[1][4] == 'X'|| gameB[3][2] == 'X' && gameB[2][2] == 'X' && gameB[1][4] == 'X' && gameB[0][5] == 'X'||
    gameB[5][1] == 'X' && gameB[4][2] == 'X' && gameB[3][3] == 'X' && gameB[2][4] == 'X'|| gameB[4][2] == 'X' && gameB[3][3] == 'X' && gameB[2][4] == 'X' && gameB[1][5] == 'X'||
    gameB[3][3] == 'X' && gameB[2][4] == 'X' && gameB[1][5] == 'X' && gameB[0][6] == 'X'|| gameB[5][2] == 'X' && gameB[4][3] == 'X' && gameB[3][4] == 'X' && gameB[2][5] == 'X'||
    gameB[4][3] == 'X' && gameB[3][4] == 'X' && gameB[2][5] == 'X' && gameB[1][6] == 'X'|| gameB[5][3] == 'X' && gameB[4][4] == 'X' && gameB[3][5] == 'X' && gameB[2][6] == 'X')
    {
        return 1;
    }
    return 0;
}

//======================================================================================================================================//

//DIAGONAL O
//used to check all possible win conditions, I understand this is an inefficient way of checking my win condition and will discuss this further within my report

//diagonal 
int checkDiagonalO(char gameB[6][7]){
    if (gameB[2][0] == 'O' && gameB[3][1] == 'O' && gameB[4][2] == 'O' && gameB[5][3] == 'O'|| gameB[1][0] == 'O' && gameB[2][1] == 'O' && gameB[3][2] == 'O' && gameB[4][3] == 'O'||
    gameB[0][0] == 'O' && gameB[1][1] == 'O' && gameB[2][2] == 'O' && gameB[3][3] == 'O'|| gameB[0][1] == 'O' && gameB[1][2] == 'O' && gameB[2][3] == 'O' && gameB[3][4] == 'O'||
    gameB[1][1] == 'O' && gameB[2][2] == 'O' && gameB[3][3] == 'O' && gameB[4][4] == 'O'|| gameB[2][1] == 'O' && gameB[3][2] == 'O' && gameB[4][3] == 'O' && gameB[5][4] == 'O'||
    gameB[0][2] == 'O' && gameB[1][3] == 'O' && gameB[2][4] == 'O' && gameB[3][5] == 'O'|| gameB[1][2] == 'O' && gameB[2][3] == 'O' && gameB[3][4] == 'O' && gameB[4][5] == 'O'||
    gameB[2][2] == 'O' && gameB[3][3] == 'O' && gameB[4][4] == 'O' && gameB[5][5] == 'O'|| gameB[0][3] == 'O' && gameB[1][4] == 'O' && gameB[2][5] == 'O' && gameB[3][6] == 'O'||
    gameB[1][3] == 'O' && gameB[2][4] == 'O' && gameB[3][5] == 'O' && gameB[4][6] == 'O'|| gameB[2][3] == 'O' && gameB[3][4] == 'O' && gameB[4][5] == 'O' && gameB[5][6] == 'O')
    {
        return 1;
    }
//anti diagonal
    else if (gameB[3][0] == 'O' && gameB[2][1] == 'O' && gameB[1][2] == 'O' && gameB[0][3] == 'O'|| gameB[4][0] == 'O' && gameB[3][1] == 'O' && gameB[2][2] == 'O' && gameB[1][3] == 'O'||
    gameB[3][1] == 'O' && gameB[2][2] == 'O' && gameB[1][3] == 'O' && gameB[0][4] == 'O'|| gameB[5][0] == 'O' && gameB[4][1] == 'O' && gameB[3][2] == 'O' && gameB[2][3] == 'O'||        
    gameB[4][1] == 'O' && gameB[3][2] == 'O' && gameB[2][3] == 'O' && gameB[1][4] == 'O'|| gameB[3][2] == 'O' && gameB[2][2] == 'O' && gameB[1][4] == 'O' && gameB[0][5] == 'O'||
    gameB[5][1] == 'O' && gameB[4][2] == 'O' && gameB[3][3] == 'O' && gameB[2][4] == 'O'|| gameB[4][2] == 'O' && gameB[3][3] == 'O' && gameB[2][4] == 'O' && gameB[1][5] == 'O'||
    gameB[3][3] == 'O' && gameB[2][4] == 'O' && gameB[1][5] == 'O' && gameB[0][6] == 'O'|| gameB[5][2] == 'O' && gameB[4][3] == 'O' && gameB[3][4] == 'O' && gameB[2][5] == 'O'||
    gameB[4][3] == 'O' && gameB[3][4] == 'O' && gameB[2][5] == 'O' && gameB[1][6] == 'O'|| gameB[5][3] == 'O' && gameB[4][4] == 'O' && gameB[3][5] == 'O' && gameB[2][6] == 'O')
    {
        return 1;
    }
    return 0;
}





//sources which helped give me ideas to create final program



//http://www.cplusplus.com/forum/beginner/102634/ 

//https://codereview.stackexchange.com/questions/27446/connect-four-game  

//https://beginnersbook.com/2014/01/2d-arrays-in-c-example/?fbclid=IwAR2kPkY-lBQmLwaADITChQInyAr-TYw3IFhT4tY-9NjLjN3bAVAXmR7ze50
