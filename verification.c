/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtenzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:56:08 by dtenzen           #+#    #+#             */
/*   Updated: 2023/10/22 15:57:16 by dtenzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verifichier(char *str)
{
	int			fd;
	int			i;
	int			j;
	static char	ber[4] = ".ber";

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	i = ft_strlen(str);
	if (i < 4)
		return (-1);
	i = i - 4;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ber[j])
			return (-1);
		i++;
		j++;
	}
	return (0);
}

int	ft_verif2(t_struct *data)
{
	t_case	cell;

	cell.line = data->pos_line;
	cell.col = data->pos_col;
	cell.direction = 0;
	data->sortietrouve = 0;
	data->itemscount = 0;
	ft_check_chemin(data, cell);
	if (data->sortietrouve != 1 || data->itemscount != data->item)
		return (-1);
	ft_free(data->map);
	return (0);
}

int	ft_verif(char **av, t_struct *data)
{
	if (ft_verifichier(av[1]) == -1)
		return (ft_putstr("Error\nLe fichier n'est pas valide\n"), -1);
	if (ft_file_to_str(av[1], data) == -1)
		return (ft_putstr("Error\nLa map pas valide\n"), -1);
	if (ft_size_col(data) < 3)
		return (free(data->str_file), ft_putstr("Error\nMAP PAS BONNE\n"), -1);
	if (ft_size_line(data) < 3)
		return (free(data->str_file), ft_putstr("Error\nMAP PAS BONNE\n"), -1);
	if (ft_remplissage(data) == -1)
		return (free(data->str_file), ft_putstr("Error\nProbleme de malloc\n")
			, -1);
	if (ft_check_wall1(data) == -1)
		return (free(data->str_file), ("Error\nMur pas valide\n"),
			ft_free(data->map), -1);
	if (ft_check_map(data) == -1)
		return (free(data->str_file), ft_putstr("ERROR\n,Map pas bonne\n"),
			ft_free(data->map), -1);
	if (ft_verif2(data) == -1)
		return (free(data->str_file), ft_free(data->map),
			ft_putstr("Error\nPas de chemin valide\n")
			, -1);
	return (0);
}
