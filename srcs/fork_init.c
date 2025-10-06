/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 18:18:41 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	one_phil(t_thread	*philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo->state_change == true)
		print_message(philo, ", has taken a fork\n");
	ft_usleep(philo->e_timer);
	pthread_mutex_unlock(philo->l_fork);
	return ;
}
void	*take_fork(t_thread	*philo)
{
	if (philo->nb_philo == 1)
		one_phil(philo);
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		if (philo->nb_philo > 1)
		{
			pthread_mutex_lock(philo->r_fork); // pair
			philo->ready_to_eat = true;
		}
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		if (philo->nb_philo > 1)
		{
			pthread_mutex_lock(philo->l_fork); // impair
			philo->ready_to_eat = true;
		}
	}
	// philo->ready_to_eat = true;
	philo->state_change = true;
	if (philo->ready_to_eat == true)
		print_message(philo, ", has taken a fork\n");
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
