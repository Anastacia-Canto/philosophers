/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:32 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/04 19:40:25 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	long long		start;
	long long		now;
	int				alive;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				times_must_eat;
	pthread_mutex_t	*forks;
}	t_data;

t_data		*data(void);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(char c);
void		*hello_philo(void *args);
void		parse_info(char **argv);
void		create_philos(void);
long long	timer(void);
/*Routine*/
void	take_fork(t_philo *philo, int position);
void	leave_fork(int left, int right);
void	to_eat(t_philo *philo);
void	to_sleep(t_philo *philo);
void	to_wait(long long time);
void	free_all(t_philo *philo);

#endif