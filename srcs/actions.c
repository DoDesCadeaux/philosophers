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
	usleep(data->time_to_sleep);
}