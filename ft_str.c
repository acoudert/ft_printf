/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:22:19 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 17:27:20 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str(t_data *data, void *arg)
{
	char	*str;
	int		len;
	int		null;

	str = (char*)arg;
	null = (!str) ? 1 : 0;
	str = (null) ? "(null)" : str;
	len = ft_strlen(str);
	len = (data->dot == '.' && data->prec < len) ? data->prec : len;
	(data->indic != '-' && data->indic != '0') ?
		ft_put_nspace(data->width - len) : 0;
	(data->indic != '-' && data->indic == '0') ?
		ft_put_s_nb(0, data->width - len) : 0;
	ft_put_nstr(str, len);
	(data->indic == '-') ? ft_put_nspace(data->width - len) : 0;
	data->curr_len = (data->width > len) ? data->width : len;
}
