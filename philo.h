/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:29:17 by akadi             #+#    #+#             */
/*   Updated: 2022/06/19 16:44:02 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <pthread.h>

typedef struct argument
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_philo_must_eat;
	int				dead;
	long			time;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;

}info;

typedef struct s_philo
{
	int		num_philo;
	int		num_eat;
	long	last_meal;
	info	*info;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	pthread_t	thread;
}t_philo;

int	ft_strlen(char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_isnbr(char *av);
int	check_error(int ac, char **av);

#endif