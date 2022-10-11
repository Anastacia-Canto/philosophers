/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/11 14:16:36 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophers(void *args)
{
	t_philo	*philo;

	philo = args;
	init_philos(philo);
	while (data()->death == false && philo->finish == false)
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
	philo->finish = false;
	define_forks(philo);
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
	init_mutexes();
	i = -1;
	while (++i < data()->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		pthread_create(&philo[i].tid, NULL, philosophers, &philo[i]);
	}
	i = -1;
	while (++i < data()->nb_philo)
		pthread_join(philo[i].tid, NULL);
	destroy_mutexes();
	free (data()->forks);
	free (philo);
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

void	destroy_mutexes(void)
{
	int	i;

	pthread_mutex_destroy(&data()->mutex_death);
	i = -1;
	while (++i < data()->nb_philo)
		pthread_mutex_destroy(&data()->forks[i]);
}
