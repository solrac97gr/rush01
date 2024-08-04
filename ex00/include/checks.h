#ifndef CHECKS_H
#define CHECKS_H

// Function declarations for check_col.c
int ft_check_col(int **board, int col, int value);

    // Function declarations for check_row.c
int ft_check_row(int **board, int row, int value);

// Function declarations for check_visibility.c
int ft_check_visibility(int **board, int *constraints);

// Function declarations for is_valid.c
int ft_is_valid(int **board, int *constraints, int row, int col, int value);

#endif // CHECKS_H