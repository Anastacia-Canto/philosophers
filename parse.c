/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:36:45 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/30 17:41:04 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_info(char **argv)
{
	int				i;

	data()->nb_philos = ft_atoi(argv[1]);
	data()->time_to_die = ft_atoi(argv[2]);
	data()->time_to_eat = ft_atoi(argv[3]);
	data()->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data()->times_must_eat = ft_atoi(argv[5]);
	else
		data()->times_must_eat = 0;
	data()->forks = malloc(sizeof(int) * (ft_atoi(argv[1])));
	data()->mutex = malloc(sizeof(pthread_mutex_t) * (ft_atoi(argv[1])));
	if (!data()->forks || !data()->mutex)
		return ;
	i = 0;
	while (i++ < data()->nb_philos)
	{
		data()->forks[i] = i;
		pthread_mutex_init(&data()->mutex[i], NULL);
	}
	create_philos(data()->nb_philos);
}

void	create_philos(int amount)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo) * amount);
	if (!philo)
		return ;
	i = 0;
	while (i < amount)
	{
		philo[i].id = i + 1;
		pthread_create(&philo[i].tid, NULL, hello_philo, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while (i < amount)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	free_all(philo);
}
