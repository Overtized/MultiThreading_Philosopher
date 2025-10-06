/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:56:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 22:10:46 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	philos_routine(t_thread	*philo)
{
	if (is_eating(philo) == NULL)
		return (false);
	if (is_sleeping(philo) == NULL)
		return (false);
	if (is_thinking(philo) == NULL)
		return (false);
	return (true);
}

static void	death_msg(t_thread *philos, t_philo_p *params, int i)
{
	long	time;

	time = get_time();
	philos[i].elapsed_t = time - philos[i].start_time;
	pthread_mutex_lock(&philos->params->death);
	philos[i].is_alive = false;
	params->stop = true;
	pthread_mutex_unlock(&philos->params->death);
	print_message(&philos[i], ", died\n");
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
			pthread_mutex_lock(&philos[i].last_meal);
			last_meal = philos[i].last_meal_t;
			pthread_mutex_unlock(&philos[i].last_meal);
			now = get_time() - philos[i].start_time;
			if (now - last_meal > philos[i].d_timer)
				return (death_msg(philos, params, i), NULL);
			i++;
		}
		usleep(500);
		pthread_mutex_lock(&params->meal_complete_m);
		if (params->meal_complete == params->nb_philo)
			return (pthread_mutex_unlock(&params->meal_complete_m), NULL);
		pthread_mutex_unlock(&params->meal_complete_m);
	}
	return (NULL);
}

void	*start_diner(void *params)
{
	t_thread	*philo;

	philo = (t_thread *) params;
	if (philo->phil_name % 2 == 0)
		ft_usleep(5, philo);
	if (philo->meal_nb > 0)
	{
		while (philo->meal_taken < philo->meal_nb)
			if (!philos_routine(philo))
				return (NULL);
		if (philo->meal_taken == philo->meal_nb)
		{
			pthread_mutex_lock(&philo->params->meal_complete_m);
			philo->params->meal_complete += 1;
			pthread_mutex_unlock(&philo->params->meal_complete_m);
		}
	}
	else
	{
		while (1)
			if (!philos_routine(philo))
				break ;
	}
	return (NULL);
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
