/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:35:00 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/15 15:28:16 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// bool	check_args(t_philo_p *params, int ac, char *av[])
// {
// 	if (ac < 5 || ac > 6)
// 		return (printf(" Wrong args numbere, args should be at least 5\n"), false);
// 	// check les arguments pour verifier leurs validité et les ranger dans une struct.
// 	(void) params;
// 	(void) av;
// 	return (true);
// }
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
