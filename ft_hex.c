/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:27:20 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 12:52:57 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(t_data *data, void *arg)
{
	unsigned long long	nb;
	int					len;
	int					prefix;

	nb = ft_u_nb_cast(data->size, &arg);
	prefix = (data->indic == '#') ? 2 : 0;
	len = ft_hex_len(nb);
	len = (len == 0 && data->dot != '.') ? len + 1 : len;
	len = (data->dot == '.' && data->prec > len) ? data->prec : len;
	len = (data->indic == '0' && data->dot != '.'
			&& data->width > len) ? data->width : len;
	(data->indic != '-') ? ft_put_nspace(data->width - (prefix + len)) : 0;
	(prefix && data->type == 'x') ? ft_put_nstr("0x", 2) : 0;
	(prefix && data->type == 'X') ? ft_put_nstr("0X", 2) : 0;
	(data->type == 'x') ? ft_put_hex(nb, len, 0) : ft_put_hex(nb, len, 1);
	(data->indic == '-') ? ft_put_nspace(data->width - (prefix + len)) : 0;
	data->curr_len = (data->width > prefix + len) ? data->width : prefix + len;
}
