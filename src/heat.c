/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:51:24 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/25 01:27:27 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_zeroes_around_enemy(int **map, t_info *map_info)
{
	int	i;
	int j;

	i = 0;
	while (i < map_info->y)
	{
		j = 0;
		while (j < map_info->x)
		{
			if (map[i][j] == ENEMY)
			{
				if (j + 1 < map_info->x && map[i][j + 1] == EMPTY)
					map[i][j + 1] = 0;
				if (j > 0 && map[i][j - 1] == EMPTY)
					map[i][j - 1] = 0;
				if (i + 1 < map_info->y && map[i + 1][j] == EMPTY)
					map[i + 1][j] = 0;
				if (i > 0 && map[i - 1][j] == EMPTY)
					map[i - 1][j] = 0;
			}
			j++;
		}
		i++;
	}
}

int		turn_up_heat(int **map, t_info *map_info, int val, int check)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->y)
	{
		j = -1;
		while (++j < map_info->x)
		{
			if (map[i][j] == val)
			{
				check = 1;
				if (j + 1 < map_info->x && map[i][j + 1] == EMPTY)
					map[i][j + 1] = val + 1;
				if (j > 0 && map[i][j - 1] == EMPTY)
					map[i][j - 1] = val + 1;
				if (i + 1 < map_info->y && map[i + 1][j] == EMPTY)
					map[i + 1][j] = val + 1;
				if (i > 0 && map[i - 1][j] == EMPTY)
					map[i - 1][j] = val + 1;
			}
		}
	}
	return (check);
}

void	make_heat_zones(int **map, t_info *map_info)
{
	int	val;

	place_zeroes_around_enemy(map, map_info);
	val = 0;
	while ((turn_up_heat(map, map_info, val, 0)) == 1)
		val++;
}
