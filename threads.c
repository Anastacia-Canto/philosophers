/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:28 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/14 15:28:18 by anastacia        ###   ########.fr       */
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
		if (data()->nb_philo == 1)
		{
			take_forks(philo);
			to_wait(data()->time_to_die);
			leave_forks(philo);
			break ;
		}
		take_forks(philo);
		to_eat(philo);
		leave_forks(philo);
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
		usleep(8000);
		pthread_mutex_lock(&data()->mutex_death);
		if (timer() - philo->last_meal >= data()->time_to_die && !data()->death)
		{
			data()->death = 1;
			pthread_mutex_unlock(&data()->mutex_death);
			printf("%lld %d died\n", (timer() - philo->start), philo->id);
		}
		else
			pthread_mutex_unlock(&data()->mutex_death);
	}
	return (NULL);
}
