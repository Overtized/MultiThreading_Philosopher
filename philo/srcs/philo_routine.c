/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:13:59 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 18:42:46 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	tasks(t_thread	*philo)
{
	if (!check_thread_death(philo))
		return (false);
	if (!is_eating(philo))
		return (false);
	if (!is_sleeping(philo))
		return (false);
	if (!is_thinking(philo))
		return (false);
	return (true);
}
bool	philos_routine(t_thread	*philo)
{
	long	meal_taken;

	meal_taken = 0;
	if (philo->meal_nb > 0)
	{
		while (philo->meal_taken < philo->meal_nb)
		{
			meal_taken_mutex(philo, &meal_taken);
			if (!tasks(philo))
				return (false);
		}
	}
	else
	{
		if (!tasks(philo))
			return (false);
	}
	return (true);
}

