/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:52:53 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/28 18:33:10 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		try_positions(int **map, int **token, t_info *tok_info, t_info cur)
{
	int	ret;
	int	i;
	int	j;
	int y;
	int x;

	ret = 0;
	y = cur.y;
	i = 0;
	while (i < tok_info->y)
	{
		x = cur.x;
		j = 0;
		while (j < tok_info->x)
		{
			if (token[i][j] == 1)
				ret += (map[y][x]);
			x++;
			j++;
		}
		y++;
		i++;
	}
	ret = (ret < OWN) ? ENEMY : ret;
	return (ret);
}

t_info	*save_best_position(t_info *map_info, t_info *tinfo, int y, int x)
{
	int	final_y;
	int	final_x;

	final_y = y - tinfo->begin_y;
	final_x = x - tinfo->begin_x;
	map_info->end_y = final_y;
	map_info->end_x = final_x;
	return (map_info);
}

t_info	*find_place(int **map, int **token, t_info *m_info, t_info *to_info)
{
	t_info	cur;
	int		ret;
	int		min_sum;
	t_info	min;

	min_sum = ENEMY;
	min.x = m_info->x;
	cur.y = 0;
	while (cur.y <= (m_info->y - to_info->y))
	{
		cur.x = 0;
		while (cur.x <= (m_info->x - to_info->x))
		{
			ret = try_positions(map, token, to_info, cur);
			if (ret < min_sum || (ret == min_sum && cur.x < min.x))
			{
				min_sum = ret;
				min.y = cur.y;
				min.x = cur.x;
			}
			cur.x++;
		}
		cur.y++;
	}
	return (save_best_position(m_info, to_info, min.y, min.x));
}
