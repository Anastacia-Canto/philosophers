/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:28 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/29 17:28:06 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*hello_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	sleep(1);
	printf("Hello, I am philo #%d\n", philo->id);
	printf("time to eat: %d\n", philo->data.time_to_eat);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 5 || argc == 6)
		parse_info(argv, &data);
	return (0);
}
