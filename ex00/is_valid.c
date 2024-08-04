int ft_check_row(int **board, int row, int value);
int ft_check_col(int **board, int col, int value);
int ft_check_visibility(int **board, int *constraints);

// Description: Check if the value is valid in the board.
int	ft_is_valid(int **board, int *constraints, int row, int col, int value)
{
	if (!ft_check_row(board, row, value) || !ft_check_col(board, col, value))
	{
		return (0);
	}
	board[row][col] = value;
	if (!ft_check_visibility(board, constraints))
	{
		board[row][col] = 0;
		return 0;
	}
	board[row][col] = 0;
	return (1);
}
