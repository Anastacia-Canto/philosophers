/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:28 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/13 15:37:06 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophers(void *args)
{
	t_philo	*philo;

	philo = args;
	init_philos(philo);
	while (!philo->finish && !data()->death)
	{
		take_forks(philo, philo->right, &philo->right_status);
		if (data()->nb_philo == 1)
			to_wait(data()->time_to_die);
		take_forks(philo, philo->left, &philo->left_status);
		to_eat(philo);
		leave_forks(philo, &philo->left_status, &philo->right_status);
		to_sleep_and_think(philo);
	}
	return (NULL);
}

void	init_philos(t_philo *philo)
{
	philo->start = timer();
	philo->last_meal = philo->start;
	philo->finish = 0;
	define_forks(philo);
}

void	*check(void *args)
{
	t_philo	*philo;

	philo = args;
	while (!philo->finish && !data()->death)
	{
		if (timer() - philo->last_meal >= data()->time_to_die)
		{
			data()->death = 1;
			printf("%lld %d died\n", (timer() - philo->start), philo->id);
		}
	}
	return (NULL);
}
