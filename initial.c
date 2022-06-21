/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:46:41 by akadi             #+#    #+#             */
/*   Updated: 2022/06/21 21:24:04 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, info *arg)
{
	int	i;

	i = 0;
	arg->time = get_current_time();
	while(i < arg->number_of_philos)
	{
		philo[i].num_philo = i + 1;
	}
}

void	