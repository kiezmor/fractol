/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:31:04 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/28 20:57:09 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			swap(int key, t_env *e)
{
	if (key == NEXT)
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
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF,
		"1 Mandelbrot");
	else if (e->fract == 2)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF, "2 Julia");
	else if (e->fract == 3)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF,
		"3 Burning Ship");
	else if (e->fract == 4)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF,
		"4 Mandelbrot P3");
	else if (e->fract == 5)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF,
		"5 Mandelbrot P4");
	else if (e->fract == 6)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF, "6 Newton V1");
	else if (e->fract == 7)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF, "7 Newton V2");
	else if (e->fract == 8)
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF,
		"8 Mandelbar V1");
	else
		mlx_string_put(e->mlx, e->win, (X - 285), 60, 0XFFFFFF,
		"9 Mandelbar V2");
}

void			menu(t_env *e)
{
	name(e);
	mlx_string_put(e->mlx, e->win, (X - 285), 80, 0XFFFFFF, "Zoom: +/-");
	mlx_string_put(e->mlx, e->win, (X - 285), 100, 0XFFFFFF, "Iteration: 1/4");
	mlx_string_put(e->mlx, e->win, (X - 285), 120, 0XFFFFFF, "Reset: 2");
	mlx_string_put(e->mlx, e->win, (X - 285), 140, 0XFFFFFF, "Change: 3/6");
}
