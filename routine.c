/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:39:51 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/07 17:08:10 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	define_forks(t_philo *philo)
{
	philo->left = philo->id;
	philo->right = philo->id - 1;
	if (philo->id == 1)
		philo->right = 0;
	if (philo->id == data()->nb_philo)
		philo->left = 0;
	return (0);
}

int	take_forks(t_philo *philo, int position)
{
	pthread_mutex_lock(&data()->forks[position]);
	print(philo, "has taken a fork");
	return (0);
}

int	to_eat(t_philo *philo)
{
	print(philo, "is eating");
	philo->last_meal = timer();
	to_wait(data()->time_to_eat);
	pthread_mutex_unlock(&data()->forks[philo->left]);
	pthread_mutex_unlock(&data()->forks[philo->right]);
	return (0);
}

int	to_sleep_and_think(t_philo *philo)
{
	print(philo, "is sleeping");
	to_wait(data()->time_to_sleep);
	print(philo, "is thinking");
	return (0);
}
