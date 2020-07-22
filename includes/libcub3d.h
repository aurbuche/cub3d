/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:34:16 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/22 14:06:10 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV 66
# define RENDERDIST 10
# define MOVESPEED 0.075
# define ROTSPEED 0.04

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <math.h>
# include <stdbool.h>
# include "key.h"
# include "../libft/include/libft.h"
# include "../libft/include/libftprintf.h"

typedef struct			s_im
{
	void		*img;
	int			width;
	int			height;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}						t_im;

typedef struct 			s_plane
{
	double		x;
	double		y;
}						t_plane;

typedef	struct 			s_pos
{
	double		x;
	double		y;
}						t_pos;

typedef struct			s_dir
{
	double		x;
	double		y;
}						t_dir;

typedef struct			s_data
{
	float		d;
	float		h;
}						t_data;


typedef struct          s_cub
{
	size_t		n_line;
	int			fd;
	int			c;
	int			f;
	int			f_color[3];
	int			c_color[3];
	int			res[2];
	char		ori;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**map;
	t_pos		pos;
	t_dir		dir;
	t_plane		plane;
	void		*mlx_ptr;
	void		*mlx_win;
	char		move;
	char		turn;
	t_im		screen;
	t_data		wall;
	t_data		ceil;
	t_data		floor;
}                       t_cub;

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
int				ft_begin_disp(t_cub *cub);
int				ft_close(t_cub *cub);
// t_data			*ft_init_data();
void			ft_start_player_pos(char c, t_cub *cub, size_t x, size_t y);
void			ft_dir(t_cub *cub);
int         	cub_loop(t_cub *cub);
void			ft_move(t_cub *cub);

#endif