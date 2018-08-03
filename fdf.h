/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:04:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/12 13:32:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# define PI 3.1416

typedef	struct	s_color
{
	double		color;
	double		s_color;
	double		f_color;
	double		procent;
}				t_color;

typedef	struct	s_coord
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_coord;

typedef	struct	s_brez
{
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
	int			e2;
}				t_brez;

typedef	struct	s_fdf
{
	size_t		width_matrix;
	size_t		height_matrix;
	int			win_height;
	int			win_width;
	int			y_centr;
	int			x_centr;
	t_brez		brez;
	t_coord		**matrix;
	t_coord		**origin;
	int			put_color;
	int			color;
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			*str_img;
	int			start_x;
	int			start_y;
	int			s_line;
	int			l_len;
	int			go_x;
	int			go_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			min_z;
	int			max_z;
	double		ch_z;
}				t_fdf;

int				ft_get_rvalue(int color);
int				ft_get_gvalue(int color);
int				ft_get_bvalue(int color);
char			**ft_open_read(char *namefile);
int				ft_record(char **arr, t_fdf *fdf);
void			ft_new_struct(t_coord *new, int x, ssize_t y, char *z_color);
int				ft_fdf(t_fdf *fdf);
int				ft_creat_img_and_put(t_fdf *fdf);
void			ft_brezenhem(t_fdf *fdf);
void			ft_go(t_fdf *fdf, int key);
void			ft_rot_and_z(t_fdf *fdf, int key);
int				ft_gradient(int f_color, int s_color, double percent);
void			ft_change_color(t_fdf *fdf, int key);
int				ft_copy_matrix(t_fdf *fdf);
int				ft_info(t_fdf *fdf);
void			ft_put_to_centr(t_fdf *fdf);
void			ft_free_all(t_fdf *fdf);
int				ft_error(int error);
void			ft_find_z(t_fdf *fdf);
double			ft_procent(double color, double f_color, double s_color);
int				ft_check_argumets(t_fdf *fdf, char **av, int ac);
void			ft_discard_to_default(t_fdf *fdf);
void			ft_instructions(void);
int				ft_validation(t_fdf *fdf, char **file);

#endif
