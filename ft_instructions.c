/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:26:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/20 19:26:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_inst(void)
{
	ft_putendl("For rotation:");
	ft_putendl("W, S - rotate x");
	ft_putendl("A, D - rotate y");
	ft_putendl("Q, E - rotate z\n");
	ft_putendl("For changing position:");
	ft_putendl("UP, DOWN, LEFT, RIGHT\n");
	ft_putendl("To change z value picture:");
	ft_putendl("+, -\n");
	ft_putendl("Enter - put picture to the center of the window\n");
	ft_putendl("Space - discard settings to beginning\n");
	ft_putendl("Mouse wheel to zoom\n");
	ft_putendl("ESC for exiting or press the cross\n");
	ft_putendl("--------------------");
}

void			ft_instructions(void)
{
	ft_putendl("--------------------\n");
	ft_putendl("Use key for:\n");
	ft_putendl("1 - 0 for change the color:");
	ft_putendl("1 - white");
	ft_putendl("2 - blue");
	ft_putendl("3 - green");
	ft_putendl("4 - red");
	ft_putendl("5 - cyan");
	ft_putendl("6 - gold");
	ft_putendl("7 - orange");
	ft_putendl("8 - purple");
	ft_putendl("9 - black");
	ft_putendl("0 - dark blue(or your color)\n");
	ft_inst();
}
