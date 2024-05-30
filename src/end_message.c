/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:37:24 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/30 11:35:20 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"

void	end_die(t_game *game)
{
	ft_printf(END);
	mlx_loop_end(game->mlx);
}

void	end_win(t_game *game)
{
	ft_printf(WIN);
	mlx_loop_end(game->mlx);
}
