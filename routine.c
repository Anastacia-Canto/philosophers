/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:39:51 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/13 15:01:31 by anastacia        ###   ########.fr       */
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

int	take_forks(t_philo *philo, int position, int *status)
{
	if (!philo->finish && !data()->death)
	{
		if (pthread_mutex_lock(&data()->forks[position]) == 0)
		{
			*status = true;
			print(philo, "has taken a fork");
			return (0);
		}
	}
	return (0);
}

int	to_eat(t_philo *philo)
{
	if (!philo->finish && !data()->death)
	{
		if (philo->meals == 0 || philo->meals <= data()->nb_meals)
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

int	leave_forks(t_philo *philo, int *l_status, int *r_status)
{
	if (*l_status == true)
	{
		pthread_mutex_unlock(&data()->forks[philo->left]);
		*l_status = false;
	}
	if (*r_status == true)
	{
		pthread_mutex_unlock(&data()->forks[philo->right]);
		*r_status = false;
	}
	return (0);
}

int	to_sleep_and_think(t_philo *philo)
{	
	if (!philo->finish && !data()->death)
	{
		print(philo, "is sleeping");
		to_wait(data()->time_to_sleep);
		print(philo, "is thinking");
	}
	return (0);
}
