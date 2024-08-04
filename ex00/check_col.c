// Description: Check if the value is in the column.
int ft_check_col(int **board, int col, int value)
{
    int i = 0;
    while (i < 4)
    {
        if (board[i][col] == value)
        {
            return 0;
        }
        i++;
    }
    return 1;
}