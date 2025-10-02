/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/02 18:03:55 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

 void	take_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		philo->ready_to_eat = true;
		printf("%d ms: %d, has taken a fork\n",philo->elapsed_t, philo->phil_name); // pair
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		philo->ready_to_eat = true;
		printf("%d ms: %d, has taken a fork\n",philo->elapsed_t, philo->phil_name); // impair
	}
}
void	putdown_fork(t_thread	*philo)
{
	if (philo->phil_name % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo->ready_to_eat = false;
		printf("%d ms: %d, has put down a fork\n",philo->elapsed_t, philo->phil_name); // pair // a enlever
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		philo->ready_to_eat = false;
		printf("%d ms: %d, has put down a fork\n",philo->elapsed_t, philo->phil_name); // impair // a enlever
	}
}
