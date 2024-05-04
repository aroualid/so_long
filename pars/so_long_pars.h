/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pars.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:35:56 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/04 20:19:24 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_PARS_H

# define SO_LONG_PARS_H

# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../includes/so_long.h"
# include "../ft_printf/ft_printf.h"

char	**get_each_line(char *file, t_game *game);
int		get_line(char *file, t_game *game);
int		get_len_line(char *file, t_game *game);
int		count_element(char **ptr, t_game *game);
int		first_last_wall(char **ptr, t_game *game);
int		check_first_last_coll(char **ptr, t_game *game);
int		check_good_carac(char **ptr, t_game *game);
int		flood_fill(t_game *game, int x, int y, char *file);
void	ft_free(char **tav);
int		count_element_ff(char **file, t_game *game);
int		count_p_ff(char **ptr, t_game *game);
int		count_c_ff(char **ptr, t_game *game);
int		count_p(char **ptr, t_game *game);
int		pars(int ac, char **av, t_game *game);
#endif
