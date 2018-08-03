/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:05:45 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/03 20:11:54 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t len;

	len = 0;
	i = 0;
	len = ft_strlen(dest);
	ft_strcpy(&dest[len], src);
	return (dest);
}
