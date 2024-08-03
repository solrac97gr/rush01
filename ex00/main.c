#include <stdio.h>
#include <stdlib.h>

int is_valid(int **board, int *constraints, int row, int col, int value);
int solve(int **board, int *constraints, int row, int col);
void print_board(int **board);
int check_row(int **board, int row, int value);
int check_col(int **board, int col, int value);
int check_visibility(int **board, int *constraints);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error: Argument count exception [only 2 arguments permited]\n");
        return 1;
    }

    int constraints[16];
    for (int i = 0; i < 16; i++)
    {
        constraints[i] = argv[1][i * 2] - '0';
    }

    int **board = malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        board[i] = malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solve(board, constraints, 0, 0))
    {
        print_board(board);
    }
    else
    {
        printf("Error: solving the board\n");
    }

    for (int i = 0; i < 4; i++)
    {
        free(board[i]);
    }
    free(board);
    return 0;
}

int is_valid(int **board, int *constraints, int row, int col, int value)
{
    // Check if value already exists in the row or column
    if (!check_row(board, row, value) || !check_col(board, col, value))
    {
        return 0;
    }

    // Place the value temporarily
    board[row][col] = value;

    // Check visibility constraints dynamically
    if (!check_visibility(board, constraints))
    {
        board[row][col] = 0; // Revert change
        return 0;
    }

    // Revert change after check
    board[row][col] = 0;
    return 1;
}

int check_row(int **board, int row, int value)
{
    for (int i = 0; i < 4; i++)
    {
        if (board[row][i] == value)
        {
            return 0;
        }
    }
    return 1;
}

int check_col(int **board, int col, int value)
{
    for (int i = 0; i < 4; i++)
    {
        if (board[i][col] == value)
        {
            return 0;
        }
    }
    return 1;
}

int check_visibility(int **board, int *constraints)
{
    // Check column visibility from top
    for (int col = 0; col < 4; col++)
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
    }

    // Check column visibility from bottom
    for (int col = 0; col < 4; col++)
    {
        int max = 0;
        int visible = 0;
        for (int row = 3; row >= 0; row--)
        {
            if (board[row][col] > max)
            {
                max = board[row][col];
                visible++;
            }
        }
        if (visible > constraints[col + 4] && constraints[col + 4] != 0)
            return 0;
    }

    // Check row visibility from left
    for (int row = 0; row < 4; row++)
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
    }

    // Check row visibility from right
    for (int row = 0; row < 4; row++)
    {
        int max = 0;
        int visible = 0;
        for (int col = 3; col >= 0; col--)
        {
            if (board[row][col] > max)
            {
                max = board[row][col];
                visible++;
            }
        }
        if (visible > constraints[row + 12] && constraints[row + 12] != 0)
            return 0;
    }

    return 1;
}

int solve(int **board, int *constraints, int row, int col)
{
    if (row == 4)
    {
        // Check final visibility constraints
        return check_visibility(board, constraints);
    }
    if (col == 4)
        return solve(board, constraints, row + 1, 0);

    for (int value = 1; value <= 4; value++)
    {
        if (is_valid(board, constraints, row, col, value))
        {
            board[row][col] = value;
            if (solve(board, constraints, row, col + 1))
            {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

void print_board(int **board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}