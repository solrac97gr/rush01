// Description: Check if the visibility is correct.
int	ft_check_visibility(int **board, int *constraints)
{
	int	col;
	int	row;
	int	max;
	int	visible;

	col = 0;
	while (col < 4)
	{
		max = 0;
		visible = 0;
		row = 0;
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

	col = 0;
	while (col < 4)
	{
		max = 0;
		visible = 0;
		row = 3;
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

	row = 0;
	while (row < 4)
	{
		max = 0;
		visible = 0;
		col = 0;
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

	row = 0;
	while (row < 4)
	{
		max = 0;
		visible = 0;
		col = 3;
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
	return (1);
}
