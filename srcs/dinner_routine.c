/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:55:13 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/06 00:24:11 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_eating(t_data *data, t_philo *philo)
{
	if (data->nb_philo == 1)
	{
		print_output(data, philo, FORK);
		pthread_mutex_lock(philo->my_fork);
		ft_sleep(data->time_to_die);
	}
	else
	{
		if (philo->name < data->nb_philo)
		{
			print_output(data, philo, FORK);
			pthread_mutex_lock(philo->my_fork);
			pthread_mutex_lock(philo->right_fork);
		}
		else
		{
			print_output(data, philo, FORK);
			pthread_mutex_lock(philo->right_fork);
			pthread_mutex_lock(philo->my_fork);
		}
		eating(data, philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->my_fork);
		sleeping(data, philo);
	}
}

void	*start_dinner(t_data *data, t_philo *philo)
{
	start_eating(data, philo);
	print_output(data, philo, THINK);
	return (NULL);
}

void	*init_dinner(void *Nullable)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) Nullable;
	pthread_mutex_lock(&data->check_total_eat);
	philo = data->ph[data->ph_name];
	data->ph_name++;
	pthread_mutex_unlock(&data->check_total_eat);
	if (philo->name % 2 == 0)
		ft_sleep(100);
	while (data->is_dead == 0)
		start_dinner(data, philo);
	return (NULL);
}

void	*end_dinner(t_data *data)
{
	int	i;

	while (data->is_dead == 0)
	{
		i = 0;
		while (data->is_dead == 0 && i < data->nb_philo)
		{
			if (dead(data, data->ph[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
