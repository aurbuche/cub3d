/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:34:16 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/15 09:10:22 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include "../libft/include/libftprintf.h"

typedef struct          s_cub
{
	size_t		n_line;
	int			fd;
	int			c;
	int			f;
	int			f_color[3];
	int			c_color[3];
	int			res[2];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**map;
}                       t_cub;

typedef struct			s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}						t_data;

t_cub			*ft_init_cub();
int				ft_check_cub(int ac, char **av, t_cub *cub);
void			ft_disp_error(char *str);
void			ft_disp_map_ok(t_cub *cub);
int				ft_parse(char *line, t_cub *cub);
void			f_converter(size_t i, char *line, t_cub *cub);
void			r_converter(size_t i, char *line, t_cub *cub);
void			c_converter(size_t i, char *line, t_cub *cub);
void			no_converter(size_t i, char *line, t_cub *cub);
void			so_converter(size_t i, char *line, t_cub *cub);
void			we_converter(size_t i, char *line, t_cub *cub);
void			ea_converter(size_t i, char *line, t_cub *cub);
void			s_converter(size_t i, char *line, t_cub *cub);
int				ft_map_analyze(char *line, t_cub *cub);
int				ft_temporary(char *line, t_cub *cub);
int				ft_check_map(t_cub *cub);
int				ft_check_inside(t_cub *cub);

#endif