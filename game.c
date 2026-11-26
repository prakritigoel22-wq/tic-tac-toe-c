#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void showBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    
    return 0;
}

int main() {
    int choice, row, col;
    char player = 'X';
    int turns = 0;

    while (turns < 9) {
        showBoard();
        printf("Player %c, enter a number (1-9): ", player);
        scanf("%d", &choice);

        // convert 1-9 into row and col
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // check if move is valid
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = player;
        turns++;

        if (checkWin()) {
            showBoard();
            printf("Player %c wins!\n", player);
            return 0;
        }

        // switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    showBoard();
    printf("It's a draw!\n");
    return 0;
}