/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:25:43 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 14:38:16 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void meal_complete_mutex(t_thread	*philo)
{
	pthread_mutex_lock(&philo->params->meal_complete_m);
	philo->params->meal_complete += 1;
	pthread_mutex_unlock(&philo->params->meal_complete_m);
}
bool	check_meal_complete(t_philo_p *params)
{
	pthread_mutex_lock(&params->meal_complete_m);
	if (params->meal_complete == params->nb_philo)
		return (pthread_mutex_unlock(&params->meal_complete_m), true);
	pthread_mutex_unlock(&params->meal_complete_m);
	return (false);
}
void	increase_meal_taken(t_thread *philo)
{
	pthread_mutex_lock(&philo->params->meal_complete_m);
	pthread_mutex_lock(&philo->meal_taken_m);
	philo->meal_taken += 1;
	pthread_mutex_unlock(&philo->params->meal_complete_m);
	pthread_mutex_unlock(&philo->meal_taken_m);
}
bool	wait_all_thread(t_thread *philo)
{
	while (1)
	{
		if (philo->params->p_start == philo->nb_philo)
			return(true);
		if (philo->params->stop == true)
			return (false);
		usleep(500);
	}
	return (true);
}
void	*meal_is_set_case(t_thread *philo)
{
	while (philo->meal_taken < philo->meal_nb)
	{
		if (!philos_routine(philo))
		{
			return (NULL);
		}
		if (philo->meal_taken == philo->meal_nb)
		{
			meal_complete_mutex(philo);
			return ( (void *) 1);
		}
	}
	return ( (void *) 1);
}
