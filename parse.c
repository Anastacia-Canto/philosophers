/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:36:45 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/29 17:34:14 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_info(char **argv, t_data *data)
{
	data->forks = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->times_must_eat = ft_atoi(argv[5]);
	create_philos(data->forks, data);
}

void	create_philos(int amount, t_data *data)
{
	pthread_t	*id;
	int			i;
	t_philo		*philo;

	id = malloc(sizeof(pthread_t) * amount);
	philo = malloc(sizeof(t_philo) * amount);
	if (!id || !philo)
		return ;
	i = 0;
	while (i < amount)
	{
		philo[i].id = i + 1;
		philo[i].data = *data;
		pthread_create(&id[i], NULL, hello_philo, (void *)&philo[i]);
		pthread_join(id[i], NULL);
		i++;
	}
	free (id);
	free (philo);
}
