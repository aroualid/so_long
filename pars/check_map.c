/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:58:59 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/15 18:42:46 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	get_line(char *file)
{
	char *str;
	int	infile;
	int	i;

	i = 0;
	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	while (str)
	{
		i++;
		free (str);
		str = get_next_line(infile);
	}
	close (infile);
	return (i);
}

char **get_each_line(char *file)
{
	int		i;
	char	**ptr;
	int		j;
	char	*str;
	int		infile;

	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	j = 0;
	i = get_line(file);
	ptr = ft_calloc(sizeof(char**), i);
	while (j < i)
	{
		ptr[j] = str;
		printf ("%s",ptr[j]);
		str = get_next_line(infile);
		j++;

	}
	close (infile);
	return (ptr);
}

int	get_len_line(char *file)
{
	int		res;
	int		i;
	char	**ptr;
	int		j;
	int		first_res;

	
	first_res = 0;
	res = 0;
	i = get_line(file);
	ptr = get_each_line(file);
	first_res = ft_strlen(ptr[0]) - 1;
	j = 1;
	while (j < i)
	{
		res = ft_strlen(ptr[j]) - 1;
		if (res == first_res)
			j++;
		else
			return (0);
	}
	return (1);
}
