/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/28 11:29:37 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	philos_routine(t_thread	*philo)
{
	if (!take_fork(philo))
		return (false);
	is_eating(philo);
	putdown_fork(philo);
	is_sleeping(philo);
	is_thinking(philo);
	return (true);
}
void	*start_diner(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	if (gettimeofday(&philo->start_t, NULL) == -1)
		return (perror("gettime failure\n"), NULL);
	while (philo->meal_taken < philo->meal_nb)
	{
		if (!philos_routine(philo))
			break;
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
		// printf("philo %d has started\n", philos[i].phil_name);
		i++;
	}
	i = 0;
	while (i < params->nb_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (perror("thread end fail\n"), false);
		// printf("philo %d has finished\n", philos[i].phil_name);
		i++;
	}
	return (true);
}

