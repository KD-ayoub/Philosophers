/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:37:14 by akadi             #+#    #+#             */
/*   Updated: 2022/06/26 21:46:27 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_helper(t_philo *philo, info *data, int i)
{
	if (data->eaten == data->number_of_philos)
	{
		data->stop = 1;
		return (0);
	}
	if ((get_current_time() - philo[i].last_meal) > data->time_to_die)
	{
		data->stop = 1;
		if (data->number_of_philos == 1)
			pthread_mutex_unlock(philo->right);
		print_msg("died\n", philo->info, 1);
		return (0);
	}
	return (1);
}

void	*check_dead_p(void	*arg)
{
	t_philo	*philo;
	info	*data;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	data = philo[0].info;
	while (1)
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			if (!check_dead_helper(philo, data, i))
				return (0);
			i++;
		}
	}
	return (NULL);
}