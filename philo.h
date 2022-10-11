/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:53:51 by anastacia         #+#    #+#             */
/*   Updated: 2022/10/11 10:47:13 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

enum e_bool
{
	false,
	true
};

typedef struct s_philo
{
	pthread_t	tid;
	int			id;
	long long	start;
	long long	last_meal;
	int			left;
	int			right;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				nb_meals;
	int				death;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_death;
}	t_data;

t_data		*data(void);
void		parse(char **argv);
void		*philosophers(void *args);
void		*check(void *args);
int			create_threads(void);
/*Routine*/
int			define_forks(t_philo *philo);
int			take_forks(t_philo *philo, int position);
int			to_eat(t_philo *philo);
int			to_sleep_and_think(t_philo *philo);
/*Utils*/
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
long long	timer(void);
void		print(t_philo *philo, char *msg);
void		to_wait(long long time);

#endif