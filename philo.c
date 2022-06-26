/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:26:53 by akadi             #+#    #+#             */
/*   Updated: 2022/06/26 21:52:57 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	t;
	long			cur_time;

	gettimeofday(&t, NULL);
	cur_time = (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (cur_time);
}

void	get_arguments(info *arg, char **av, int ac)
{
	arg->number_of_philos = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		if (!(arg->n_of_philo_must_eat = ft_atoi(av[5])))
			return ;
	}
	else
		arg->n_of_philo_must_eat = -1;
	
}

void	end_all(info *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(philos[i].right);
		i++;
	}
	pthread_join(data->check_dead, NULL);
	free(philos);
	free(data->forks);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	info	arg;

	if (check_error(ac, av) || ac == 1)
		return (0);
	get_arguments(&arg, av, ac);
	philo = malloc(sizeof(t_philo) * arg.number_of_philos);
	init_philo(philo, &arg);
	init_fork(&arg);
	end_all(&arg, philo);
}

