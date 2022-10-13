/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/13 13:28:25 by anastacia        ###   ########.fr       */
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
		check_meals(philo);
		take_forks(philo, philo->right, &philo->right_status);
		if (data()->nb_philo == 1)
			to_wait(data()->time_to_die);
		take_forks(philo, philo->left, &philo->left_status);
		to_eat(philo);
		leave_forks(philo, &philo->left_status, &philo->right_status);
		to_sleep_and_think(philo);
		check_meals(philo);
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
			return (NULL);
		}
	}
	return (NULL);
}

int	create_threads(void)
{
	t_philo		*philo;
	int			i;
	pthread_t	monitor;

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
		pthread_create(&monitor, NULL, check, &philo[i]);
		pthread_detach(monitor);
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
