/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:35:52 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/19 18:46:23 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' ||
		*str == '\r' ||
		*str == '\v' ||
		*str == '\f' ||
		*str == '\t' ||
		*str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + (*str++ - '0');
	return (nbr * sign);
}
