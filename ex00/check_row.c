// Description: Check if the value is in the row.
int ft_check_row(int **board, int row, int value)
{
    int i = 0;
    while (i < 4)
    {
        if (board[row][i] == value)
        {
            return 0;
        }
        i++;
    }
    return 1;
}