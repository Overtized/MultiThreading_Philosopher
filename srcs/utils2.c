/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:25:43 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/07 21:40:34 by mchanlia         ###   ########.fr       */
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
	philo->meal_taken += 1;
	pthread_mutex_unlock(&philo->params->meal_complete_m);
}
