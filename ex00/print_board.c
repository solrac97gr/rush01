#include <stdio.h>

void ft_print_board(int **board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}