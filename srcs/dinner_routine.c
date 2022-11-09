/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:55:13 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/09 16:55:15 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_eating(t_data *data, t_philo *philo)
{
	if (data->nb_philo == 1)
		take_left_fork(data, philo);
	else
	{
		take_left_fork(data, philo);
		take_right_fork(data, philo);
		eating(data, philo);
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->right_fork);
		sleeping(data, philo);
	}
}

void	*start_dinner(t_data *data, t_philo *philo)
{
	start_eating(data, philo);
	if (data->is_dead == 1)
		return (NULL);
	else
		print_output(data, philo, THINK);
	return (NULL);
}

void	*init_dinner(void *Nullable)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) Nullable;
	philo = data->ph[data->ph_name];
	data->ph_name++;
	if (philo->name % 2 == 0)
		ft_sleep(100);
	while (data->min_eat == -1 || data->total_eat < data->min_eat)
	{
		if (data->is_dead == 0)
			start_dinner(data, philo);
	}
	return (NULL);
}

void	*end_dinner(t_data *data)
{
	int	i;

	while (31)
	{
		i = 0;
		while (i < data ->nb_philo)
		{
			if (dead(data, data->ph[i]))
				return (NULL);
			if (data->min_eat != -1 && (data->total_eat == data->min_eat))
			{
				pthread_mutex_lock(&data->print);
				return (NULL);
			}
			i++;
		}
	}
}