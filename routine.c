/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:36:29 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/30 18:05:43 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_philo *philo, int signal)
{
	int	id;

	philo->now = timer();
	id = philo->id;
	if (signal == 0)
	{
		if (pthread_mutex_lock(&data()->mutex[id]))
		{
			printf("%lld %d has taken a fork\n", (philo->now - philo->start), philo->id);
			return (1);
		}
	}
	else
	{
		if (id == 1)
		{
			if (pthread_mutex_lock(&data()->mutex[data()->nb_philos]))
			{
				printf("%lld %d has taken a fork\n", (philo->now - philo->start), philo->id);
				return (1);
			}
		}
		else
		{
			if (pthread_mutex_lock(&data()->mutex[id - 1]))
			{
				printf("%lld %d has taken a fork\n", (philo->now - philo->start), philo->id);
				return (1);
			}
		}
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (take_fork(philo, 0) == 1 && take_fork(philo, 1) == 1)
	{
		philo->now = timer();
		printf("%lld %d is eating\n", (philo->now - philo->start), philo->id);
		to_wait(data()->time_to_eat);
	}
}

void	nap_time(t_philo *philo)
{
	philo->now = timer();
	printf("%lld %d is sleeping\n", (philo->now - philo->start), philo->id);
	to_wait(data()->time_to_sleep);
	philo->now = timer();
	printf("%lld %d is thinking\n", (philo->now - philo->start), philo->id);
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
