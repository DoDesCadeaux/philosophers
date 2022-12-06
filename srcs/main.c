/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:19:20 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/06 00:17:51 by vrogiste         ###   ########.fr       */
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
	join_threads(data, 0);
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
