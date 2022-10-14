/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:09:03 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/13 12:40:06 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse(char **argv)
{
	data()->nb_philo = ft_atoi(argv[1]);
	data()->time_to_die = ft_atoi(argv[2]);
	data()->time_to_eat = ft_atoi(argv[3]);
	data()->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data()->nb_meals = ft_atoi(argv[5]);
	else
		data()->nb_meals = 0;
	data()->death = 0;
	create_threads();
}
