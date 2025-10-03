/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/03 17:38:43 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	philos_routine(t_thread	*philo)
{
	if (is_eating(philo) == NULL)
		return (false);
	if (is_sleeping(philo) == NULL)
		return (false);
	if (is_thinking(philo) == NULL)
		return (false);
	return (true);
}
void	*monitor(t_philo_p *params, t_thread *philos)
{
	int	i;
	long	now;

	i = 0;
	now = 0;
	while (1)
	{
		i = 0;
		while (i < params->nb_philo)
		{
			now = get_time() - philos[i].start_time;
			// printf("value is %ld\n", now);
			// printf("start is %ld\n", philos[i].start_time);
			// printf("last meal is %ld\n", philos[i].last_meal_t);
			// printf("death time is %d\n", philos[i].d_timer);
			if (now - philos[i].last_meal_t > philos[i].d_timer) 
			{
				philos[i].is_alive = false;
				print_message(&philos[i], ", died\n");
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
	pthread_mutex_init(&params->death, NULL);
	pthread_mutex_init(&philos->print, NULL);
	while (i < params->nb_philo)
	{
		if (pthread_create(&philos[i].t, NULL, &start_diner, &philos[i]) != 0)
			return (perror("thread create fail\n"), false);
		i++;
	}
	monitor(params, philos);
	i = 0;
	while (i < params->nb_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (perror("thread end fail\n"), false);
		i++;
	}
	pthread_mutex_destroy(&params->death);
	pthread_mutex_destroy(&philos->print);
	return (true);
}

