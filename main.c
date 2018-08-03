/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:45:24 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/20 17:06:51 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	fdf;
	char	**map;

	if (ft_check_argumets(&fdf, &av[1], ac) < 0)
	{
		ft_putendl("Usage : fdf <filename> -c <0xCOLOR> -p <width> <height>");
		return (-1);
	}
	if (!(map = ft_open_read(av[1])) || ft_validation(&fdf, map) < 0)
		return (-1);
	if (ft_info(&fdf) < 0)
	{
		ft_putendl("Something bad happened with mlx");
		return (-1);
	}
	if (ft_record(map, &fdf) < 0 || ft_copy_matrix(&fdf) < 0)
		return (-1);
	ft_instructions();
	if (ft_fdf(&fdf) < 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	mlx_loop(fdf.mlx);
	return (0);
}
