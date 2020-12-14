/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:54:28 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 12:54:53 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_s_nb(long long nb, int len)
{
	char	*str;
	int		i;

	i = len;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return ;
	if (nb == -9223372036854775807)
	{
		str[--i] = '7';
		nb = nb / 10;
	}
	if (nb < 0)
		nb = nb * (-1);
	while (--i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	while (++i < len)
		ft_putchar(str[i]);
	free(str);
}

void	ft_put_u_nb(unsigned long long nb, int len)
{
	char	*str;
	int		i;

	i = len;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return ;
	while (--i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	while (++i < len)
		ft_putchar(str[i]);
	free(str);
}

void	ft_put_hex(unsigned long long nb, int len, int type)
{
	char	*str;
	char	*conv;
	int		i;

	i = len;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return ;
	conv = (!type) ? "0123456789abcdef" : "0123456789ABCDEF";
	while (--i >= 0)
	{
		str[i] = conv[nb % 16];
		nb = nb / 16;
	}
	while (++i < len)
		ft_putchar(str[i]);
	free(str);
}
