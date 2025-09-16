/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:10:10 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/16 18:36:17 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_phil	*init_philos(t_philo_p params)
{
	int		i;
	t_phil	*philos;

	i = 0;
	philos = malloc (sizeof(t_phil) * params.nb_philo);
	if (!philos)
		return (printf("wtf dude\n"), NULL);
	while (i < params.nb_philo)
	{
		philos[i].phil_name = i + 1;
		philos[i].d_timer = params.d_timer;
		philos[i].e_timer = params.e_timer;
		philos[i].s_timer = params.s_timer;
		if (params.meal_nb)
			philos[i].meal_nb = params.meal_nb;
		i++;
	}
	return (philos);
}
