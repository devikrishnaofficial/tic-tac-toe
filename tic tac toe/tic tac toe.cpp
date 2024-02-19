#include <stdio.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to check if the game is over (win or draw)
int gameOver(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    // Check for draw
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                draw = 0;
        }
    }
    if (draw)
        return 2;
    return 0;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int row, col, currentPlayer = 1;
    char mark;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while (1) {
        printBoard(board);
        currentPlayer = (currentPlayer % 2) ? 1 : 2;

        printf("Player %d, enter row (1-3) and column (1-3) to place your mark: ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Adjust indices
        row--;
        col--;

        // Check if the cell is empty
        if (board[row][col] == ' ') {
            mark = (currentPlayer == 1) ? 'X' : 'O';
            board[row][col] = mark;

            // Check if the game is over
            if (gameOver(board, mark) == 1) {
                printBoard(board);
                printf("Player %d wins!\n", currentPlayer);
                break;
            } else if (gameOver(board, mark) == 2) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch player
            currentPlayer++;
        } else {
            printf("Cell already occupied. Please try again.\n");
        }
    }

    return 0;
}

