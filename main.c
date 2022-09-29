/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:28 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/29 18:21:41 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*hello_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	sleep(2);
	printf("Hello, I am philo #%d\n", philo->id);
	printf("time to eat: %d\n", philo->data.time_to_eat);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data			data;
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	if (argc == 5 || argc == 6)
		parse_info(argv, &data);
	else
	{
		printf("Incorrect arguments!\n");
		printf("Usage:\n./philo [number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep]");
		printf(" [number_of_times_each_philosopher_must_eat](optional)\n");
	}
	gettimeofday(&end, NULL);
	printf("time: %ld\n", ((end.tv_sec * 1000) - (start.tv_sec * 1000)));
	return (0);
}
