/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:50:36 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/28 19:19:53 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**save_token(t_info *token_info)
{
	int		row_counter;
	char	*line;
	int		i;
	int		res;
	int		**token;

	row_counter = 0;
	token = create_int_map(token_info->y, token_info->x);
	while (row_counter < token_info->y && (res = get_next_line(0, &line)) != -1)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '.')
				token[row_counter][i] = 0;
			else
				token[row_counter][i] = 1;
			i++;
		}
		row_counter++;
		ft_strdel(&line);
	}
	if (res == -1)
		filler_error_handling(strerror(errno));
	return (trim_token(token, token_info, token_info->y));
}

void	get_token_beginning_point(int **token, t_info *tinfo)
{
	int	i;
	int	j;

	tinfo->begin_y = tinfo->y;
	tinfo->begin_x = tinfo->x;
	i = 0;
	while (i < tinfo->y)
	{
		j = 0;
		while (j < tinfo->x)
		{
			if (token[i][j] == 1)
			{
				tinfo->begin_y = (i < tinfo->begin_y) ? i : tinfo->begin_y;
				tinfo->begin_x = (j < tinfo->begin_x) ? j : tinfo->begin_x;
				tinfo->end_y = (i > tinfo->end_y) ? i : tinfo->end_y;
				tinfo->end_x = (j > tinfo->end_x) ? j : tinfo->end_x;
			}
			j++;
		}
		i++;
	}
	tinfo->y = tinfo->end_y - tinfo->begin_y + 1;
	tinfo->x = tinfo->end_x - tinfo->begin_x + 1;
}

int		**trim_token(int **token, t_info *tok_info, int orig_y)
{
	int	h;
	int	w;
	int	**cut;
	int	i;
	int	j;

	get_token_beginning_point(token, tok_info);
	cut = create_int_map(tok_info->y, tok_info->x);
	i = tok_info->begin_y;
	h = 0;
	while (h < tok_info->y)
	{
		w = 0;
		j = tok_info->begin_x;
		while (w < tok_info->x)
		{
			cut[h][w] = token[i][j];
			j++;
			w++;
		}
		i++;
		h++;
	}
	ft_free_int_tab(token, orig_y);
	return (cut);
}
