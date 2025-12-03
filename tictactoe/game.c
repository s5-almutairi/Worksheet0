#include "game.h"

#include <stdio.h>

#include "board.h"

static int read_move(int *row, int *col) {
    char buffer[32];
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 0;
    }
    return sscanf(buffer, "%d %d", row, col) == 2;
}

void run_game(void) {
    Board board;
    board_init(&board);
    char player = 'X';

    puts("TicTacToe – enter moves as: row col (0-based indices)\n");

    while (1) {
        board_print(&board);
        printf("Player %c move: ", player);
        int row = 0;
        int col = 0;
        if (!read_move(&row, &col)) {
            puts("Could not parse move; try again.");
            continue;
        }
        if (!board_place(&board, row, col, player)) {
            puts("Illegal move (out of range or already occupied). Try again.");
            continue;
        }

        char winner = board_winner(&board);
        if (winner != ' ') {
            board_print(&board);
            printf("Player %c wins!\n", winner);
            break;
        }
        if (board_is_full(&board)) {
            board_print(&board);
            puts("It's a draw.");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

