/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_check2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:04:22 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 16:33:21 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_philo_done(t_philo_p *params, t_thread *philos, int *i)
{
	int	j;

	j = *i;
	pthread_mutex_lock(&params->meal_complete_m);
	if (philos[j].meal_taken == philos[j].meal_nb)
	{
		pthread_mutex_unlock(&params->meal_complete_m);
		(*i)++;
		return (true);
	}
	pthread_mutex_unlock(&params->meal_complete_m);
	return (false);
}

void	wait_all_thread_m(t_thread *philo)
{
	int	current;

	current = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->params->p_start_m);
		current = philo->params->p_start;
		pthread_mutex_unlock(&philo->params->p_start_m);
		if (current == philo->nb_philo)
			return ;
		usleep(1000);
	}
	return ;
}

bool	wait_all_thread_c(t_thread *philo)
{
	int		current;
	bool	stopped;

	pthread_mutex_lock(&philo->params->p_start_m);
	philo->params->p_start += 1;
	pthread_mutex_unlock(&philo->params->p_start_m);
	while (1)
	{
		pthread_mutex_lock(&philo->params->p_start_m);
		current = philo->params->p_start;
		stopped = philo->params->stop;
		pthread_mutex_unlock(&philo->params->p_start_m);
		if (current == philo->nb_philo)
			return (true);
		if (stopped)
			return (false);
		usleep(1000);
	}
	return (true);
}
