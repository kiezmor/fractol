/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale_b2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:32:45 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/27 16:02:04 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractale_man2(t_env *e, float tmp, float rz, float iz)
{
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rc = e->x / e->zoom + e->x1;
			e->ic = e->y / e->zoom + e->y1;
			e->rz = 0;
			e->iz = 0;
			e->a = 0;
			while (e->a < e->i && e->rz * e->rz + e->iz * e->iz < 4)
			{
				tmp = e->rz;
				rz = e->rz * e->rz;
				iz = e->iz * e->iz;
				e->rz = rz * e->rz - 3 * e->rz * iz + e->rc;
				e->iz = 3 * rz * e->iz - iz * e->iz + e->ic;
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void		fractale_man4(t_env *e, float tmp, float rz, float iz)
{
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rc = e->x / e->zoom + e->x1;
			e->ic = e->y / e->zoom + e->y1;
			e->rz = 0;
			e->iz = 0;
			e->a = 0;
			while (e->a < e->i && e->rz * e->rz + e->iz * e->iz < 4)
			{
				tmp = e->rz;
				rz = tmp * tmp;
				iz = e->iz * e->iz;
				e->rz = rz * rz - 6 * rz * iz + iz * iz + e->rc;
				e->iz = 4 * rz * tmp * e->iz - 4 * tmp * iz * e->iz + e->ic;
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}
