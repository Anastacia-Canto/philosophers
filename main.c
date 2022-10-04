/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:28 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/04 19:41:51 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*hello_philo(void *args)
{
	t_philo			*philo;
	int				left_fork;
	int				right_fork;

	philo = (t_philo *)args;
	philo->start = timer();
	left_fork = philo->id - 1;
	right_fork = (philo->id + 1) % data()->nb_philos;
	take_fork(philo, left_fork);
	take_fork(philo, right_fork);
	to_eat(philo);
	leave_fork(left_fork, right_fork);
	to_sleep(philo);
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
