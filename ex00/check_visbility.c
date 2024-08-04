int ft_check_visibility(int **board, int *constraints);
int count_visible(int **board, int start_row, int start_col, int row_step, int col_step);
int check_row_visibility(int **board, int *constraints, int row);
int check_col_visibility(int **board, int *constraints, int col);

int ft_check_visibility(int **board, int *constraints)
{
	for (int col = 0; col < 4; col++)
	{
		if (!check_col_visibility(board, constraints, col))
			return 0;
	}

	for (int row = 0; row < 4; row++)
	{
		if (!check_row_visibility(board, constraints, row))
			return 0;
	}

	return 1;
}

int count_visible(int **board, int start_row, int start_col, int row_step, int col_step)
{
	int max = 0;
	int visible = 0;
	int row = start_row;
	int col = start_col;

	while (row >= 0 && row < 4 && col >= 0 && col < 4)
	{
		if (board[row][col] > max)
		{
			max = board[row][col];
			visible++;
		}
		row += row_step;
		col += col_step;
	}

	return visible;
}

int check_row_visibility(int **board, int *constraints, int row)
{
	int max = 0;
	int visible = 0;

	for (int col = 0; col < 4; col++)
	{
		if (board[row][col] > max)
		{
			max = board[row][col];
			visible++;
		}
	}

	if (visible > constraints[row + 8] && constraints[row + 8] != 0)
		return 0;

	return 1;
}

int check_col_visibility(int **board, int *constraints, int col)
{
	int max = 0;
	int visible = 0;

	for (int row = 0; row < 4; row++)
	{
		if (board[row][col] > max)
		{
			max = board[row][col];
			visible++;
		}
	}

	if (visible > constraints[col] && constraints[col] != 0)
		return 0;

	return 1;
}
