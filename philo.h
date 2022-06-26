/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:29:17 by akadi             #+#    #+#             */
/*   Updated: 2022/06/26 21:45:23 by akadi            ###   ########.fr       */
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
	int				stop;
	int				eaten;
	long			time;
	long			print_time;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	pthread_t		check_dead;
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
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_isnbr(char *av);
long	get_current_time(void);
void	init_philo(t_philo *philo, info *arg);
void	init_fork(info *arg);
void	*routine(void	*philo);
void	ft_usleep(long t);
void	*check_dead_p(void	*arg);
int	check_dead_helper(t_philo *philo, info *data, int i);
void	lock_fork(t_philo *philo);
void	unlock_fork(t_philo *philo);
int	eat(t_philo *philo);
void	print_msg(char *msg, info *info, int num_philo);
int	check_error(int ac, char **av);

#endif