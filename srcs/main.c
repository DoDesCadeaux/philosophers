/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:19:20 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/01 16:19:22 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		protection;
	int		i;

	protection = ft_args_protection(argc, argv);
	if (protection != 0)
		return (FAILURE);
	data = init_gobal_data(argc, argv);
	if (!data)
		return (FAILURE);
	end_dinner(data);
	pthread_mutex_destroy(&data->print);
	protection = clear_threads(data);
	if (protection != 0)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		free(data->ph[i]);
		i++;
	}
	free(data->ph);
	free(data);
	return (SUCCESS);
}
