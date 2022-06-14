/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:35:29 by akadi             #+#    #+#             */
/*   Updated: 2022/06/14 13:14:32 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnbr(char *av)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (av[i] == '+')
	{
		i = 1;
		if (len == 1)
			return (0);
	}
	while (i < len)
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_error(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || av[1][0] == '0')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while(av[i])
	{
		if (!ft_isnbr(av[i]) || av[i][0] == '-')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}