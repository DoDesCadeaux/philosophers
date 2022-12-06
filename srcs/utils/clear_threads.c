/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:28:31 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/05 23:51:58 by vrogiste         ###   ########.fr       */
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
		i++;
	}
	return (SUCCESS);
}
