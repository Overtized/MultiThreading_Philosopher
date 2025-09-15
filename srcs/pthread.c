/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:19:11 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/15 17:19:59 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	*pthread_init(void)
{
	int i;
	int *res;
	int *total;
	t_thread th;
	t_thread *m;

	pthread_mutex_init(&th.mutex, NULL);
	i = 0;
	total = malloc(sizeof(int) * 1);
	*total = 0;
	while (i < 3)
	{
		m = malloc(sizeof(t_thread) * 1);
		if (!m)
			return (NULL);
		m->mutex = th.mutex;
		if (pthread_create(&th.t[i], NULL, routine, m) != 0)
			return (perror("create failed\n"), NULL);
		printf("thread %d has started \n", i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (pthread_join(th.t[i], (void **) &res) != 0)
			return (perror("join failed\n"), NULL);
		*total += *res;
		free(res);
		printf("thread %d has finished \n", i);
		i++;
	}
	pthread_mutex_destroy(&th.mutex);
	return (total);
}
void	*routine(void *params)
{
	t_thread *mutex;
	int i;
	int mails;
	int *result;

	mutex = (t_thread *) params;
	i = 0;
	mails = 0;
	result = malloc(sizeof(int) * 1);
	if (!result)
		return (false);
	while (i < 10)
	{
		pthread_mutex_lock(&mutex->mutex);
		mails += 1;
		i++;
		pthread_mutex_unlock(&mutex->mutex);
	}
	*result = mails;
	return ((void *) result);
}