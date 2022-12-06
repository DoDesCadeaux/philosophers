/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:19:50 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/01 16:19:53 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_forward(char *str, int *signe, int *neg)
{
	int	i;

	i = 0;
	*neg = 1;
	*signe = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*neg = -1;
		i++;
		*signe += 1;
	}
	return (i);
}

long long	ft_atoi(const char *str)
{
	int						i;
	int						signe;
	int						neg;
	unsigned long long		res;
	char					*forward;

	forward = (char *)str;
	res = 0;
	i = ft_forward(forward, &signe, &neg);
	if (signe > 1)
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (neg == -1 && res - 1 > LLONG_MAX)
		return (0);
	if (neg == 1 && res > LLONG_MAX)
		return (-1);
	return (res * neg);
}
