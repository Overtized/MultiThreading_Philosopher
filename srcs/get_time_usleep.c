/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_usleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:17:59 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 16:09:04 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	now_t;
	long			elapsed_time;

	if (gettimeofday(&now_t, NULL) == -1)
		return (printf ("gettime failure\n"), -1);
	elapsed_time = (now_t.tv_sec * 1000) + (now_t.tv_usec / 1000);
	return (elapsed_time);
}

bool	ft_usleep(long time_to_wait, t_thread *philo)
{
	long	end_t;

	end_t = get_time() + time_to_wait;
	while (get_time() < end_t)
	{
		if (!check_thread_death(philo))
			return (false);
		usleep(500);
	}
	return (true);
}

void	update_elasped_time(t_thread	*philo)
{
	long	new_time;

	new_time = get_time();
	if (new_time == -1)
		return ;
	pthread_mutex_lock(&philo->elapsed_m);
	philo->elapsed_t = new_time - philo->start_time;
	pthread_mutex_unlock(&philo->elapsed_m);
}
