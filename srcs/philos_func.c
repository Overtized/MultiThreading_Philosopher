/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:56 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*is_eating(t_thread	*philo)
{
	long	new_time;

	take_fork(philo);
	philo->state_change = 1;
	if (philo->ready_to_eat)
	{
		new_time = get_time();
		if (new_time == -1)
			return(NULL);
		new_time = new_time - philo->start_time;
		printf("%d ms: %d, is eating\n",philo->elapsed_t, philo->phil_name);
		if (ft_usleep(philo->e_timer, philo) == NULL)
		 	return(NULL);
		philo->last_meal_t = new_time;
		philo->meal_taken += 1;
		putdown_fork(philo);
		return ((void*)1);
	}
	return ((void*)1);
}
void	is_thinking(t_thread	*philo)
{
	if (philo->state_change == 1)
	{
		printf("%d ms: %d, is thinking\n",philo->elapsed_t, philo->phil_name);
		philo->state_change = 0;
	}
}

void	*is_sleeping(t_thread	*philo)
{
	printf("%d ms: %d, is sleeping\n",philo->elapsed_t, philo->phil_name);
	if (ft_usleep(philo->s_timer, philo) == NULL)
		return(NULL);
	return ((void *)1);
}
void	*is_philo_dead(t_thread	*philo)
{
	long	is_dead_t;

	is_dead_t = 0;
	if (get_time_death(philo) == -1)
		return (NULL);
	is_dead_t = philo->elapsed_t - philo->last_meal_t;
	if (is_dead_t >= philo->d_timer)
	{
		printf ("%d ms: %d died\n", philo->elapsed_t, philo->phil_name);
		philo->is_alive = false;
		return ((void*)1);
	}
	return ((void*)1);
}

