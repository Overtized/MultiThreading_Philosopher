/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/02 20:27:00 by mchanlia         ###   ########.fr       */
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
	is_thinking(philo);
	if (is_philo_dead(philo) == NULL || philo->is_alive == false )
		return (false);
	return (true);
}
void	*monitor(void *params)
{
	t_philo_p	*data;

	data = (t_philo_p *) params;
	printf("hello from monitor \n");
	// while (data->is_alive)
	// {
	// 	if (data->is_alive == false)
	// 	return (NULL);
	// }
	return ((void *)1);
}
void	*start_diner(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	philo->start_time = get_time();
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
	if (pthread_create(&params->monitor, NULL, &monitor, &philos[i]) != 0)
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

