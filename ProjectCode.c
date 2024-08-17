//
// main.c
// c program
//
// Created by Jatin Gupta on 07/05/21.
/*
* ENGG1110 Problem Solving by Programming
*
* Course Project
*
* I declare that the project here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* https://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name :Jatin Gupta
* Student ID :1155172419
* Class/Section :ENGG1110A
* Date :18/11/2021
*/
#include <stdio.h>
/* NO other header files are allowed */
/* NO global variables are allowed */
/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2
/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {
 // TODO : Complete this part
 int i,j;
 for (i=0;i<6;i++){
 for (j=0;j<7;j++){
 gameBoard[i][j]=EMPTY;
 }
 }
}
/* Display the game board on the screen.
 You are required to exactly follow the output format stated in the project specification.
 IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {
 // TODO : Complete this part
 int i,j;
 for (i=0;i<6;i++){
 for (j=0;j<7;j++){
 if (gameBoard[i][j]!=EMPTY){
 if (gameBoard[i][j]==CIRCLE){
 printf("|O");
 }
 if (gameBoard[i][j]==CROSS){
 printf("|X");
 }
 }
 else{
 printf("| ");
 }
 }
 printf("|");
 printf("\n");
}
 printf(" 1 2 3 4 5 6 7\n");
}
/* Ask the human player to place the mark.
 You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {
    int column, row, r = 0;
    scanf("%d", &column);
    while (column <= 0 || column > 7) {
        printf("Input out of range. Please input again:\n");
        scanf("%d", &column);
    }
    while (1) {
        r = 0;
        for (row = 5; row >= 0; row--) {
            if (gameBoard[row][column - 1] != EMPTY) {
                r++;
            }
        }
        if (r == 6) {
            printf("Column is full. Please input again:\n");
            scanf("%d", &column);
            while (column <= 0 || column > 7) {
                printf("Input out of range. Please input again:\n");
                scanf("%d", &column);
            }
        } else {
            break;
        }
    }
    for (row = 5; row >= 0; row--) {
        if (gameBoard[row][column - 1] == EMPTY) {
            gameBoard[row][column - 1] = mark;
            break;
        }
    }
}

/* Return 1 if there is a winner in the game, otherwise return 0.
 Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){
 // TODO : Complete this part
 int i,j,eh=0,h,ed1=0,ev=0,ed2=0;
 for (i=5;i>2;i--){
 for (j=0;j<4;j++){
 if (gameBoard[i][j]!=EMPTY){
 for (h=0;h<4;h++){
 if (gameBoard[i][j]==gameBoard[i][j+h]){
 eh++;
 if (eh==4){
 return 1;
 }
 }
 if (gameBoard[i][j]==gameBoard[i-h][j]){
 ev++;
 if (ev==4){
 return 1;
 }
 }
 }
 }
 eh=ev=0;
 }
 }
 for (i=2;i>=0;i--){
 for (j=3;j<7;j++){
 if (gameBoard[i][j]!=EMPTY){
 for (h=0;h<4;h++){
 if (gameBoard[i][j]==gameBoard[i+h][j]){
 ev++;
 if (ev==4){
 return 1;
 }
 }
 }
 }
 eh=ev=0;
 }
 }
 for (i=5;i>=0;i--){
 for (j=6;j>=0;j--){
 if (gameBoard[i][j]!=EMPTY){
 if (i>2){
 if (j<4){
 for (h=0;h<4;h++){
 if (gameBoard[i][j]==gameBoard[i-h][j+h]){
 ed1++;
 if (ed1==4){
 return 1;
 }
 }
 }
 ed1=0;
 }
 if (j>=3){
 for (h=0;h<4;h++){
 if (gameBoard[i][j]==gameBoard[i-h][j-h]){
 ed1++;
 if (ed1==4){
 return 1;
 }
 }
 }
 ed1=0;
 }
 }
 if (i<3){
 if (j<4){
 for (h=0;h<4;h++){
 if (gameBoard[i][j]==gameBoard[i+h][j+h]){
 ed2++;
 if (ed2==4){
 return 1;
 }
 }
 }
 ed2=0;
 }
 if (j>2){
 for (h=0;h<4;h++){
 if (gameBoard[i][j]==gameBoard[i+h][j-h]){
 ed2++;
 if (ed2==4){
 return 1;
 }
 }
 }
 ed2=0;
 }
 }
 }
 }
 }
 return 0;
}
/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {
 // TODO : Complete this part
 int i,j,s=0,b=0;
 for (i=0;i<6;i++){
 for (j=0;j<7;j++){
 if (gameBoard[i][j]!=EMPTY){
 s++;
 }
 if (gameBoard[i][j]==EMPTY){
 break;
 }
 }
 b=b+s;
 if (s!=7){
 break;
 }
 s=0;
 }
 if (b==42){
 return 1;
 }
 else{
 return 0;
 }
}
/* Determine the next move of the computer player.
 You are required to exactly follow the strategy mentioned in the project specification.
 Using other strategies will result in mark deduction. */
