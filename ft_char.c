/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:36:38 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 17:32:52 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_data *data, void *arg)
{
	char	*c;

	c = (char*)&arg;
	(data->indic != '-' && data->indic != '0') ?
		ft_put_nspace(data->width - 1) : 0;
	(data->indic != '-' && data->indic == '0') ?
		ft_put_s_nb(0, data->width - 1) : 0;
	ft_putchar(*c);
	(data->indic == '-') ? ft_put_nspace(data->width - 1) : 0;
	data->curr_len = (data->width > 1) ? data->width : 1;
}
