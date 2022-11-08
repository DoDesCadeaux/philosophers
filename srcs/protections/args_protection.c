/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_protection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:19:37 by dduraku           #+#    #+#             */
/*   Updated: 2022/11/01 16:19:38 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_is_only_nbrs(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] < '0' || src[i] > '9')
			return (0);
		else
			i++;
	}
	return (1);
}

static int	ft_numeric_args(char **argv)
{
	int			i;
	long long	argument;

	i = 1;
	while (argv[i])
	{
		argument = ft_atoi(argv[i]);
		if (!ft_is_only_nbrs(argv[i]))
		{
			write(2, "Numeric or positive argument required\n", 38);
			return (FAILURE);
		}
		else if (argument > INT_MAX)
		{
			write(2, "Illegal hardware instruction\n", 29);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static int	ft_is_argv_empty(char **argv)
{
	int			i;
	long long	argument;

	i = 1;
	while (argv[i])
	{
		argument = ft_atoi(argv[i]);
		if (!*argv[i])
		{
			write(2, "Argument is empty\n", 18);
			return (FAILURE);
		}
		else if (argument == 0)
		{
			write(2, "Should be greater than 0\n", 25);
			return (FAILURE);
		}
		else
			i++;
	}
	return (SUCCESS);
}

int	ft_args_protection(int argc, char **argv)
{
	int		is_numeric;
	int		is_empty;
	int		is_too_much;

	if (!(argc >= 5 && argc <= 6))
	{
		write(2, "Must have 5 args or 6 args\n", 27);
		return (FAILURE);
	}
	is_too_much = ft_atoi(argv[1]);
	if (is_too_much > 200)
	{
		write(2, "Too much philos\n", 16);
		return (FAILURE);
	}
	is_numeric = ft_numeric_args(argv);
	if (is_numeric != 0)
		return (FAILURE);
	is_empty = ft_is_argv_empty(argv);
	if (is_empty != 0)
		return (FAILURE);
	return (SUCCESS);
}
