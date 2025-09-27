/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:10:10 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/28 00:55:22 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_thread	*init_philos(t_philo_p *params, t_thread *phil)
{
	int		i;

	i = 0;
	while (i < params->nb_philo)
	{
		phil[i].phil_name = i + 1;
		phil[i].nb_philo = params->nb_philo;
		phil[i].d_timer = params->d_timer;
		phil[i].e_timer = params->e_timer;
		phil[i].s_timer = params->s_timer;
		if (params->meal_nb)
			phil[i].meal_nb = params->meal_nb;
		phil[i].r_fork = &params->forks[i];
		phil[i].l_fork = &params->forks[(i + 1) % params->nb_philo];
			i++;
	}
	return (phil);
}
