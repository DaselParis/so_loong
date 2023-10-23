#include "so_long.h"

int	ft_taillefichier(char *str)
{
	int		fd;
	int		count;
	char	buff[1];

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buff, 1) != 0)
	{
		count++;
		if (count > 20000)
			return (-1);
	}
	close(fd);
	return (count);
}

int	ft_size_col(t_struct *data)
{
	int	i;

	i = 0;
	while (data->str_file[i] != '\0')
	{
		if (data->str_file[i] == '\n')
		{
			data->col = i;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_size_line(t_struct *data)
{
	int	i;
	int	col_count;
	int	line_count;

	i = 0;
	col_count = 0;
	line_count = 0;
	while (data->str_file[i] != '\0')
	{
		if (data->str_file[i] == '\n')
		{
			if (col_count != data->col)
				return (-1);
			col_count = -1;
			line_count++;
		}
		col_count++;
		i++;
	}
	data->line = line_count;
	return (line_count);
}

int	ft_file_to_str(char *av, t_struct *data)
{
	int		fd;
	int		size;

	size = ft_taillefichier(av);
	if (size == -1)
		return (-1);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	data->str_file = malloc(sizeof(char) * (size + 1));
	if (data->str_file == NULL)
		return (close(fd), -1);
	if (read(fd, data->str_file, size) == -1)
		return (close(fd), free(data->str_file), -1);
	data->str_file[size] = '\0';
	close(fd);
	return (0);
}


// utiliser cette char *str pour compter les cols, lignes et remplir la map (ft_remplissage)
