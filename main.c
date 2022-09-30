/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:28 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/30 17:25:19 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*hello_philo(void *args)
{
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)args;
	gettimeofday(&time, NULL);
	philo->start = timer();
	eat(philo);
	nap_time(philo);
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		parse_info(argv);
	else
	{
		printf("Incorrect arguments!\n");
		printf("Usage:\n./philo [number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep]");
		printf(" [number_of_times_each_philosopher_must_eat](optional)\n");
	}
	return (0);
}
