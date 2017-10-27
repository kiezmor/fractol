/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:31:04 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/27 16:55:12 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			swap(int key, t_env *e)
{
	if (key == CHANGE)
	{
		if (e->fract < 9)
			e->fract++;
		else
			e->fract = 1;
	}
	if (key == PREV)
	{
		if (e->fract != 1)
			e->fract--;
		else
			e->fract = 9;
	}
	init_val(e);
}

static void		name(t_env *e)
{
	if (e->fract == 1)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF,
		"1 Mandelbrot");
	else if (e->fract == 2)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF, "2 Julia");
	else if (e->fract == 3)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF,
		"3 Burning Ship");
	else if (e->fract == 4)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF,
		"4 Mandelbrot P3");
	else if (e->fract == 5)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF,
		"5 Mandelbrot P4");
	else if (e->fract == 6)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF, "6 Newton V1");
	else if (e->fract == 7)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF, "7 Newton V2");
	else if (e->fract == 8)
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF,
		"8 Mandelbar V1");
	else
		mlx_string_put(e->mlx, e->win, (X - 285), 340, 0XFFFFFF,
		"9 Mandelbar V2");
}

void			menu(t_env *e)
{
	name(e);
	mlx_string_put(e->mlx, e->win, (X - 285), 360, 0XFFFFFF, "Zoom: +/-");
	mlx_string_put(e->mlx, e->win, (X - 285), 400, 0XFFFFFF, "Iteration: 1/4");
	mlx_string_put(e->mlx, e->win, (X - 285), 380, 0XFFFFFF, "Reset: 2");
	mlx_string_put(e->mlx, e->win, (X - 285), 420, 0XFFFFFF, "Next: 3");
	mlx_string_put(e->mlx, e->win, (X - 285), 440, 0XFFFFFF, "Prev: 6");
}
