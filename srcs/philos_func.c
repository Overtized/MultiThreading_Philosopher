/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/01 17:24:58 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_eating(t_thread	*philo)
{
	double	time_spent_eating;
	struct timeval now_t;
	long	elapsed_time;
	int		new_time;

	elapsed_time = 0;
	new_time = 0;
	if (gettimeofday(&now_t, NULL) == -1)
		return (printf ("gettime failure\n"), false);
	elapsed_time = (now_t.tv_sec - philo->start_t.tv_sec) * 1000000 + (now_t.tv_usec - philo->start_t.tv_usec);
	elapsed_time = elapsed_time / 1000.0;
	new_time = (int)elapsed_time - philo->converted_time ;
	if (!is_philo_dead(philo))
		return (false);
	time_spent_eating = philo->e_timer * 1000;
	printf("%d ms: %d, is eating\n",philo->converted_time, philo->phil_name);
	usleep(time_spent_eating);
	philo->last_meal_t = new_time + time_spent_eating;
	philo->meal_taken += 1;
	putdown_fork(philo);
	return (true);
}
void	is_thinking(t_thread	*philo)
{
	printf("%d ms: %d, is thinking\n",philo->converted_time, philo->phil_name);
	take_fork(philo);
}

void	is_sleeping(t_thread	*philo)
{
	long	time_spent_sleeping;

	time_spent_sleeping = 0;
	time_spent_sleeping = philo->s_timer * 1000;
	printf("%d ms: %d, is sleeping\n",philo->converted_time, philo->phil_name);
	usleep(time_spent_sleeping);
	// a voir si tu dois pas rajouter des checks de death dans le sleep et think
}
bool	is_philo_dead(t_thread	*philo)
{
	int	is_dead_t;

	is_dead_t = 0;
	if (!get_time(philo))
		return (false);
	is_dead_t = philo->converted_time - philo->last_meal_t;
	if (is_dead_t >= philo->d_timer)
	{
		printf ("%d ms: %d died\n", philo->converted_time, philo->phil_name);
		return (false);
	}
	return (true);
}
bool	get_time(t_thread	*philo)
{
	struct timeval now_t;
	long	elapsed_time;

	elapsed_time = 0;
	philo->converted_time = 0;
	if (gettimeofday(&now_t, NULL) == -1)
		return (printf ("gettime failure\n"), false);
	elapsed_time = (now_t.tv_sec - philo->start_t.tv_sec) * 1000000 + (now_t.tv_usec - philo->start_t.tv_usec);
	philo->converted_time = elapsed_time / 1000.0;
	// printf("elapsed time is %ld micro seconds\n", elapsed_time);
	// printf("converted time is %d miliseconds\n", philo->converted_time);
	return (true);
}
