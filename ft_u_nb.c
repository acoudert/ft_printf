/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:07:41 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/26 11:14:11 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_nb(t_data *data, void *arg)
{
	unsigned long long	nb;
	int					len;

	nb = ft_u_nb_cast(data->size, &arg);
	len = ft_u_nb_len(nb);
	len = (len == 0 && data->dot != '.') ? len + 1 : len;
	len = (data->dot == '.' && data->prec > len) ? data->prec : len;
	len = (data->indic == '0' && data->dot != '.'
			&& data->width > len) ? data->width : len;
	(data->indic != '-') ? ft_put_nspace(data->width - len) : 0;
	ft_put_u_nb(nb, len);
	(data->indic == '-') ? ft_put_nspace(data->width - len) : 0;
	data->curr_len = (data->width > len) ? data->width : len;
}
