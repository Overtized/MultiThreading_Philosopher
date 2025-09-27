/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:28:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/27 19:24:36 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	fork_circuit(t_thread	*philo)
{
	if (!is_philo_dead(philo))
		return (false);
	if (philo->nb_philo > 1)
	{
		pthread_mutex_lock(&philo->l_fork);
		printf("philo %d, has taken a fork\n", philo->phil_name);
	}
	pthread_mutex_lock(&philo->r_fork);
	printf("philo %d, has taken a fork\n", philo->phil_name);
	return (true);
	// revoir le fork sans r et l mais avec tab de fork et gestion de dispo de fork
}

bool	is_eating(t_thread	*philo)
{
	double	time_spent_eating;

	time_spent_eating = 0;
	time_spent_eating = philo->e_timer * 1000;
	if (!fork_circuit(philo))
		return (false);
	printf("philo %d, is eating\n", philo->phil_name);
	usleep(time_spent_eating);
	philo->last_meal = philo->converted_time + time_spent_eating;
	if (philo->nb_philo > 1)
		pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	// revoir le fork sans r et l mais avec tab de fork et gestion de dispo de fork
	return (true);
}
void	is_thinking(t_thread	*philo)
{
	long	time_spent_thinking;

	time_spent_thinking = 0;
	// time_spent_thinking = philo->e_timer * 1000;
	printf("philo %d, is thinking\n", philo->phil_name);
	usleep(time_spent_thinking);
	// si fork locked tu think sinon tu mange et tu repete tant au que meal nb
	// check de death ?
}
void	is_sleeping(t_thread	*philo)
{
	long	time_spent_sleeping;

	time_spent_sleeping = 0;
	time_spent_sleeping = philo->s_timer * 1000;
	printf("philo %d, is sleeping\n", philo->phil_name);
	usleep(time_spent_sleeping);
	// a voir si tu dois pas rajouter des checks de death dans le sleep et think
}
bool	is_philo_dead(t_thread	*philo)
{
	struct timeval now_t;
	long	elapsed_time;

	elapsed_time = 0;
	philo->converted_time = 0;
	usleep(1000);
	if (gettimeofday(&now_t, NULL) == -1)
		return (printf ("gettime failure\n"), false);
	elapsed_time = (now_t.tv_sec - philo->start_t.tv_sec) * 1000000 + (now_t.tv_usec - philo->start_t.tv_usec);
	philo->converted_time = elapsed_time / 1000.0;
	printf("elapsed time is %ld micro seconds\n", elapsed_time);
	printf("converted time is %f miliseconds\n", philo->converted_time);
	if (philo->converted_time + philo->last_meal >= philo->d_timer)
		return (printf ("philo %d is dead within %f ms\n", philo->phil_name, philo->converted_time + philo->last_meal), false);
	else
		return (printf("philo %d has started since %f ms\n", philo->phil_name, philo->converted_time + philo->last_meal), true);
	return (true);
}
