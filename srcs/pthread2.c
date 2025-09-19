/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/19 16:03:32 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	pthread_mutex_lock(&philo->fork);
	// is_eating;
	// is_sleeping;
	// is_thinking;
	printf("hello from thread\n");
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
	// check si la fork est utilise ou pas, si le philo est mort ou pas
}

bool	init_threads(t_philo_p params, t_thread *philos)
{
	int			i;

	i = 0;
	
	while (i < params.nb_philo)
	{
		pthread_mutex_init(&philos[i].fork, NULL);
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
		pthread_mutex_destroy(&philos[i].fork);
		printf("thread %d has finished\n", i);
		i++;
	}
	return (true);
}
