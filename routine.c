/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:36:29 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/04 19:49:57 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo, int position)
{	
	if (pthread_mutex_lock(&data()->forks[position]) == 0)
	{
		philo->now = timer();
		printf("%lld %d has taken a fork\n", (philo->now - philo->start), philo->id);
	}
	else
		return ;
}

void	leave_fork(int left, int right)
{
	pthread_mutex_unlock(&data()->forks[left]);
	pthread_mutex_unlock(&data()->forks[right]);
}

void	to_eat(t_philo *philo)
{
	philo->now = timer();
	printf("%lld %d is eating\n", (philo->now - philo->start), philo->id);
	to_wait(data()->time_to_eat);
	return ;
}

void	to_sleep(t_philo *philo)
{
	philo->now = timer();
	printf("%lld %d is sleeping\n", (philo->now - philo->start), philo->id);
	to_wait(data()->time_to_sleep);
	philo->now = timer();
	printf("%lld %d is thinking\n", (philo->now - philo->start), philo->id);
}
