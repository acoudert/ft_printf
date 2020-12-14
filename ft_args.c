/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:23:57 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 12:57:14 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_def_dbl_ft(t_data *data, va_list args)
{
	double	d;

	d = va_arg(args, double);
	if (data->type == 'f')
		ft_f(data, d, 1);
	else if (data->type == 'g')
		ft_g(data, d);
	else if (data->type == 'e')
		ft_e(data, d, 1);
}

int		ft_args(t_data *data, va_list args)
{
	t_ft	*ft_tab;
	void	*arg;
	int		i;

	i = 0;
	if (!(ft_tab = (t_ft*)malloc(sizeof(t_ft) * FT_TAB_SIZE)))
		return (0);
	ft_init_ft_tab(ft_tab);
	while (i < FT_TAB_SIZE && ft_tab[i].type != data->type)
		i++;
	if (data->type != 'f' && data->type != 'g' && data->type != 'e')
	{
		arg = (data->type != '%') ? va_arg(args, void*) : (void*)0;
		ft_tab[i].ft(data, arg);
	}
	else
		ft_def_dbl_ft(data, args);
	data->count += data->curr_len;
	free(ft_tab);
	return (1);
}
