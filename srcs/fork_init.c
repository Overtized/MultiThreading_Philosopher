/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/28 00:51:01 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// bool	forks_init(t_thread *philo)
// {
// 	philo->r_fork = philo->forks[philo->phil_name];
// 	philo->l_fork = philo->forks[philo->phil_name + 1 % philo->nb_philo];
// 	return (true);
// }

bool	take_fork(t_thread	*philo)
{
	if (!is_philo_dead(philo))
		return (false);
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		printf("philo %d, has taken a fork\n", philo->phil_name);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		printf("philo %d, has taken a fork\n", philo->phil_name);
	}
	return (true);
	// revoir le fork sans r et l mais avec tab de fork et gestion de dispo de fork
}
void	putdown_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}
