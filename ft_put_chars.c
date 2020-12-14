/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:54:08 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 12:55:12 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_nspace(int n)
{
	while (n > 0)
	{
		ft_putchar(' ');
		n--;
	}
}

void	ft_put_nstr(char *str, int len)
{
	while (len > 0)
	{
		ft_putchar(*str);
		str++;
		len--;
	}
}
