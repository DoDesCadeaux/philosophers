/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:12:52 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/08 16:12:53 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*init_philo(int	philo_name)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->name = philo_name;
	philo->eat_time = ft_get_time();
	return (philo);
}

void	init_philo_fork(t_data *data, int philo_name)
{
	//Si il y'a que 1 philo, fork gauche = la premiere, donc la sienne.
	if (data->nb_philo == 1)
		data->ph[philo_name]->my_fork = &data->forks[0];
	else
	{
		//Si c'est le dernier philo, fork gauche = la sienne, et fork droite = premiere fork
		if (philo_name == data->nb_philo - 1)
		{
			data->ph[philo_name]->my_fork = &data->forks[philo_name];
			data->ph[philo_name]->right_fork = &data->forks[0];
		}
		//Pour tous les autres philos != dernier, fork gauche = la sienne, et fork droite = fork du prochain philo (philo + 1)
		else
		{
			data->ph[philo_name]->my_fork = &data->forks[philo_name];
			data->ph[philo_name]->right_fork = &data->forks[philo_name + 1];
		}
	}
}

int	init_philos_data(t_data *data)
{
	int	i;

	data->ph = malloc(sizeof(t_philo *) * data->nb_philo);
	if (!data->ph)
		return (MALLOC_FAILURE);
	memset(data->ph, 0, sizeof(t_philo *) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		data->ph[i] = init_philo(i + 1);
		if (!data->ph[i])
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		init_philo_fork(data, i);
//		protection = pthread_create(data->ph[i]->philo_t);
//		if (protection != 0)
//			return (FAILURE);
//		printf("Pthread #%d created\n", i);
		i++;
	}
	return (SUCCESS);
}

int	init_table_forks(t_data *data)
{
	int	protection;
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (MALLOC_FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		protection = pthread_mutex_init(data->forks, NULL);
		if (protection != 0)
			return (FAILURE);
		printf("Mutex %d initialized\n", i + 1);
		i++;
	}
	return (SUCCESS);
}

int	protected_init(t_data *data)
{
	int	protection;

	protection = pthread_mutex_init(&data->print, NULL);
	if (protection != 0)
		return (FAILURE);
	protection = init_table_forks(data);
	if (protection != 0)
		return (FAILURE);
	protection = init_philos_data(data);
	if (protection != 0)
		return (FAILURE);
	return (SUCCESS);
}

t_data	*init_gobal_data(int argc, char **argv)
{
	t_data	*data;
	int		protection;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->min_eat = ft_atoi(argv[5]);
	else
		data->min_eat = -1;
	data->is_dead = 0;
	data->ph_name = 0;
	data->start_time = ft_get_time();
	printf("Nb philo : %d\n time to die : %d\n time to eat : %d\n"
		   " time to sleep : %d\n min eat : %d\n is dead : %d\n philo name : %d\n START TIME : %lld\n",
		   	data->nb_philo, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->min_eat, data->is_dead, data->ph_name, data->start_time);
	protection = protected_init(data);
	if (protection != 0)
		return (NULL);
	return (data);
}