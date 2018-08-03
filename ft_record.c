/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:06:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/08 18:06:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int			ft_creat_s(char *arr, t_coord **coord, ssize_t y)
{
	int		x;
	char	**str;
	ssize_t len;

	len = ft_count_words(arr, ' ');
	if (!(str = ft_strsplit(arr, ' ')))
		return (ft_error(ENOMEM));
	if (!(*coord = (t_coord*)malloc(sizeof(t_coord) * len)))
		return (ft_error(ENOMEM));
	x = 0;
	while (str[x] != NULL)
	{
		ft_new_struct(&(*coord)[x], x, y, str[x]);
		x++;
	}
	ft_free(str);
	return (0);
}

static	int			ft_creat_arr_struct(char **arr, t_fdf *fdf)
{
	ssize_t		len;
	ssize_t		y;

	len = ft_arrlen(((const char**)arr));
	if (!(fdf->matrix = (t_coord**)malloc(sizeof(t_coord*) * (len + 1))))
		return (ft_error(ENOMEM));
	y = 0;
	while (y < len)
	{
		if (ft_creat_s(arr[y], &fdf->matrix[y], y) < 0)
			return (-1);
		y++;
	}
	fdf->matrix[y] = NULL;
	return (0);
}

int					ft_record(char **arr, t_fdf *fdf)
{
	if (ft_creat_arr_struct(arr, fdf) < 0)
		return (-1);
	ft_free(arr);
	return (0);
}
