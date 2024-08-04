// Description: Check if the visibility is correct.
int ft_check_visibility(int **board, int *constraints)
{
    // Check column visibility from top
    int col = 0;
    while (col < 4)
    {
        int max = 0;
        int visible = 0;
        int row = 0;
        while (row < 4)
        {
            if (board[row][col] > max)
            {
                max = board[row][col];
                visible++;
            }
            row++;
        }
        if (visible > constraints[col] && constraints[col] != 0)
            return 0;
        col++;
    }

    // Check column visibility from bottom
    col = 0;
    while (col < 4)
    {
        int max = 0;
        int visible = 0;
        int row = 3;
        while (row >= 0)
        {
            if (board[row][col] > max)
            {
                max = board[row][col];
                visible++;
            }
            row--;
        }
        if (visible > constraints[col + 4] && constraints[col + 4] != 0)
            return 0;
        col++;
    }

    // Check row visibility from left
    int row = 0;
    while (row < 4)
    {
        int max = 0;
        int visible = 0;
        int col = 0;
        while (col < 4)
        {
            if (board[row][col] > max)
            {
                max = board[row][col];
                visible++;
            }
            col++;
        }
        if (visible > constraints[row + 8] && constraints[row + 8] != 0)
            return 0;
        row++;
    }

    // Check row visibility from right
    row = 0;
    while (row < 4)
    {
        int max = 0;
        int visible = 0;
        int col = 3;
        while (col >= 0)
        {
            if (board[row][col] > max)
            {
                max = board[row][col];
                visible++;
            }
            col--;
        }
        if (visible > constraints[row + 12] && constraints[row + 12] != 0)
            return 0;
        row++;
    }

    return 1;
}