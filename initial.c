/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:46:41 by akadi             #+#    #+#             */
/*   Updated: 2022/06/26 21:53:48 by akadi            ###   ########.fr       */
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
		philo[i].left = &arg->forks[i];
		if (i == 0)
			philo[i].right = &arg->forks[arg->number_of_philos - 1];
		else
			philo[i].right = &arg->forks[i - 1];
		philo[i].info = arg;
		philo[i].last_meal = arg->time;
		philo[i].num_eat = 0;
		philo[i].info->stop = 0;
		pthread_create(&philo->thread, NULL, &routine, &philo[i]);
		i++;
	}
	pthread_create(&philo->info->check_dead, NULL, &check_dead_p, philo);
}

void	init_fork(info *arg)
{
	int	i;

	i = 0;
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->number_of_philos);
	while (i < arg->number_of_philos)
		pthread_mutex_init(&arg->forks[i++], NULL);
}