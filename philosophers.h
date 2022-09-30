/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:32 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/30 18:02:44 by anastacia        ###   ########.fr       */
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
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				times_must_eat;
	int				*forks;
	pthread_mutex_t	*mutex;
}	t_data;

t_data		*data(void);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(char c);
void		*hello_philo(void *args);
void		parse_info(char **argv);
void		create_philos(int amount);
long long	timer(void);
/*Routine*/
int		take_fork(t_philo *philo, int signal);
void	eat(t_philo *philo);
void	nap_time(t_philo *philo);
void	to_wait(long long time);
void	free_all(t_philo *philo);

#endif