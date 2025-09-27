/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:00:42 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/28 00:52:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_struct(t_philo_p *params, t_thread	*philos)
{
	int i;

	i = 0;
	if (params)
	{
		while (i < philos->nb_philo)
		{
			if (params[i].forks)
				pthread_mutex_destroy(&params->forks[i]);
			i++;
		}
		free(params);
	}
	if (philos)
		free(philos);
}
