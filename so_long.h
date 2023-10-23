/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtenzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:34:51 by dtenzen           #+#    #+#             */
/*   Updated: 2023/10/22 15:53:48 by dtenzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_struct
{
	char	**map;
	int		line;
	int		col;
	int		exit;
	int		item;
	int		start;
	int		pos_line;
	int		pos_col;
	int		sortietrouve;
	int		itemscount;
	char	*str_file;
}t_struct;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*floor;
	void		*wall;
	void		*player;
	void		*exit;
	void		*item1;
	void		*item2;
	void		*item3;
	void		*item4;
	int			img_width;
	int			img_height;
	int			x;
	int			y;
	int			mov_count;
	t_struct	data;
}	t_vars;

typedef struct s_case
{
	int	line;
	int	col;
	int	direction;
}t_case;

//utils
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_free(char **str);

//verification
int		ft_verifichier(char *str);
int		ft_verif(char **av, t_struct *data);
int		ft_verif2(t_struct *data);

//map.veri
int		ft_check_wall1(t_struct *data);
int		ft_check_wall2(t_struct *data);
int		ft_check_map(t_struct *data);
int		ft_caravalide(char c);

//mapverif2
int		ft_check_elem(t_struct *data, int i);
int		ft_remplissage(t_struct *data);

//ft_cheminvalide
int		ft_check_chemin(t_struct *data, t_case cell);
char	ft_check_case(t_struct *data, t_case cell);

//main
int		ft_input(int keycode, t_vars *vars);
int		ft_close(t_vars *vars);
int		ft_close2(t_vars *vars);
void	ft_input2(int keycode, t_vars *vars);

//mapmap
int		t_item(t_vars	*vars, int i, int j, int count);
void	ft_draw(t_vars *vars, int i, int j, int a);
void	ft_map(t_struct *data, t_vars *vars);
void	ft_check_player(t_vars *vars);
int		ft_textures(t_vars	*vars);

//mapsmapsmaps
int		ft_taillefichier(char *str);
int		ft_size_col(t_struct *data);
int		ft_size_line(t_struct *data);
int		ft_file_to_str(char *av, t_struct *data);

#endif
