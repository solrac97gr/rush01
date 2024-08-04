int ft_check_row(int **board, int row, int value);
int ft_check_col(int **board, int col, int value);
int ft_check_visibility(int **board, int *constraints);

// Description: Check if the value is valid in the board.
int ft_is_valid(int **board, int *constraints, int row, int col, int value)
{
    // Check if value already exists in the row or column
    if (!ft_check_row(board, row, value) || !ft_check_col(board, col, value))
    {
        return 0;
    }

    // Place the value temporarily
    board[row][col] = value;

    // Check visibility constraints dynamically
    if (!ft_check_visibility(board, constraints))
    {
        board[row][col] = 0; // Revert change
        return 0;
    }

    // Revert change after check
    board[row][col] = 0;
    return 1;
}