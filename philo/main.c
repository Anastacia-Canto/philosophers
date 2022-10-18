/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:58:03 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/07 14:44:41 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if ((argc == 5 || argc == 6) && ft_atoi(argv[1]) > 0)
		parse(argv);
	else
	{
		printf("Incorrect arguments!\nUsage:\n");
		printf("./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("number_of_times_each_philosopher_must_eat");
		printf("[optional]\n");
	}
	return (0);
}
