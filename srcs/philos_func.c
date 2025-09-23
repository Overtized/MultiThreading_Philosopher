/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/23 17:27:21 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
int cout = 0;
void	is_eating(t_thread	*philo)
{
	if (philo->nb_philo > 1)
		pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	while (cout < 100)
	{
		printf("thread %d\n", philo->phil_name);
		cout += 10;
		printf("cout value is %d\n", cout);
	}
	cout = 0;
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