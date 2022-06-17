/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:35:29 by akadi             #+#    #+#             */
/*   Updated: 2022/06/16 15:36:52 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;
	char	*src;

	i = 0;
	sign = 1;
	result = 0;
	src = (char *)str;
	while ((src[i] >= 9 && src[i] <= 13) || src[i] == ' ')
		i++;
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((src[i] >= '0' && src[i] <= '9') && src[i] != '\0')
	{
		result = result * 10 + src[i] - '0';
		i++;
	}
	return (result * sign);
}

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
	if (ac < 5)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while(av[i])
	{
		if (!ft_isnbr(av[i]) || av[i][0] == '-' || !ft_atoi(av[i]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}