/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:41 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/06 00:26:55 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_data *data, t_philo *philo)
{
	print_output(data, philo, SLEEP);
	ft_usleep(data->time_to_sleep);
}

void	eating(t_data *data, t_philo *philo)
{
	print_output(data, philo, EAT);
	ft_usleep(data->time_to_eat);
	philo->eat_time = get_time();
	philo->philo_eated++;
	if (data->min_eat != -1 && philo->philo_eated == data->nb_philo)
	{
		data->total_eat++;
		philo->philo_eated = 0;
		if (data->total_eat == data->min_eat)
			data->is_dead = 1;
	}
}

int	dead(t_data *data, t_philo *philo)
{
	if (get_time() >= (philo->eat_time + data->time_to_die))
	{
		print_output(data, philo, DEAD);
		data->is_dead = 1;
		return (1);
	}
	return (0);
}
