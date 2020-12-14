/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:31:05 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 13:06:33 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_data_struct(t_data *data)
{
	data->count = 0;
	data->curr_len = 0;
	data->indic = 0;
	data->width = 0;
	data->dot = 0;
	data->prec = 0;
	data->size[0] = 0;
	data->size[1] = 0;
	data->type = 0;
}

void	ft_init_flags(t_data *data)
{
	data->curr_len = 0;
	data->indic = 0;
	data->width = 0;
	data->dot = 0;
	data->prec = 0;
	data->size[0] = 0;
	data->size[1] = 0;
	data->type = 0;
}

void	ft_init_ft_tab(t_ft *ft_tab)
{
	ft_tab[0].type = 'c';
	ft_tab[0].ft = &ft_char;
	ft_tab[1].type = 's';
	ft_tab[1].ft = &ft_str;
	ft_tab[2].type = 'p';
	ft_tab[2].ft = &ft_ptr;
	ft_tab[3].type = 'd';
	ft_tab[3].ft = &ft_s_nb;
	ft_tab[4].type = 'i';
	ft_tab[4].ft = &ft_s_nb;
	ft_tab[5].type = 'u';
	ft_tab[5].ft = &ft_u_nb;
	ft_tab[6].type = 'x';
	ft_tab[6].ft = &ft_hex;
	ft_tab[7].type = 'X';
	ft_tab[7].ft = &ft_hex;
	ft_tab[8].type = '%';
	ft_tab[8].ft = &ft_perc;
	ft_tab[9].type = 'n';
	ft_tab[9].ft = &ft_n;
}
