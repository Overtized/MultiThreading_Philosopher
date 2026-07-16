/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:13:59 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:32:24 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	tasks(t_thread	*philo)
{
	if (!check_thread_death(philo)) // check for a timer limit overflow hence death of a philo
		return (false);
	if (!is_eating(philo)) // rest is self explanatory
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
		while (philo->meal_taken < philo->meal_nb) // while meal situation not finished
		{
			meal_taken_mutex(philo, &meal_taken);
			if (!tasks(philo))
				return (false);
		}
	}
	else
	{
		if (!tasks(philo)) // classic solution 
			return (false);
	}
	return (true);
}
// a bit of a clunky implementation there
