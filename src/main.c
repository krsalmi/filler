/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:03:25 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/28 19:17:14 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	check_player_char(void)
{
	size_t	len;
	char	p_char;
	char	*line;

	p_char = 0;
	len = ft_strlen(BEGINNING_PL_LINE);
	if (get_next_line(0, &line) == -1)
		filler_error_handling(strerror(errno));
	if (line && !ft_strncmp(line, BEGINNING_PL_LINE, len))
	{
		p_char = (line[len] == '1') ? 'o' : 'x';
		ft_strdel(&line);
	}
	else
	{
		if (line)
			ft_strdel(&line);
		filler_error_handling("Incorrectly formatted player information");
	}
	return (p_char);
}

void	free_map_token(int **int_map, int **token, t_info *minfo, t_info *tinfo)
{
	ft_free_int_tab(int_map, minfo->y);
	ft_free_int_tab(token, tinfo->y);
	int_map = NULL;
	token = NULL;
}

int		main(void)
{
	t_info	map_info;
	t_info	token_info;
	char	p_char;
	int		**int_map;
	int		**token;

	p_char = check_player_char();
	while (1)
	{
		init_struct(&map_info);
		get_parameters(PLATEAU, &map_info);
		int_map = save_map(&map_info, p_char);
		make_heat_zones(int_map, &map_info);
		init_struct(&token_info);
		get_parameters(PIECE, &token_info);
		token = save_token(&token_info);
		find_place(int_map, token, &map_info, &token_info);
		ft_printf("%d %d\n", map_info.end_y, map_info.end_x);
		free_map_token(int_map, token, &map_info, &token_info);
	}
	return (0);
}
