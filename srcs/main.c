/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:57 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 21:28:46 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_philo_p	*params;
	t_thread	*philos;

	philos = NULL;
	params = mini_calloc(1, sizeof(t_philo_p));
	if (params == NULL)
		return (printf("calloc fail\n"), 1);
	if (!check_args(params, ac, av))
		return (free_struct(params, philos), 1);
	philos = mini_calloc(params->nb_philo, sizeof(t_thread));
	if (philos == NULL)
		return (printf("calloc fail\n"), free_struct(params, philos), 1);
	if (init_philos(params, philos) == NULL)
		return (free_struct(params, philos), 1);
	if (!init_threads(params, philos))
		return (printf("thread fail\n"), free_struct(params, philos), 1);
	free_struct(params, philos);
	return (0);
}
// print_params(philos);
/*sur des timings tres court et un nombre de philo impair, il y aura toujours un
 philo qui ne mange pas et qui esseira de choper les fourchettes 
 juste avant de mourir de faim, si ils sont pairs ils alternent
les un apres les autres ce qui rend la simualtion plus stable.
time to die et time to eat sont a surveiller de pres
comme sur l'input:./philo 3 400 200 100 dies et && ./philo 3 410 200 100 live*/

// les philo sont nommes et de 1 a nb of philo et assis dans ordre croissant 
// tu dois representer des philosophers a l'aide de thread (pthread_create),
// utiliser usleep pour les faire attendre que un autre thread finisse une tache
// entre chaque philo tu as une fork (une a gauche une a droite 
// donc suposant table ronde (sauf si un seul philo, un seul fork !!))
//empecher les philo de duppliquer les fork avec mutex

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

•There is one fork between each pair of philosophers.
// Therefore, if there are several
philosophers, each philosopher has a fork on their left side
// and a fork on their right
side. If there is only one philosopher, they will have access to just one fork.

•To prevent philosophers from duplicating forks,
// you should protect each fork’s state
with a mutex.
*/