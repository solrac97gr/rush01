/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos97gr <carloga2@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:52:03 by carlos97gr        #+#    #+#             */
/*   Updated: 2024/08/04 15:52:14 by carlos97gr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "solve.h"
#include "board.h"
#include "utils.h"
#include "constraints.h"

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

