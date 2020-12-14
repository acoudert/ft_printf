/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:58:14 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 17:30:44 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(t_data *data, void *arg)
{
	unsigned long long	nb;
	int					len;
	int					nil;
	int					space;

	nb = (unsigned long long)arg;
	nil = (!nb) ? 1 : 0;
	space = (data->indic == ' ') ? 1 : 0;
	len = ft_hex_len(nb);
	len = (len == 0 && data->dot != '.') ? len + 1 : len;
	len = (data->dot == '.' && data->prec > 2 + len) ? data->prec : len;
	len = (data->indic == '0' && data->dot != '.'
			&& data->width > 2 + len) ? data->width - space : len;
	len = (nil && data->dot == '.' && data->prec == 0) ? 0 : len;
	(data->indic != '-') ? ft_put_nspace(data->width - (space + 2 + len)) : 0;
	(!nil && space) ? ft_putchar(' ') : 0;
	ft_put_nstr("0x", 2);
	ft_put_hex(nb, len, 0);
	(data->indic == '-') ? ft_put_nspace(data->width - (space + 2 + len)) : 0;
	data->curr_len = (data->width > 2 + len) ? data->width : space + 2 + len;
}
