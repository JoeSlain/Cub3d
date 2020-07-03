/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:31:05 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/22 16:23:18 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_error(char *s)
{
	write(2, "Error:\n", 7);
	write(2, s, ft_strlen(s));
	exit(1);
}

void		ft_free_map(t_info *info_map)
{
	int		y;
	t_map	*ptr;

	y = 0;
	ptr = info_map->map_struct;
	while (y < info_map->len_y)
	{
		free(info_map->map[y]);
		y++;
	}
	free(info_map->map);
	if (info_map->map_struct)
	{
		while (info_map->map_struct)
		{
			ptr = info_map->map_struct->next;
			free(info_map->map_struct->line);
			free(info_map->map_struct);
			info_map->map_struct = ptr;
		}
	}
}

void		ft_error_free(char *s, t_info *info_map)
{
	ft_free_map(info_map);
	ft_error(s);
}

void		ft_error_map_fill(char **tmp, char *s, int i)
{
	int		k;

	k = 0;
	while (k < i)
	{
		free(tmp[k]);
		k++;
	}
	free(tmp);
	ft_error(s);
}
