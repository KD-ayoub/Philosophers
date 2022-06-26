/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:32:06 by akadi             #+#    #+#             */
/*   Updated: 2022/06/26 21:37:03 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *msg, info *info, int num_philo)
{
	if (info->stop == 1 && ft_strncmp(msg, "died", 4))
		return ;
	pthread_mutex_lock(&info->mutex);
	info->print_time = get_current_time() - info->time;
	printf("%lu       %d   %s \n", info->print_time, num_philo, msg);
	pthread_mutex_unlock(&info->mutex);
}