/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/28 11:27:41 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	take_fork(t_thread	*philo)
{
	if (!is_philo_dead(philo))
		return (false);
	if (philo->phil_name % 2 == 0)
	{
		if (philo->nb_philo > 1)
			pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		printf("philo %d, has taken a fork\n", philo->phil_name);
	}
	else
	{
		if (philo->nb_philo > 1)
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
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}
