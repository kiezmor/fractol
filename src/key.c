/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:30:23 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/27 16:55:07 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractale_function(t_env *e)
{
	if (e->fract == 1)
		fractale_man(e);
	else if (e->fract == 2)
		fractale_jul(e);
	else if (e->fract == 3)
		fractale_bship(e);
	else if (e->fract == 4)
		fractale_man2(e, 0, 0, 0);
	else if (e->fract == 5)
		fractale_man4(e, 0, 0, 0);
	else if (e->fract == 6)
		fractale_newton_love(e, 0);
	else if (e->fract == 7)
		fractale_newton(e, 0);
	else if (e->fract == 8)
		fractale_tricorn(e);
	else
		fractale_mandelbar4(e, 0, 0, 0);
}

void		change(t_env *e)
{
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp),
			&(e->img_line), &(e->end));
	fractale_function(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	menu(e);
	mlx_destroy_image(e->mlx, e->data_img);
}

int			mouse_zoom(int key, int x, int y, t_env *e)
{
	double	tmpx;
	double	tmpy;

	tmpx = x / e->zoom + e->x1;
	tmpy = y / e->zoom + e->y1;
	if (key == IN)
		e->zoom /= 1.1;
	else if (key == OUT)
		e->zoom *= 1.1;
	e->x1 = tmpx - (x / e->zoom);
	e->y1 = tmpy - (y / e->zoom);
	change(e);
	return (0);
}

int			mouse_change(int x, int y, t_env *e)
{
	if (x < X && x > 0 && y < Y && y > 0)
	{
		e->rc = (float)(x + 400 - X) / 500;
		e->ic = (float)(y + 400 - Y) / 500;
	}
	change(e);
	return (0);
}

int			key(int key, t_env *e)
{
	e->y1 += (key == UP) ? 0.1 : 0;
	e->y1 -= (key == DOWN) ? 0.1 : 0;
	e->x1 += (key == LEFT) ? 0.1 : 0;
	e->x1 -= (key == RIGHT) ? 0.1 : 0;
	e->zoom *= (key == PLUS) ? 1.1 : 1;
	e->zoom /= (key == MOIN) ? 1.1 : 1;
	e->i += (key == P_ITERATION) ? 5 : 0;
	e->i -= (key == N_ITERATION) ? 5 : 0;
	(key == RESET) ? init_val(e) : 0;
	swap(key, e);
	change(e);
	(key == ESC) ? exit(2) : 0;
	return (0);
}
