/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:43:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/16 02:49:23 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	first_last_wall(char *file)
{
	char	**ptr;
	int		i;
	char	*first;
	char	*last;
	

	i = 0;
	ptr = get_each_line(file);
	first = ptr[0];
	last = ptr[get_line(file) - 1];
	while (first[i] != '\n')
	{
		if (first[i] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (last[i] != '\n')
	{
		if (last[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_first_last_coll(char *file)
{
	char	**ptr;
	int		i;
	char	*str;

	i = 0;
	ptr = get_each_line(file);
	while (i < get_line(file))
	{
		str = ptr[i];
		if (str[0] == '1' && str[get_len_line(file) - 1] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_good_carac(char *file)
{
	char	**ptr;
	int		i;
	char	*str;
	int		j;
	
	j = 0;
	i = 0;
	ptr = get_each_line(file);
	while (i < get_line(file))
	{
		str = ptr[i];
		while (j != get_len_line(file) - 1)
		{
			if ((str[j] == '1') || (str[j] == '0') || (str[j] == 'P') ||
				(str[j] == 'C') || (str[j] == 'E'))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
		
	}
	printf ("YOUPI\n");
	return (1);
}


