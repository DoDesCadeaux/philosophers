/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:38:20 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/08 18:38:22 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_output(t_data *data, t_philo *philo, int status)
{
	unsigned long long	time;

	pthread_mutex_lock(&data->print);
	time = ft_get_time() - data->start_time;
	if (status == FORK && data->is_dead == 0)
		printf("%lld %d has taken a fork\n", time, philo->name);
	else if (status == EAT && data->is_dead == 0)
		printf("%lld %d is eating\n", time, philo->name);
	else if (status == SLEEP && data->is_dead == 0)
		printf("%lld %d is sleeping\n", time, philo->name);
	else if (status == THINK && data->is_dead == 0)
		printf("%lld %d is thinking\n", time, philo->name);
	else if (status == DEAD)
		printf("%lld %d died\n", time, philo->name);
	pthread_mutex_unlock(&data->print);
}
