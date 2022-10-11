/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/11 12:01:58 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophers(void *args)
{
	t_philo	*philo;

	philo = args;
	philo->start = timer();
	philo->last_meal = philo->start;
	define_forks(philo);
	while (data()->death == false)
	{
		if (philo->id == data()->nb_philo)
		{
			take_forks(philo, philo->left);
			if (data()->nb_philo == 1)
			{
				pthread_mutex_unlock(&data()->forks[philo->left]);
				to_wait(data()->time_to_die);
				print(philo, "died");
				break ;
			}
			take_forks(philo, philo->right);
		}
		else
		{
			take_forks(philo, philo->right);
			take_forks(philo, philo->left);
		}
		to_eat(philo);
		to_sleep_and_think(philo);
	}
	return (NULL);
}

int	create_threads(void)
{
	t_philo		*philo;
	int			i;

	philo = data()->philo;
	philo = malloc(sizeof(t_philo) * data()->nb_philo);
	data()->forks = malloc(sizeof(pthread_mutex_t) * data()->nb_philo);
	if (!philo || !data()->forks)
		return (0);
	pthread_mutex_init(&data()->mutex_death, NULL);
	i = -1;
	while (++i < data()->nb_philo)
		pthread_mutex_init(&data()->forks[i], NULL);
	i = -1;
	while (++i < data()->nb_philo)
	{
		philo[i].id = i + 1;
		pthread_create(&philo[i].tid, NULL, philosophers, &philo[i]);
	}
	i = -1;
	while (++i < data()->nb_philo)
		pthread_join(philo[i].tid, NULL);
	pthread_mutex_destroy(&data()->mutex_death);
	i = -1;
	while (++i < data()->nb_philo)
		pthread_mutex_destroy(&data()->forks[i]);
	free (data()->forks);
	free (philo);
	return (0);
}
