/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:03:53 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/16 02:47:24 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	count_c(char *file)
{
	char	**ptr;
	int		c;
	int		i;
	int		j;
	char	*str;

	j = 0;
	c = 0;
	i = 0;
	ptr = get_each_line(file);
	while(i < get_line(file))
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] ==  'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	return (c);
}

int	count_e(char *file)
{
	char	**ptr;
	int		e;
	int		i;
	int		j;
	char	*str;

	j = 0;
	e = 0;
	i = 0;
	ptr = get_each_line(file);
	while(i < get_line(file))
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] ==  'E')
				e++;
			j++;
		}
		i++;
		j = 0;
	}
	return (e);
}

int	count_p(char *file)
{
	char	**ptr;
	int		p;
	int		i;
	int		j;
	char	*str;

	j = 0;
	p = 0;
	i = 0;
	ptr = get_each_line(file);
	while(i < get_line(file))
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] ==  'P')
				p++;
			j++;
		}
		i++;
		j = 0;
	}
	return (p);
}


int	count_element(char *file)
{
	int c;
	int	e;
	int	p;

	c = count_c(file);
	e = count_e(file);
	p = count_p(file);
	if (c >= 1 && e == 1 && p == 1 && (first_last_wall(file) == 1) && (check_first_last_coll(file) == 1) 
		&& check_good_carac(file) == 1)
	{
		printf("OUI\n");
		return (1);
	}
	else
	{
		printf("NON\n");
		return (0);
	}
}
