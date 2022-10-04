/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:36:45 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/04 19:47:09 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_info(char **argv)
{
	data()->nb_philos = ft_atoi(argv[1]);
	data()->time_to_die = ft_atoi(argv[2]);
	data()->time_to_eat = ft_atoi(argv[3]);
	data()->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data()->times_must_eat = ft_atoi(argv[5]);
	else
		data()->times_must_eat = 0;
	create_philos();
}

void	create_philos(void)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo) * data()->nb_philos);
	data()->forks = malloc(sizeof(pthread_mutex_t) * data()->nb_philos);
	if (!philo || !data()->forks)
		return ;
	i = 0;
	while (i < data()->nb_philos)
	{
		pthread_mutex_init(&data()->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data()->nb_philos)
	{
		philo[i].id = i + 1;
		pthread_create(&philo[i].tid, NULL, hello_philo, (void *)&philo[i]);
		// usleep(300000);
		i++;
	}
	i = 0;
	while (i < data()->nb_philos)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	i = 0;
	while (i < data()->nb_philos)
	{
		pthread_mutex_destroy(&data()->forks[i]);
		i++;
	}
	free_all(philo);
}
