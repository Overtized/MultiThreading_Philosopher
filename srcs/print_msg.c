/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:45:53 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/03 17:42:34 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_thread *philos, const char *msg)
{
	if (philos->someone_died == false)
	{
		pthread_mutex_lock(&philos->print);
		if (philos->is_alive == true)
			printf("%d ms: %d %s\n", philos->elapsed_t, philos->phil_name, msg);
		else if (philos->is_alive == false)
		{
			printf("%d ms: %d %s\n", philos->elapsed_t, philos->phil_name, msg);
			philos->someone_died = true;
		}
		pthread_mutex_unlock(&philos->print);
	}
	return ;
	// a refaire pour print n'importe quel message q pqrtir de l qpelqnt pas dans la func
}
