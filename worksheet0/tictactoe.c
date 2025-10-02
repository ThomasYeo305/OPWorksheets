#include <stdio.h>

#define SIZE 3 // Will be used to set size as 3 by 3

// Function prototypes
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);

int main(void) {

    // Setting up variables
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col, moves = 0;
    char player = 'X';

    while (1) {
        printBoard(board);

        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move, try again!\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(board)) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        } else if (moves == SIZE * SIZE) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }
        // Switches Player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Prints board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

// Checks if there is a winner
int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        // Checks rows
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        // Checks columns
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Checks diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}
