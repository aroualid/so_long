/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:17:56 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 16:37:33 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:29 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 16:03:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_collectibles	*create_node_collectibles(int x, int y)
{
	t_collectibles	*new_node;

	new_node = malloc(sizeof(t_collectible));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->x = x;
	new_node->y = y;
	return (new_node);
}

void	add_node_collec(t_collectibles **lst, t_collectibles *new)
{
	t_collectibles	*current;
	t_collectibles	*previous;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	previous->next = new;
}

t_collectibles	*create_list_collec(t_game *game)
{
	t_collectibles	*node;
	t_collectibles	*list;
	int				x;
	int				y;

	list = NULL;
	y = 0;
	x = 0;
	while (y < game->max_y)
	{
		while (x < game->max_x)
		{
			if (game->map_ok[y][x] == 'C')
			{
				node = create_node_collectibles(x, y);
				add_node_collec(&list, node);
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (list);
}

