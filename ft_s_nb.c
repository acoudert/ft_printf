/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:09:24 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 11:30:36 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_nb(t_data *data, void *arg)
{
	long long	nb;
	int			len;
	int			sign;

	nb = ft_s_nb_cast(data->size, &arg);
	sign = (nb < 0) ? 1 : 0;
	sign = (data->indic == '+') ? 1 : sign;
	sign = (data->indic == ' ') ? 1 : sign;
	len = ft_s_nb_len(nb);
	len = (len == 0 && data->dot != '.') ? len + 1 : len;
	len = (data->dot == '.' && data->prec > len) ? data->prec : len;
	len = (data->indic == '0' && data->dot != '.'
			&& data->width > len) ? data->width - sign : len;
	(data->indic != '-') ? ft_put_nspace(data->width - (sign + len)) : 0;
	(nb < 0) ? ft_putchar('-') : 0;
	(nb > 0 && data->indic == '+') ? ft_putchar('+') : 0;
	(nb > 0 && data->indic == ' ') ? ft_putchar(' ') : 0;
	ft_put_s_nb(nb, len);
	(data->indic == '-') ? ft_put_nspace(data->width - (sign + len)) : 0;
	data->curr_len = (data->width > sign + len) ? data->width : sign + len;
}
