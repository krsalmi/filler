/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 01:02:11 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/28 19:20:47 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <errno.h>
# define BEGINNING_PL_LINE "$$$ exec p"
# define PLATEAU "Plateau "
# define PIECE "Piece "
# define ENEMY 200000
# define OWN 100000
# define EMPTY 1000

typedef	struct	s_info
{
	int	y;
	int	x;
	int	begin_y;
	int	begin_x;
	int	end_y;
	int	end_x;
}				t_info;

char			check_player_char(void);
t_info			*init_struct(t_info *new);
t_info			*get_parameters(char *to_compare, t_info *info);
int				**create_int_map(int y, int x);
void			save_as_ints_map(int *int_line, char *line, char p_char);
int				**save_map(t_info *map_info, char p_char);
void			place_zeroes_around_enemy(int **map, t_info *map_info);
int				**save_token(t_info *token_info);
void			make_heat_zones(int **map, t_info *map_info);
int				turn_up_heat(int **map, t_info *map_info, int val, int check);
void			get_token_beginning_point(int **token, t_info *tinfo);
int				**trim_token(int **token, t_info *tok_info, int orig_y);
t_info			*find_place(int **map, int **token, t_info *m_info, \
					t_info *to_info);
int				try_positions(int **map, int **token, t_info *tok_info, \
					t_info cur);
t_info			*save_best_position(t_info *map_info, t_info *tinfo, \
					int y, int x);
void			free_map_token(int **map, int **token, t_info *minfo, \
					t_info *tinfo);
void			filler_error_handling(char *msg);
#endif
