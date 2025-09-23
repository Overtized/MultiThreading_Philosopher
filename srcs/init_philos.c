/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:10:10 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/23 15:07:44 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	init_philos(t_philo_p params, t_thread *phil)
{
	int		i;

	i = 0;
	phil = malloc (sizeof(t_thread) * params.nb_philo);
	if (!phil)
		return (printf("wtf dude\n"), false);
	while (i < params.nb_philo)
	{
		phil[i].phil_name = i + 1;
		phil[i].nb_philo = params.nb_philo;
		phil[i].d_timer = params.d_timer;
		phil[i].e_timer = params.e_timer;
		phil[i].s_timer = params.s_timer;
		if (params.meal_nb)
			phil[i].meal_nb = params.meal_nb;
		i++;
	}
	return (true);
}
