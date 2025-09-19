/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/19 14:59:19 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *params)
{
	t_thread	*t;

	t = (t_thread *) params;
	pthread_mutex_lock(&t->fork);
	printf("hello from thread\n");
	pthread_mutex_unlock(&t->fork);
	return (NULL);
}

bool	init_threads(t_philo_p params, t_phil *philos)
{
	int			i;
	t_thread	*t;

	i = 0;
	t = malloc(sizeof(t_thread) * 1);
	if (!t)
		return (false);
	pthread_mutex_init(&t->fork, NULL);
	while (i < params.nb_philo)
	{
		if (pthread_create(&t->t[i], NULL, &routine, t) != 0)
			return (perror("thread create fail\n"), false);
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < params.nb_philo)
	{
		if (pthread_join(t->t[i], NULL) != 0)
			return (perror("thread end fail\n"), false);
		printf("thread %d has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&t->mutex);
	(void)philos;
	return (free(t), true);
}
