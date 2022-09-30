/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:21:19 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/30 17:24:42 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t')
		|| (c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				nb;
	int				i;
	int				minus;

	minus = 1;
	nb = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb * minus);
}
