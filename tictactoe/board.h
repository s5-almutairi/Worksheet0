#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define BOARD_DIM 3
#define BOARD_CELLS (BOARD_DIM * BOARD_DIM)

typedef struct {
    char cells[BOARD_CELLS];
} Board;

void board_init(Board *board);
bool board_place(Board *board, int row, int col, char marker);
bool board_is_full(const Board *board);
char board_winner(const Board *board);
void board_print(const Board *board);

#endif

