/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapverif2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtenzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:42:37 by dtenzen           #+#    #+#             */
/*   Updated: 2023/10/22 15:43:12 by dtenzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_remplissage(t_struct *data)
{
	int	line;
	int	col;
	int	i;

	line = 0;
	i = 0;
	data->map = malloc(sizeof(char *) * (data->line + 1));
	if (!data->map)
		return (-1);
	while (line < data->line)
	{
		col = 0;
		data->map[line] = malloc(sizeof(char) * (data->col + 1));
		if (data->map[line] == NULL)
			return (-1);
		while (data->str_file[i] != '\n')
			data->map[line][col++] = data->str_file[i++];
		data->map[line][col] = '\0';
		i++;
		line++;
	}
	data->map[line] = malloc(sizeof(char) * (data->col + 1));
	if (data->map[line] == NULL)
		return (-1);
	data->map[line][0] = '\0';
	return (0);
}

int	ft_check_elem(t_struct *data, int i)
{
	int	j;

	j = 0;
	while (j < data->col - 1)
	{
		if (ft_caravalide(data->map[i][j]) == -1)
			return (-1);
		if (data->map[i][j] == 'E')
			data->exit++;
		if (data->map[i][j] == 'C')
			data->item++;
		if (data->map[i][j] == 'P')
		{
			data->pos_col = j;
			data->pos_line = i;
			data->start++;
		}
		j++;
	}
	return (0);
}
