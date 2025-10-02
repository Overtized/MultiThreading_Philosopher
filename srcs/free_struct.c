/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:00:42 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/02 20:27:31 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_struct(t_philo_p *params, t_thread	*philos)
{
	int i;

	i = 0;
	if (params && !params->nb_philo)
		free(params);
	else
	{
		while (i < params->nb_philo)
		{
			pthread_mutex_destroy(&params->forks[i]);
			i++;
		}
		free(params->forks);
		free(params);
		
	}
	if (philos)
		free (philos);
}
