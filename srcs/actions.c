/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:41 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/08 18:32:43 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_data *data, t_philo *philo)
{
	print_status(data, philo, SLEEP);
	ft_sleep(data->time_to_sleep);
}

void	eating(t_data *data, t_philo *philo)
{
	print_status(data, philo, EAT);
	philo->eat_time = ft_get_time();
	if (data->min_eat != -1 && (data->philo_eated < data->nb_philo))
	{
		data->philo_eated++;
		if (data->philo_eated == data->nb_philo)
		{
			data->total_eat++;
			data->philo_eated = 0;
		}
		ft_sleep(data->time_to_eat);
	}
}

int	dead(t_data *data, t_philo *philo)
{
	if (ft_get_time() > (philo->eat_time + data->time_to_die))
	{
		print_status(data, philo, DEAD);
		data->is_dead = 1;
		return (1);
	}
	return (0);
}

void	take_left_fork(t_data *data, t_philo *philo)
{
	if (data->is_dead == 1)
		return ;
	pthread_mutex_lock(philo->my_fork);
	print_status(data, philo, FORK);
	if (data->nb_philo == 1)
		ft_sleep(data->time_to_die + 1);
}

void	take_right_fork(t_data *data, t_philo *philo)
{
	if (data->is_dead == 1)
		return ;
	pthread_mutex_lock(philo->right_fork);
	print_status(data, philo, FORK);
}