/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:10:10 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/03 12:33:06 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philos(t_philo_p *params, t_thread *phil)
{
	int		i;

	i = 0;
	while (i < params->nb_philo)
	{
		phil[i].phil_name = i + 1;
		phil[i].nb_philo = params->nb_philo;
		phil[i].ready_to_eat = false;
		phil[i].is_alive = true;
		phil[i].state_change = true;
		phil[i].last_meal_t = 0;
		phil[i].elapsed_t = 0;
		phil[i].start_time = get_time();
		phil[i].d_timer = params->d_timer;
		phil[i].e_timer = params->e_timer;
		phil[i].s_timer = params->s_timer;
		phil[i].r_fork = &params->forks[i];
		phil[i].l_fork = &params->forks[(i + 1) % params->nb_philo];
		if (params->meal_nb)
			phil[i].meal_nb = params->meal_nb;
		i++;
	}
}

