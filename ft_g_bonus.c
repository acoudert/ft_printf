/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:53:32 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 13:53:33 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_g_update_prec(t_data *data, t_dbl *g)
{
	int		i;

	i = 0;
	while (g->n2 && g->n2 % 10 == 0)
	{
		g->n2 = g->n2 / 10;
		i++;
	}
	data->prec = (g->n2 == 0) ? 0 : i;
}

void	ft_g(t_data *data, double arg)
{
	t_dbl	f;
	t_dbl	e;

	f = ft_f(data, arg, 0);
	e = ft_e(data, arg, 0);
	if (e.n3 < 4 || e.n3 >= data->prec)
	{
		ft_g_update_prec(data, &e);
		ft_e(data, arg, 1);
	}
	else
	{
		ft_g_update_prec(data, &f);
		ft_f(data, arg, 1);
	}
}
