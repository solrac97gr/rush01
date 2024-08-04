int ft_is_valid(int **board, int *constraints, int row, int col, int value);
int ft_check_visibility(int **board, int *constraints);

// Description: Solve the board using backtracking.
int ft_solve(int **board, int *constraints, int row, int col)
{
    if (row == 4)
    {
        // Check final visibility constraints
        return ft_check_visibility(board, constraints);
    }
    if (col == 4)
        return ft_solve(board, constraints, row + 1, 0);

    for (int value = 1; value <= 4; value++)
    {
        if (ft_is_valid(board, constraints, row, col, value))
        {
            board[row][col] = value;
            if (ft_solve(board, constraints, row, col + 1))
            {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}