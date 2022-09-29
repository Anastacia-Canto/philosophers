/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:32 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/29 18:20:22 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int	forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_data;

typedef struct s_philo
{
	int		id;
	t_data	data;
}	t_philo;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	*hello_philo(void *args);
void	parse_info(char **argv, t_data *data);
void	create_philos(int amount, t_data *data);

#endif