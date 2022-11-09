/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:28:31 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/09 17:28:33 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	clear_threads(t_data *data)
{
	int	i;
	int	protection;

	i = 0;
	while (i < data->nb_philo)
	{
		protection = pthread_mutex_destroy(&data->forks[i]);
		if (protection != 0)
			return (FAILURE);
		protection = pthread_detach(data->ph[i]->philo_t);
		if (protection != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}