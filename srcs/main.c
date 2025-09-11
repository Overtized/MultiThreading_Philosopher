/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:57 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/11 15:40:14 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_philo_p params;
	t_phil **philos;

	if (!check_args(&params, ac, av))
		return (1);
	//launch philos
	//freeall
	printf(" hello world\n");
	(void) philos;
	// les args doivent etre passes sous forme d unisgned int sauf pour time to eat et sleep en miliseconde (double ?)
	// les philo sont nommes et ranges de 1 a nb of philo et assis dans leurs ordre croissant 
	// tu dois representer des philosophers a l'aide de thread (pthread_create), utiliser usleep pour les faire attendre que un autre thread finisse une tache
	// entre chaque philo tu as une fork (une a gauche une a droite donc suposant table ronde (sauf si un seul philo, un seul fork !!))
	//empecher les philo de duppliquer les fork avec mutex
	return (0);
}
/*Program name philo

Turn in files Makefile, *.h, *.c, in directory philo/

Makefile NAME, all, clean, fclean, re

Arguments number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]

External functs. memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock

Libft authorized No

Description Philosophers with threads and mutexes

The specific rules for the mandatory part are:

•Each philosopher must be represented as a separate thread.

•There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, they will have access to just one fork.

•To prevent philosophers from duplicating forks, you should protect each fork’s state
with a mutex.

*/