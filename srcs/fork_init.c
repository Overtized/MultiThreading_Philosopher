/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/01 17:43:56 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

 void	take_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0)
	{
		if (philo->nb_philo > 1)
			pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		
		printf("%d ms: %d, has taken a fork\n",philo->converted_time, philo->phil_name); // pair
	}
	else
	{
		if (philo->nb_philo > 1)
			pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		printf("%d ms: %d, has taken a fork\n",philo->converted_time, philo->phil_name); // impair
	}
}
void	putdown_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0)
	{
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		printf("%d ms: %d, has put down a fork\n",philo->converted_time, philo->phil_name); // pair // a enlever
	}
	else
	{
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		printf("%d ms: %d, has put down a fork\n",philo->converted_time, philo->phil_name); // impair // a enlever
	}
}
