/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:50:23 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/29 16:50:24 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arrdup(const char **arr)
{
	ssize_t len;
	char	**new;

	if (!arr)
		return (NULL);
	len = ft_arrlen(arr);
	if (!(new = ft_arrnew((size_t)len)))
		return (NULL);
	if (!(ft_arrcpy(new, arr)))
	{
		ft_free(new);
		return (NULL);
	}
	return (new);
}
