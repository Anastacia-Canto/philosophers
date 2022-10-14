/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:39:51 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/14 15:43:59 by anastacia        ###   ########.fr       */
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
	{
		philo->right = 0;
		philo->left = philo->id - 1;
	}
	philo->left_status = false;
	philo->right_status = false;
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (!philo->left_status && !philo->right_status)
	{
		pthread_mutex_lock(&data()->forks[philo->right]);
		philo->right_status = true;
		print(philo, "has taken a fork");
		if (data()->nb_philo == 1)
			return (0);
		pthread_mutex_lock(&data()->forks[philo->left]);
		philo->left_status = true;
		print(philo, "has taken a fork");
	}
	return (0);
}

int	to_eat(t_philo *philo)
{
	if (philo->left_status && philo->right_status)
	{
		if (philo->meals == 0 || philo->meals < data()->nb_meals)
		{
			print(philo, "is eating");
			philo->last_meal = timer();
			to_wait(data()->time_to_eat);
		}
		if (data()->nb_meals != 0)
			philo->meals++;
		check_meals(philo);
	}
	return (0);
}

int	leave_forks(t_philo *philo)
{
	if (philo->left_status == true)
	{
		pthread_mutex_unlock(&data()->forks[philo->left]);
		philo->left_status = false;
	}
	if (philo->right_status == true)
	{
		pthread_mutex_unlock(&data()->forks[philo->right]);
		philo->right_status = false;
	}
	return (0);
}

int	to_sleep_and_think(t_philo *philo)
{	
	print(philo, "is sleeping");
	to_wait(data()->time_to_sleep);
	print(philo, "is thinking");
	return (0);
}
