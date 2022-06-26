/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:35:47 by akadi             #+#    #+#             */
/*   Updated: 2022/06/26 21:41:11 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*phillo)
{
	t_philo	*philo;

	philo = (t_philo *)phillo;
	while (philo->info->stop == 0)
	{
		eat(philo);
		if (philo->info->stop == 1)
			return (0);
		print_msg("is sleeping", philo->info, philo->num_philo);
		ft_usleep(philo->info->time_to_sleep);
		if (philo->info->stop == 1)
			return (0);
		print_msg("is thinking", philo->info, philo->num_philo);
	}
	return (0);
}

void	lock_fork(t_philo *philo)
{
	if (philo->num_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		print_msg("has taken a fork", philo->info, philo->num_philo);
		pthread_mutex_lock(philo->left);
		print_msg("has taken a fork", philo->info, philo->num_philo);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_msg("has taken a fork", philo->info, philo->num_philo);
		pthread_mutex_lock(philo->right);
		print_msg("has taken a fork", philo->info, philo->num_philo);
	}
}

void	unlock_fork(t_philo *philo)
{
	if (philo->num_philo % 2 == 0)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
	}
	else
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
}

int	eat(t_philo *philo)
{
	lock_fork(philo);
	print_msg("is eating", philo->info, philo->num_philo);
	philo->last_meal = get_current_time();
	ft_usleep(philo->info->time_to_eat);
	philo->num_eat++;
	if (philo->num_eat == philo->info->n_of_philo_must_eat)
		philo->info->eaten++;
	unlock_fork(philo);
	if (philo->info->stop == 1)
		return (1);
	return (0);
}