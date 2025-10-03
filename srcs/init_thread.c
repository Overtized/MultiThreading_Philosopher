/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/03 12:36:41 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	philos_routine(t_thread	*philo)
{
	if (philo->nb_philo > 1)
	{
		if (is_eating(philo) == NULL)
			return (false);
		if (is_sleeping(philo) == NULL)
			return (false);
	}
	if (philo->is_alive == false)
		return (false);
	is_thinking(philo);
	return (true);
}
void	*monitor(void *params)
{
	t_philo_p	data;
	t_thread	*phil;
	int	i;
	long	now;

	i = 0;
	now = 0;
	phil = (t_thread *) params;
	data.phil = phil;
	while (1)
	{
		i = 0;
		while (i < phil->nb_philo)
		{
			now = get_time() - data.phil[i].start_time;
			// printf("value is %ld\n", now);
			// printf("start is %ld\n", data.phil[i].start_time);
			// printf("last meal is %ld\n", data.phil[i].last_meal_t);
			if (now - data.phil[i].last_meal_t > data.phil[i].d_timer) 
			{
				data.phil[i].is_alive = false;
				printf ("%d ms: %d died\n", data.phil[i].elapsed_t, data.phil[i].phil_name);
				return (NULL);
			}
			i++;
		}
		usleep(500);
	}
	return (NULL);
}
void	*start_diner(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	if (philo->meal_nb > 0)
	{
		while (philo->meal_taken < philo->meal_nb)
		{
			if (!philos_routine(philo))
				break;
		}
	}
	else 
	{
		while (1)
		{
			if (!philos_routine(philo))
				break;
		}
	}
	return(NULL);
}
// a voir comment remonter l erreur si start dinner fail ? main wise

bool	init_threads(t_philo_p *params, t_thread *philos)
{
	int	i;

	i = 0;
	while (i < params->nb_philo)
	{
		if (pthread_create(&philos[i].t, NULL, &start_diner, &philos[i]) != 0)
			return (perror("thread create fail\n"), false);
		i++;
	}
	if (pthread_create(&params->monitor, NULL, &monitor, philos) != 0)
		return (perror("thread create fail\n"), false);
	i = 0;
	while (i < params->nb_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (perror("thread end fail\n"), false);
		i++;
	}
	if (pthread_join(params->monitor, NULL) != 0)
			return (perror("thread end fail\n"), false);
	return (true);
}

