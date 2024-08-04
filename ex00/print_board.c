#include <unistd.h>

void ft_print_board(int **board)
{
    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4)
        {
            char c = board[i][j] + '0';
            write(1, &c, 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}