/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:51:39 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/09 16:51:41 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	data->total_eat = 0;
	data->ph_name = 0 ;
	data->start_time = get_time();
	protection = protected_init(data);
	if (protection != 0)
		return (NULL);
	return (data);
}
