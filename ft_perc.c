/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:49:23 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 17:25:23 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_perc(t_data *data, void *arg)
{
	(void)arg;
	(data->indic != '-' && data->indic != '0') ?
		ft_put_nspace(data->width - 1) : 0;
	(data->indic != '-' && data->indic == '0') ?
		ft_put_s_nb(0, data->width - 1) : 0;
	ft_putchar('%');
	(data->indic == '-') ? ft_put_nspace(data->width - 1) : 0;
	data->curr_len = (data->width > 1) ? data->width : 1;
}
