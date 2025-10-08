/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 18:17:18 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	death_msg(t_thread *philos, t_philo_p *params, int i)
{
	long	time;

	pthread_mutex_lock(&philos->params->death);
	params->stop = true;
	philos[i].is_alive = false;
	pthread_mutex_unlock(&philos->params->death);
	pthread_mutex_lock(&philos[i].elapsed_m);
	time = get_time();
	philos[i].elapsed_t = time - philos[i].start_time;
	pthread_mutex_unlock(&philos[i].elapsed_m);
	print_message(&philos[i], "died\n");
}

void	*monitor(t_philo_p *params, t_thread *philos)
{
	int		i;
	long	now;
	long	last_meal;

	last_meal = 0;
	while (1)
	{
		i = 0;
		while (i < params->nb_philo)
		{
			if (check_philo_done(params, philos, &i))
				continue ;
			pthread_mutex_lock(&philos[i].last_meal);
			last_meal = philos[i].last_meal_t;
			pthread_mutex_unlock(&philos[i].last_meal);
			now = get_time() - philos[i].start_time;
			if (now - last_meal >= philos[i].d_timer)
				return (death_msg(philos, params, i), NULL);
			i++;
		}
		if (check_meal_complete(params))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

void	*start_diner(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	if (!wait_all_thread_c(philo))
		return (NULL);
	if (philo->phil_name % 2 == 0)
		usleep((philo->e_timer * 1000) / 2);
	if (philo->meal_nb > 0)
	{
		if (meal_is_set_case(philo) == NULL)
			return (NULL);
		else
			return ((void *) 1);
	}
	else
	{
		while (1)
		{
			if (!philos_routine(philo))
				return (NULL);
			usleep(500);
		}
	}
	return ((void *) 1);
}

bool	init_threads(t_philo_p *params, t_thread *philos)
{
	int	i;

	i = 0;
	while (i < params->nb_philo)
	{
		if (pthread_create(&philos[i].t, NULL, &start_diner, &philos[i]) != 0)
			return (perror("thread create fail\n"), false);
		i++;
	}
	wait_all_thread_m(philos);
	monitor(params, philos);
	i = 0;
	while (i < params->nb_philo)
	{
		if (pthread_join(philos[i].t, NULL) != 0)
			return (perror("thread end fail\n"), false);
		i++;
	}
	return (true);
}
