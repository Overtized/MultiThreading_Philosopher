/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 18:37:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*is_eating(t_thread	*philo)
{
	long	new_time;

	if (check_thread_death(philo) == NULL)
		return(NULL);
	if (take_fork(philo) == NULL)
		return ((void*)1);
	if (check_thread_death(philo) == NULL)
		return(putdown_fork(philo), NULL);
	if (philo->ready_to_eat)
	{
		new_time = get_time();
		if (new_time == -1)
			return(putdown_fork(philo), NULL);
		philo->elapsed_t = new_time - philo->start_time;
		pthread_mutex_lock(&philo->last_meal);
		philo->last_meal_t = new_time;
		pthread_mutex_unlock(&philo->last_meal);
		print_message(philo, ", is eating\n");
		if (ft_usleep(philo->e_timer, philo) == NULL)
		 	return(putdown_fork(philo), NULL);
		philo->meal_taken += 1;
	}
	putdown_fork(philo);
	return ((void*)1);
}

void	*is_thinking(t_thread	*philo)
{
	long	new_time;

	if (check_thread_death(philo) == NULL)
		return(NULL);
	new_time = get_time();
	philo->elapsed_t = new_time - philo->start_time;
	if (philo->state_change == 1)
	{
		print_message(philo, ", is thinking\n");
		philo->state_change = 0;
	}
	return ((void *)1);
}

void	*is_sleeping(t_thread	*philo)
{
	long	new_time;

	if (check_thread_death(philo) == NULL)
		return(NULL);
	new_time = get_time();
	philo->elapsed_t = new_time - philo->start_time;
	if (philo->meal_taken > 0)
	{
		print_message(philo, ", is sleeping\n");
		if (ft_usleep(philo->s_timer, philo) == NULL)
			return(NULL);
		if (check_thread_death(philo) == NULL)
			return(NULL);
	}
	return ((void *)1);
}

