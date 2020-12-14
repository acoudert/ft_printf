/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:04:35 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 12:52:09 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parser(t_data *data, va_list args, char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			data->count += 1;
		}
		else
		{
			ft_init_flags(data);
			if (!(i = ft_flags(data, format, i, args)))
				return (0);
			if (!(ft_args(data, args)))
				return (0);
		}
		i++;
	}
	return (1);
}
