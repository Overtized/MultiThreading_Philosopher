/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/27 19:22:56 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	mutex_init(t_thread *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
			return (perror("mutex init issue\n"), false);
		i++;
	}
	return (true);
}

bool	mutex_destroy(t_thread *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (philo->nb_philo > 1)
			if (pthread_mutex_destroy(&philo->forks[i]) != 0)
				return (perror("mutex init issue\n"), false);
		i++;
	}
	return (true);
}
