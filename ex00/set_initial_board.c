#include <stdlib.h>

// Description: Sets the initial board to all zeros.
/*
    [[0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]]
*/
void ft_set_initial_board(int ***board)
{
    int i;
    int j;

    *board = malloc(4 * sizeof(int *));
    i = 0;
    while (i < 4)
    {
        (*board)[i] = malloc(4 * sizeof(int));
        j = 0;
        while (j < 4)
        {
            (*board)[i][j] = 0;
            j++;
        }
        i++;
    }
}