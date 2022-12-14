/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:13:34 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/06 00:18:18 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	join_threads(t_data *data, int i)
{
	int	protection;

	while (i < data->nb_philo)
	{
		protection = pthread_join(data->ph[i]->philo_t, NULL);
		if (protection != 0)
			return ;
		i++;
	}
}

void	create_threads(t_data *data, int i)
{
	int	prot;

	while (i < data->nb_philo)
	{
		init_philo_fork(data, i);
		prot = pthread_create(&data->ph[i]->philo_t, NULL, &init_dinner, data);
		if (prot != 0)
			return ;
		i++;
	}
}
