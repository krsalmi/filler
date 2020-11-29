/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:49:38 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/28 18:50:23 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_int_map(int y, int x)
{
	int i;
	int	**int_map;

	if (!(int_map = (int**)malloc(sizeof(int*) * y)))
		filler_error_handling(strerror(errno));
	i = 0;
	while (i < y)
	{
		if (!(int_map[i] = (int*)malloc(sizeof(int) * x)))
			filler_error_handling(strerror(errno));
		i++;
	}
	return (int_map);
}

void	save_as_ints_map(int *int_line, char *line, char p_char)
{
	int		i;
	char	*to_read;

	to_read = (line + 4);
	i = 0;
	while (to_read[i])
	{
		if (to_read[i] == '.')
			int_line[i] = EMPTY;
		else if (p_char == 'o')
		{
			if (to_read[i] == 'o' || to_read[i] == 'O')
				int_line[i] = OWN;
			if (to_read[i] == 'x' || to_read[i] == 'X')
				int_line[i] = ENEMY;
		}
		else if (p_char == 'x')
		{
			if (to_read[i] == 'o' || to_read[i] == 'O')
				int_line[i] = ENEMY;
			if (to_read[i] == 'x' || to_read[i] == 'X')
				int_line[i] = OWN;
		}
		i++;
	}
}

int		**save_map(t_info *map_info, char p_char)
{
	int		row_counter;
	char	*line;
	int		res;
	int		**int_map;

	row_counter = -1;
	int_map = create_int_map(map_info->y, map_info->x);
	while (row_counter < map_info->y && (res = get_next_line(0, &line)) != -1)
	{
		if (row_counter >= 0)
			save_as_ints_map(int_map[row_counter], line, p_char);
		row_counter++;
		ft_strdel(&line);
	}
	if (res == -1)
		filler_error_handling(strerror(errno));
	return (int_map);
}
