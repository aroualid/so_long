/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:34:32 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/22 14:53:40 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	extension(char *av2)
{
	int	i;

	i = ft_strlen(av2);
	if (i > 4)
	{
		if (ft_strncmp(av2 + i - 4, ".ber", 4) != 0)
			return (0);
		else
		{
			if (av2[i - 5] == '/')
				return (0);
			return (1);
		}
		return (1);
	}	
	else if (i <= 4)
		return (0);
	return (0);
}

int	check_file(char *av2)
{
	if (extension (av2) == 1)
	{
		if (open(av2, O_RDONLY) != -1)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	if (ac == 2)
	{
		if (check_file (av[1]) == 0)
			printf ("ERROR\n");
		else if (check_file (av[1]) == 1 
				&& get_len_line(av[1], &game) != 0 
				&& count_element(av[1], &game) == 1)
		{
			printf("px = %i\n", game.pp_x);
			printf("py = %i\n", game.pp_y);
			printf("max x = %i\n", game.max_x);
			printf("max y = %i\n", game.max_y);	
			flood_fill(&game, game.pp_x, game.pp_y, av[1]);
			for(int i = 0; i < game.max_y; i++)
			{
				printf("%s", game.map[i]);
			}
		}
		else
			printf("ERROR3\n");
	}
	else
		printf ("ERROR2\n");
}
