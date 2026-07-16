/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:35:08 by mchanlia         ###   ########.fr       */
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

bool	take_fork(t_thread	*philo)
{
	if (philo->nb_philo == 1)
	{
		one_phil(philo); // until death
		return (false);
	}
	if (philo->phil_name % 2 == 0) // basic handling of even / odd philos fork picking
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	if (!update_elasped_time(philo))
		return (false);
	print_message(philo, "has taken a fork\n");
	philo->state_change = true;
	return (true);
}

void	putdown_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0) // even phil
	{
		pthread_mutex_unlock(philo->l_fork); // order of the fork put down is crucial
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork); // notice diff
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->l_fork);
	}
	philo->state_change = true;
}
