/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:45:53 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/07 21:11:26 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_thread *philos, const char *msg)
{
	pthread_mutex_lock(&philos->params->print);
	pthread_mutex_lock(&philos->params->death);
	pthread_mutex_lock(&philos->elapsed_m);
	if (philos->params->someone_died == false)
	{
		if (philos->is_alive == true)
			printf("%d %d %s", philos->elapsed_t, philos->phil_name, msg);
		else if (philos->is_alive == false)
		{
			printf("%d %d %s", philos->elapsed_t, philos->phil_name, msg);
			philos->params->someone_died = true;
		}
	}
	pthread_mutex_unlock(&philos->elapsed_m);
	pthread_mutex_unlock(&philos->params->print);
	pthread_mutex_unlock(&philos->params->death);
	return ;
}

void	*check_thread_death(t_thread *philos)
{
	pthread_mutex_lock(&philos->params->death);
	if (philos->is_alive == false || philos->params->stop == true) // a voir si tu peux pas le tej le philo is alive 
	{
		pthread_mutex_unlock(&philos->params->death);
		return (NULL);
	}
	pthread_mutex_unlock(&philos->params->death);
	return ((void *)1);
}
