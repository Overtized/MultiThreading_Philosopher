/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 14:11:51 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_eating(t_thread	*philo)
{
	long	new_time;

	if (!take_fork(philo))
		return (true);
	if (!check_thread_death(philo))
		return (putdown_fork(philo), false);
	if (philo->ready_to_eat)
	{
		new_time = get_time();
		if (new_time == -1)
			return (putdown_fork(philo), false);
		pthread_mutex_lock(&philo->last_meal);
		pthread_mutex_lock(&philo->elapsed_m);
		philo->elapsed_t = new_time - philo->start_time;
		philo->last_meal_t = new_time -philo->start_time;
		pthread_mutex_unlock(&philo->last_meal);
		pthread_mutex_unlock(&philo->elapsed_m);
		print_message(philo, "is eating\n");
		if (!ft_usleep(philo->e_timer, philo))
			return (putdown_fork(philo), false);
		increase_meal_taken(philo);
	}
	putdown_fork(philo);
	return (true);
}

bool	is_thinking(t_thread	*philo)
{
	update_elasped_time(philo);
	if (!check_thread_death(philo))
		return (false);
	if (philo->state_change == 1)
	{
		// usleep(500);
		print_message(philo, "is thinking\n");
		philo->state_change = 0;
		if (!check_thread_death(philo))
		return (false);
	}
	return (true);
}
// a voir si je le laisse le usleep
bool	is_sleeping(t_thread	*philo)
{
	update_elasped_time(philo);
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
