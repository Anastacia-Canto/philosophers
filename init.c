/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/14 15:27:08 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(void)
{
	t_philo		*philo;
	int			i;

	philo = data()->philo;
	philo = malloc(sizeof(t_philo) * data()->nb_philo);
	data()->forks = malloc(sizeof(pthread_mutex_t) * data()->nb_philo);
	if (!philo || !data()->forks)
		return (0);
	init_mutexes();
	i = -1;
	while (++i < data()->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		pthread_create(&philo[i].tid, NULL, philosophers, &philo[i]);
		pthread_create(&philo[i].monitor, NULL, check, &philo[i]);
	}
	join_destroy_free(philo);
	return (0);
}

void	init_mutexes(void)
{
	int	i;

	pthread_mutex_init(&data()->mutex_death, NULL);
	i = -1;
	while (++i < data()->nb_philo)
		pthread_mutex_init(&data()->forks[i], NULL);
}

void	join_destroy_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data()->nb_philo)
	{
		pthread_join(philo[i].tid, NULL);
		pthread_join(philo[i].monitor, NULL);
	}
	i = -1;
	while (++i < data()->nb_philo)
		pthread_mutex_destroy(&data()->forks[i]);
	pthread_mutex_destroy(&data()->mutex_death);
	free (data()->forks);
	free (philo);
}
