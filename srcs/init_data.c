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

t_philo	*init_philo(int philo_name)
{
	t_philo	*philo;

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
	if (data->nb_philo == 1)
		data->ph[philo_name]->my_fork = &data->forks[0];
	else
	{
		if (philo_name == data->nb_philo - 1)
		{
			data->ph[philo_name]->my_fork = &data->forks[philo_name];
			data->ph[philo_name]->right_fork = &data->forks[0];
		}
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
	create_threads(data, 0);
	join_threads(data, 0);
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
		protection = pthread_mutex_init(&data->forks[i], NULL);
		if (protection != 0)
			return (FAILURE);
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
