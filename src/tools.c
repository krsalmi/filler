/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:58:58 by ksalmi            #+#    #+#             */
/*   Updated: 2020/09/28 19:17:17 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_info	*init_struct(t_info *new)
{
	new->y = 0;
	new->x = 0;
	new->begin_y = 0;
	new->begin_x = 0;
	new->end_y = 0;
	new->end_x = 0;
	return (new);
}

t_info	*get_parameters(char *to_compare, t_info *info)
{
	char	*line;
	size_t	len;
	int		ret;

	if ((ret = get_next_line(0, &line)) == -1)
		filler_error_handling(strerror(errno));
	if (line != NULL && ft_strstr(line, to_compare) == line)
	{
		len = ft_strlen(to_compare);
		info->y = ft_atoi(line + len);
		info->x = ft_atoi(ft_strrchr(line, ' '));
	}
	else
	{
		if (ret)
			ft_strdel(&line);
		filler_error_handling("Incorrectly formatted parameters");
	}
	if (line)
		ft_strdel(&line);
	if (info->y > 999 || info->x > 999)
		filler_error_handling("Size too big");
	return (info);
}

void	filler_error_handling(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}
