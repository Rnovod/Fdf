/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argumets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:21:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/20 18:21:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int			ft_arg_color(t_fdf *fdf, char **av, int *i)
{
	(*i)++;
	if (!(av[*i]))
	{
		ft_putendl("Error: didn't put the color param");
		return (-1);
	}
	if (!(ft_strstr(av[*i], "0x")))
		return (-1);
	if (av[*i][2] == '\0')
	{
		ft_putendl("Error: incorrect color input");
		return (-1);
	}
	fdf->put_color = ft_atoi_base(&av[*i][2], 16);
	fdf->color = fdf->put_color;
	(*i)++;
	return (0);
}

static	int			ft_arg_size_win(t_fdf *fdf, char **av, int *i)
{
	if (!(av[*i + 1]) || !(av[*i + 2]))
	{
		ft_putendl("Error: didn't put correct data about the window");
		return (-1);
	}
	fdf->win_width = ft_atoi(av[*i + 1]);
	fdf->win_height = ft_atoi(av[*i + 2]);
	if (fdf->win_width <= 50 || fdf->win_height <= 50)
	{
		ft_putendl("Error: "
		"Width and height must be greater then 50");
		return (-1);
	}
	if (fdf->win_width > 1700 || fdf->win_height > 1300)
	{
		ft_putendl("Error: "
		"The width must be less then 1700, the height - less 1300");
		return (-1);
	}
	*i += 3;
	return (0);
}

static	int			ft_argumets(t_fdf *fdf, char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (ft_strcmp(av[i], "-c") == 0)
		{
			if (ft_arg_color(fdf, av, &i) < 0)
				return (-1);
		}
		else if (ft_strcmp(av[i], "-p") == 0)
		{
			if (ft_arg_size_win(fdf, av, &i) < 0)
				return (-1);
		}
		else if (av[i] != NULL)
			return (-1);
	}
	return (0);
}

int					ft_check_argumets(t_fdf *fdf, char **av, int ac)
{
	if (ac == 1 || ac > 7)
		return (-1);
	fdf->put_color = -1;
	fdf->win_width = 0;
	fdf->win_height = 0;
	if (ft_argumets(fdf, av) < 0)
		return (-1);
	return (0);
}
