#include <stdlib.h>

void ft_free_board(int **board)
{
    int i;

    i = 0;
    while (i < 4)
    {
        free(board[i]);
        i++;
    }
    free(board);
}