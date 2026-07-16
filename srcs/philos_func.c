/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:35:31 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_eating(t_thread	*philo)
{
	if (!take_fork(philo))
		return (true);
	if (!update_e_time_last_meal(philo)) // time update as soon as possible 
	{
		putdown_fork(philo);
		return (false);
	}
	print_message(philo, "is eating\n");
	if (!check_thread_death(philo))
	{
		putdown_fork(philo);
		return (false);
	}
	if (!ft_usleep(philo->e_timer, philo))
	{
		putdown_fork(philo);
		return (false);
	}
	increase_meal_taken(philo);
	putdown_fork(philo);
	return (true);
}

bool	is_thinking(t_thread	*philo)
{
	long	time_to_think;

	time_to_think = philo->d_timer - philo->e_timer - philo->s_timer;
	if (!update_elasped_time(philo))
		return (false);
	if (!check_thread_death(philo))
		return (false);
	if (philo->state_change == 1)
	{
		ft_usleep((time_to_think * 0.8), philo);
		print_message(philo, "is thinking\n");
		philo->state_change = 0;
	}
	return (true);
}

bool	is_sleeping(t_thread	*philo)
{
	if (!update_elasped_time(philo)) // timer update
		return (false);
	if (!check_thread_death(philo))
		return (false);
	if (philo->meal_taken > 0)
	{
		print_message(philo, "is sleeping\n");
		if (!ft_usleep(philo->s_timer, philo))
			return (false);
		if (!check_thread_death(philo))
			return (false);
	}
	return (true);
}
