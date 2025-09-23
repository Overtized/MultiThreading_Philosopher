/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/23 17:27:25 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	if (philo->nb_philo > 1)
		if (pthread_mutex_init(&philo->l_fork, NULL) != 0)
			return (perror("mutex init issue\n"), NULL); 
	if (pthread_mutex_init(&philo->r_fork, NULL) != 0)
		return (perror("mutex init issue\n"), NULL); 
	is_eating(philo);
	// is_sleeping(philo);
	// is_thinking(philo);
	if (philo->nb_philo > 1)
		if (pthread_mutex_destroy(&philo->l_fork) != 0)
			return (perror("mutex init issue\n"), NULL); 
	if (pthread_mutex_destroy(&philo->r_fork) != 0)
		return (perror("mutex init issue\n"), NULL); 
	return (NULL);
	// check si la fork est utilise ou pas, si le philo est mort ou pas
}

bool	init_threads(t_philo_p params, t_thread *philos)
{
	int			i;

	i = 0;
	while (i < params.nb_philo)
	{
		if (pthread_create(&philos[i].t, NULL, &routine, &philos[i]) != 0)
			return (perror("thread create fail\n"), false);
		printf("philo %d has started\n", philos[i].phil_name);
		i++;
	}
	i = 0;
	while (i < params.nb_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (perror("thread end fail\n"), false);
		printf("philo %d has finished\n", philos[i].phil_name);
		i++;
	}
	return (true);
}
