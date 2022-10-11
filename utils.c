/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:54:02 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/11 16:00:34 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&data()->mutex_death);
	if (data()->death == false)
		printf("%lld %d %s\n", (timer() - philo->start), philo->id, msg);
	pthread_mutex_unlock(&data()->mutex_death);
}

void	to_wait(long long time)
{
	long long	initial_time;
	long long	actual_time;

	initial_time = timer();
	actual_time = initial_time;
	while (actual_time - initial_time < time)
		actual_time = timer();
	return ;
}

int	check_meals(t_philo *philo)
{
	if (timer() - philo->last_meal >= data()->time_to_die)
	{
		print(philo, "died");
		data()->death = true;
		return (1);
	}
	if (philo->meals == data()->nb_meals && philo->meals > 0)
	{
		philo->finish = true;
		return (1);
	}
	return (0);
}
