/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/26 10:52:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void	is_eating(t_thread	*philo)
{
	if (philo->nb_philo > 1)
		pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	if (!is_philo_dead(philo))
	{
		if (philo->nb_philo > 1)
			pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		return ;
	}
	printf(" hello thread %d\n", philo->phil_name);
	if (philo->nb_philo > 1)
		pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}
void	is_thinking(t_thread	*philo)
{
	usleep(1000);
	(void) philo;
	
}
void	is_sleeping(t_thread	*philo)
{
	usleep(1000);
	(void) philo;
}
bool	is_philo_dead(t_thread	*philo)
{
	struct timeval timer;

	if (gettimeofday(&timer, NULL) == -1)
		return (printf ("gettime failure\n"), false);
	if (&philo->clock - &timer > philo->d_timer)
		return (printf ("philos is dead within %ld ms\n", &philo->clock - &timer), false);
	else
		return (printf("philo has started since %ld ms\n", &philo->clock - &timer), true);
}