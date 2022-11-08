/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:33:58 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/08 14:34:03 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define SUCCESS 0
# define FAILURE 1
# define MALLOC_FAILURE 2

typedef struct timeval	t_time;

enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	UNLOCK,
	LOCK
};

typedef struct s_philo
{
	int					name;
	unsigned long long	eat_time;
	pthread_mutex_t		*my_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			philo_t;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					min_eat;
	int					all_eated;
	int					total_eat;
	int					is_dead;
	int					ph_name;
	unsigned long long	start_time;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_philo				**ph;
}	t_data;

//INIT DATA
t_data				*init_gobal_data(int argc, char **argv);

//UTILS
long long			ft_atoi(const char *str);
unsigned long long	ft_get_time(void);

//PROTECTION
int					ft_args_protection(int argc, char **argv);

//PRINT STATUS
void				print_status(t_data *data, t_philo *philo, int status);

#endif
