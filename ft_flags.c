/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:47:28 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 15:01:19 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_charset(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_itoa(int nb, char c)
{
	nb *= 10;
	nb += c - '0';
	return (nb);
}

int			ft_size(t_data *data, char *format, int i)
{
	if (format[i] == 'l')
	{
		data->size[0] = 'l';
		if (format[i + 1] == 'l')
		{
			data->size[1] = 'l';
			return (1);
		}
	}
	else if (format[i] == 'h')
	{
		data->size[0] = 'h';
		if (format[i + 1] == 'h')
		{
			data->size[1] = 'h';
			return (1);
		}
	}
	return (0);
}

void		ft_width_prec(t_data *data, char c, va_list args)
{
	if (c == '*')
	{
		if (data->dot == '.')
			data->prec = va_arg(args, int);
		else
		{
			data->width = va_arg(args, int);
			if (data->width < 0)
			{
				data->width = data->width * (-1);
				data->indic = '-';
			}
		}
	}
	else if (ft_in_charset(c, "0123456789"))
	{
		if (data->dot == '.')
			data->prec = ft_itoa(data->prec, c);
		else
			data->width = ft_itoa(data->width, c);
	}
}

int			ft_flags(t_data *data, char *format, int i, va_list args)
{
	i += 1;
	while (format[i] && !ft_in_charset(format[i], "cspdiuxXnfge%"))
	{
		if (data->indic == 0 && data->width == 0
				&& data->dot != '.' && ft_in_charset(format[i], "-# +0"))
			data->indic = format[i];
		else if (data->width == 0 && data->dot != '.'
				&& data->indic == '0' && format[i] == '-')
			data->indic = format[i];
		else if (format[i] == '.')
			data->dot = '.';
		else if (format[i] == '*' || ft_in_charset(format[i], "0123456789"))
			ft_width_prec(data, format[i], args);
		else if (ft_in_charset(format[i], "lh"))
			i += ft_size(data, format, i);
		i++;
	}
	if (!format[i])
		return (0);
	data->type = format[i];
	data->dot = (data->prec < 0) ? 0 : data->dot;
	data->prec = (data->prec < 0) ? 0 : data->prec;
	return (i);
}
