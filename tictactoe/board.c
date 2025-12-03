#include "board.h"

#include <stdio.h>
#include <string.h>

void board_init(Board *board) {
    if (!board) {
        return;
    }
    memset(board->cells, ' ', sizeof(board->cells));
}

bool board_place(Board *board, int row, int col, char marker) {
    if (!board || row < 0 || col < 0 || row >= BOARD_DIM || col >= BOARD_DIM) {
        return false;
    }
    int index = row * BOARD_DIM + col;
    if (board->cells[index] != ' ') {
        return false;
    }
    board->cells[index] = marker;
    return true;
}

bool board_is_full(const Board *board) {
    if (!board) {
        return false;
    }
    for (int i = 0; i < BOARD_CELLS; ++i) {
        if (board->cells[i] == ' ') {
            return false;
        }
    }
    return true;
}

static bool winning_line(const Board *board, int start, int step) {
    char first = board->cells[start];
    if (first == ' ') {
        return false;
    }
    for (int i = 1; i < BOARD_DIM; ++i) {
        if (board->cells[start + step * i] != first) {
            return false;
        }
    }
    return true;
}

char board_winner(const Board *board) {
    if (!board) {
        return ' ';
    }
    for (int row = 0; row < BOARD_DIM; ++row) {
        if (winning_line(board, row * BOARD_DIM, 1)) {
            return board->cells[row * BOARD_DIM];
        }
    }
    for (int col = 0; col < BOARD_DIM; ++col) {
        if (winning_line(board, col, BOARD_DIM)) {
            return board->cells[col];
        }
    }
    if (winning_line(board, 0, BOARD_DIM + 1)) {
        return board->cells[0];
    }
    if (winning_line(board, BOARD_DIM - 1, BOARD_DIM - 1)) {
        return board->cells[BOARD_DIM - 1];
    }
    return ' ';
}

void board_print(const Board *board) {
    if (!board) {
        return;
    }
    puts("  0 1 2");
    for (int row = 0; row < BOARD_DIM; ++row) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_DIM; ++col) {
            int idx = row * BOARD_DIM + col;
            printf("%c", board->cells[idx]);
            if (col < BOARD_DIM - 1) {
                printf("|");
            }
        }
        putchar('\n');
        if (row < BOARD_DIM - 1) {
            puts("  -----");
        }
    }
}

