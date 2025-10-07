/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/07 19:06:44 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	one_phil(t_thread	*philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo->state_change == true)
		print_message(philo, "has taken a fork\n");
	ft_usleep(philo->d_timer, philo);
	pthread_mutex_unlock(philo->l_fork);
	return ;
}

void	*take_fork(t_thread	*philo)
{
	if (philo->nb_philo == 1)
	{
		one_phil(philo);
		return (NULL);
	}
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		philo->ready_to_eat = true;
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		philo->ready_to_eat = true;
	}
	if (philo->ready_to_eat == true)
	{
		update_elasped_time(philo);
		print_message(philo, "has taken a fork\n");
		philo->state_change = true;
	}
	return ((void *)1);
}

void	putdown_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->l_fork);
	}
	if (philo->nb_philo > 1)
	{
		philo->ready_to_eat = false;
		philo->state_change = true;
	}
}
