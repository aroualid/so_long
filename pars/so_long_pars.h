/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pars.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:35:56 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/16 02:44:22 by aroualid         ###   ########.fr       */
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

char	**get_each_line(char *file);
int		get_line(char *file);
int		get_len_line(char *file);
int		count_element(char *file);
int		first_last_wall(char *file);
int		check_first_last_coll(char *file);
int		check_good_carac(char *file);


#endif