// TODO : Write the placeMarkByComputerPlayer(...) function here

void placeMarkByComputerPlayer(int gameBoard[6][7]) {
    int row, col, chk = 0;

    // First, try to win
    for (col = 0; col < 7; col++) {
        for (row = 5; row >= 0; row--) {
            if (gameBoard[row][col] == EMPTY) {
                gameBoard[row][col] = CROSS;
                if (hasWinner(gameBoard)) {
                    return;
                }
                gameBoard[row][col] = EMPTY;
                break;
            }
        }
    }

    // Then, try to block the human player
    for (col = 0; col < 7; col++) {
        for (row = 5; row >= 0; row--) {
            if (gameBoard[row][col] == EMPTY) {
                gameBoard[row][col] = CIRCLE;
                if (hasWinner(gameBoard)) {
                    gameBoard[row][col] = CROSS;
                    return;
                }
                gameBoard[row][col] = EMPTY;
                break;
            }
        }
    }

    // If no winning or blocking move, place in the leftmost available column
    for (col = 0; col < 7; col++) {
        for (row = 5; row >= 0; row--) {
            if (gameBoard[row][col] == EMPTY) {
                gameBoard[row][col] = CROSS;
                return;
            }
        }
    }
}
/* The main function */
int main()
{
 /* Local variables */
 int gameBoard[6][7]; // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
 int currentPlayer; // 1: Player 1 2: Player 2
 int gameContinue; // 1: The game continues 0: The game ends
 int numOfHumanPlayers; // 1 or 2
 /* Initialize the local variables */
 initGameBoard(gameBoard);
 currentPlayer = 1;
 gameContinue = 1;
 printf("Enter the number of human players [1-2]:\n");
 scanf("%d", &numOfHumanPlayers); // You can assume that the user input must be valid
 /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
 are implemented correctly.
 You can add more if you wish.
 After testing, you can delete them or move them elsewhere. */
 //printGameBoard(gameBoard);
 //printf("Player 1's turn:\n");
 //placeMarkByHumanPlayer(gameBoard, CIRCLE);
 //printGameBoard(gameBoard);
 //printf("Player 2's turn:\n");
 //placeMarkByHumanPlayer(gameBoard, CROSS);
 //printGameBoard(gameBoard);
 /* Game start
 If there are two human players, they are Player 1 and Player 2
 If there is only one human player, he/she is Player 1 and another player is the computer player
 For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
 Hint: use a while loop */
 // TODO : Complete this part
 printGameBoard(gameBoard);
    while (gameContinue == 1) {
        if (numOfHumanPlayers == 2) {
            printf("Player %d's turn:\n", currentPlayer);
            placeMarkByHumanPlayer(gameBoard, currentPlayer == 1 ? CIRCLE : CROSS);
        } else if (numOfHumanPlayers == 1) {
            if (currentPlayer == 1) {
                printf("Player 1's turn:\n");
                placeMarkByHumanPlayer(gameBoard, CIRCLE);
            } else {
                printf("Computer's turn:\n");
                placeMarkByComputerPlayer(gameBoard);
            }
        }

        printGameBoard(gameBoard);

        if (hasWinner(gameBoard)) {
            if (numOfHumanPlayers == 2) {
                printf("Congratulations! Player %d wins!\n", currentPlayer);
            } else if (currentPlayer == 1) {
                printf("Congratulations! Player 1 wins!\n");
            } else {
                printf("Computer wins!\n");
            }
            gameContinue = 0;
        } else if (isFull(gameBoard)) {
            printf("Draw game.\n");
            gameContinue = 0;
        } else {
            currentPlayer = 3 - currentPlayer; // Switch between 1 and 2
        }
    }

    return 0;
}