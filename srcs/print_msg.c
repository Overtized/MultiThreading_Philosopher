/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:45:53 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/03 14:02:20 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_thread *philos, const char *msg)
{
	if (philos->is_alive == false)
	{
		pthread_mutex_lock(&philos->print);
		printf ("%d ms: %d died\n", philos[0].elapsed_t, philos[0].phil_name);
		pthread_mutex_unlock(&philos->print);
		return ;
	}
	// a refaire pour print n'importe quel message q pqrtir de l qpelqnt pas dans la func
}