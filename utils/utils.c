/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:23:57 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/04 17:55:49 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

long long	timer(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	to_wait(long long time)
{
	long long	actual_time;
	long long	initial_time;

	initial_time = timer();
	actual_time = timer();
	while (actual_time - initial_time <= time)
		actual_time = timer();
	return ;
}

void	free_all(t_philo *philo)
{
	free (philo);
}
