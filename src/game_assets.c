/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:09:00 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 15:09:10 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_assets(t_game *game)
{
	key_color(game);
	ft_put_nbr_to_win(game, game->walk / 20, 0);
	collect_fruit(game);
	win_game(game);
}
