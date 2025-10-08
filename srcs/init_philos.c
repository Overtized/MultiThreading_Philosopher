/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:10:10 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 14:34:27 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*load_params(t_philo_p *params, t_thread *phil, int i)
{
	phil->phil_name = i + 1;
	phil->nb_philo = params->nb_philo;
	phil->d_timer = params->d_timer;
	phil->e_timer = params->e_timer;
	phil->s_timer = params->s_timer;
	phil->meal_nb = params->meal_nb;
	phil->last_meal_t = 0;
	phil->meal_taken = 0;
	phil->elapsed_t = 0;
	phil->ready_to_eat = false;
	phil->is_alive = true;
	phil->state_change = true;
	phil->stop = params->stop;
	phil->r_fork = &params->forks[i];
	phil->l_fork = &params->forks[(i + 1) % params->nb_philo];
	phil->start_time = get_time();
	if (pthread_mutex_init(&phil->last_meal, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&phil->elapsed_m, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&phil->meal_taken_m, NULL) != 0)
		return (NULL);
	phil->params = params;
	return ((void *) 1);
}

void	*init_philos(t_philo_p *params, t_thread *phil)
{
	int		i;

	i = 0;
	while (i < params->nb_philo)
	{
		params->last_meal_clean = i;
		params->elapsed_m_clean = i;
		if (load_params(params, &phil[i], i) == NULL)
			return (NULL);
		i++;
	}
	return ((void *) 1);
}
