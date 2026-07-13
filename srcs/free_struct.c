/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:00:42 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/09 13:57:18 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	free_trash(t_philo_p *params, t_thread	*philos)
{
	pthread_mutex_destroy(&params->print);
	pthread_mutex_destroy(&params->death);
	pthread_mutex_destroy(&params->meal_complete_m);
	pthread_mutex_destroy(&params->p_start_m);
	free(params->forks);
	free(params);
	if (philos)
		free (philos);
}

static void	free_mutex_tab(t_philo_p *params, t_thread	*philos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < params->thread_fail_nb)
	{
		if (pthread_join(philos[j].t, NULL) != 0)
		{
			perror("thread end fail\n");
			return ;
		}
		j++;
	}
	(void) philos;
	while (i < params->fork_clean)
	{
		pthread_mutex_destroy(&params->forks[i]);
		i++;
	}
}

void	free_struct(t_philo_p *params, t_thread	*philos)
{
	int	i;

	i = 0;
	if (params)
	{
		free_mutex_tab(params, philos);
		i = 0;
		while (i < params->last_meal_clean)
		{
			pthread_mutex_destroy(&philos[i].last_meal);
			i++;
		}
		i = 0;
		while (i < params->elapsed_m_clean)
		{
			pthread_mutex_destroy(&philos[i].elapsed_m);
			i++;
		}
		while (i < params->meal_taken_clean)
		{
			pthread_mutex_destroy(&philos[i].meal_taken_m);
			i++;
		}
		free_trash(params, philos);
	}
}
