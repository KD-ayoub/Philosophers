/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:29:17 by akadi             #+#    #+#             */
/*   Updated: 2022/06/16 15:37:04 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pthread.h>


int	ft_strlen(char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_isnbr(char *av);
int	check_error(int ac, char **av);

#endif