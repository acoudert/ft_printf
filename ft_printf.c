/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 08:54:35 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/26 14:20:07 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data		data;
	va_list		args;

	ft_init_data_struct(&data);
	if (format)
	{
		va_start(args, format);
		if (!ft_parser(&data, args, (char*)format))
			return (-1);
		va_end(args);
	}
	return (data.count);
}
