/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/23 15:17:15 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	if (philo->nb_philo > 1)
		pthread_mutex_init(&philo->l_fork, NULL);
	pthread_mutex_init(&philo->r_fork, NULL);
	is_eating(philo);
	// is_sleeping(philo);
	// is_thinking(philo);
	if (philo->nb_philo > 1)
		pthread_mutex_destroy(&philo->l_fork);
	pthread_mutex_destroy(&philo->r_fork);
	return (NULL);
	// check si la fork est utilise ou pas, si le philo est mort ou pas
}

bool	init_threads(t_philo_p params, t_thread *philos)
{
	int			i;

	i = 0;
	while (i < params.nb_philo)
	{
		if (pthread_create(&philos[i].t, NULL, &routine, philos) != 0)
			return (perror("thread create fail\n"), false);
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < params.nb_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (perror("thread end fail\n"), false);
		printf("thread %d has finished\n", i);
		i++;
	}
	return (true);
}
