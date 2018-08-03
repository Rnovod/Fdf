/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:39:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/20 20:39:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int			ft_check_correct_color(char **file)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] != NULL)
	{
		j = 0;
		while (file[i][j] != '\0')
		{
			if (file[i][j] == ',')
				if (!ft_strstr(&file[i][j], ",0x"))
					return (-1);
			if (file[i][j] == 'x')
				if (file[i][j + 1] == ' ')
					return (-1);
			if (file[i][j] == ',' && (file[i][j + 1] != '0' ||
				file[i][j + 2] != 'x'))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static	int			ft_check_length(char **file, t_fdf *fdf)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_count_words(file[i], ' ');
	if (len == 0)
		return (-1);
	while (file[i] != NULL)
	{
		if (len != ft_count_words(file[i], ' '))
			return (-1);
		i++;
	}
	fdf->width_matrix = len;
	fdf->height_matrix = i;
	return (0);
}

static	int			ft_check_char(char **file)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] != NULL)
	{
		j = 0;
		while (file[i][j] != '\0')
		{
			if (file[i][j] != ' ' && file[i][j] != '\n' &&
				file[i][j] != 'x' && file[i][j] != ',' &&
				file[i][j] != '-' &&
				(file[i][j] < 'A' || file[i][j] > 'F') &&
				(file[i][j] < 'a' || file[i][j] > 'f') &&
				(file[i][j] < '0' || file[i][j] > '9'))
			{
				ft_putstr("Error. Found wrong character - '");
				ft_putchar(file[i][j]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int					ft_validation(t_fdf *fdf, char **file)
{
	if (ft_check_length(file, fdf) < 0)
	{
		ft_putendl("Found wrong line length. Exiting.");
		return (-1);
	}
	if (ft_check_char(file) < 0)
	{
		ft_putendl("'. Allowed characters are:\n"
			"0-9, A-F, a-f, space, Enter and color.\nExiting.");
		return (-1);
	}
	if (ft_check_correct_color(file) < 0)
	{
		ft_putendl("Error. Invalid color parametr");
		return (-1);
	}
	return (0);
}
