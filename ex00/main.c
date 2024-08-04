#include <stdlib.h>

int	ft_solve(int **board, int *constraints, int row, int col);
void	ft_print_board(int **board);
void	ft_free_board(int **board);
void	ft_extract_constraints(int *constraints, char *arg);
void	ft_set_initial_board(int ***board);
void	ft_print_str(char *str);

int	main(int argc, char **argv)
{
	int	*constraints;
	int	**board;

	if (argc != 2)
	{
		ft_print_str("Error: Argument count exception\n");
		return 1;
	}                       
	constraints = malloc(16 * sizeof(int));
	ft_extract_constraints(constraints, argv[1]);
	ft_set_initial_board(&board);
	if (ft_solve(board, constraints, 0, 0))
		ft_print_board(board);
	else
		ft_print_str("Error: solving the board\n");

	ft_free_board(board);
	return (0);
}







