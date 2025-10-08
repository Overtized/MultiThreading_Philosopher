/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_check2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:04:22 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/08 15:16:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_philo_done(t_philo_p *params, t_thread *philos, int *i)
{
	int	j;

	j = *i;
	pthread_mutex_lock(&params->meal_complete_m);
	if (philos[j].meal_taken == philos[j].meal_nb)
	{
		pthread_mutex_unlock(&params->meal_complete_m);
		(*i)++;
		return (true);
	}
	pthread_mutex_unlock(&params->meal_complete_m);
	return (false);
}