/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:13:09 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/26 11:30:46 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_s_nb_cast(char *size, void *nb)
{
	int					*i;
	char				*c;
	short				*s;
	long long			*ll;
	long				*l;

	i = (int*)nb;
	c = (char*)nb;
	s = (short*)nb;
	ll = (long long*)nb;
	l = (long*)nb;
	if (size[0] == 0)
		return (*i);
	else if (size[0] == 'h' && size[1] == 'h')
		return (*c);
	else if (size[0] == 'h')
		return (*s);
	if (size[0] == 'l' && size[1] == 'l')
		return (*ll);
	else if (size[0] == 'l')
		return (*l);
	return (0);
}

unsigned long long	ft_u_nb_cast(char *size, void *nb)
{
	unsigned int		*i;
	unsigned char		*c;
	unsigned short		*s;
	unsigned long long	*ll;
	unsigned long		*l;

	i = (unsigned int*)nb;
	c = (unsigned char*)nb;
	s = (unsigned short*)nb;
	ll = (unsigned long long*)nb;
	l = (unsigned long*)nb;
	if (size[0] == 0)
		return (*i);
	else if (size[0] == 'h' && size[1] == 'h')
		return (*c);
	else if (size[0] == 'h')
		return (*s);
	if (size[0] == 'l' && size[1] == 'l')
		return (*ll);
	else if (size[0] == 'l')
		return (*l);
	return (0);
}
