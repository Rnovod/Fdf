/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:50:46 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/08 17:50:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_open(char *namefile)
{
	int fd;

	if ((fd = open(namefile, O_RDONLY)) < 0)
		return (ft_error(errno));
	return (fd);
}

static	int		ft_read(const int fd, char ***file)
{
	ssize_t	ret;
	char	*buff;
	char	*tmp;
	char	*str;

	buff = ft_strnew(BUFF_SIZE);
	str = ft_strnew(0);
	if (!str || !buff)
		return (ft_error(ENOMEM));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = str;
		buff[ret] = '\0';
		if (!(str = ft_strjoin(str, buff)))
			return (ft_error(ENOMEM));
		free(tmp);
	}
	if (ret < 0)
		return (ft_error(errno));
	free(buff);
	if (!(*file = ft_strsplit(str, '\n')))
		return (ft_error(ENOMEM));
	free(str);
	return (0);
}

char			**ft_open_read(char *namefile)
{
	char	**file;
	int		fd;

	if ((fd = ft_open(namefile)) < 0)
		return (NULL);
	if (ft_read(fd, &file) < 0)
		return (NULL);
	if (close(fd) < 0)
	{
		ft_error(errno);
		return (NULL);
	}
	return (file);
}
