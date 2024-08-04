#include <checks.h>

// Description: Solve the board using backtracking.
int	ft_solve(int **board, int *constraints, int row, int col)
{
	int	value;

	value = 0;
	if (row == 4)
	{
		return ft_check_visibility(board, constraints);
	}
	if (col == 4)
		return ft_solve(board, constraints, row + 1, 0);
	while (value <= 4)
	{
		if (ft_is_valid(board, constraints, row, col, value))
		{
			board[row][col] = value;
			if (ft_solve(board, constraints, row, col + 1))
			{
				return (1);
			}
			board[row][col] = 0;
		}
		value++;
	}
    return (0);
}
