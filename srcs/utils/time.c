/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:29:03 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/08 16:29:05 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_sleep(unsigned long long time_to_sleep)
{
	unsigned long long actual;

	actual = ft_get_time();
	while (1)
	{
		if (ft_get_time() - actual >= time_to_sleep)
			break ;
		usleep(50);
	}
}

unsigned long long	ft_get_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}