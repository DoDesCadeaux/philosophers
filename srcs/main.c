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
	int		protection;

	protection = ft_args_protection(argc, argv);
	if (protection != 0)
		return (FAILURE);
	return (0);
}
