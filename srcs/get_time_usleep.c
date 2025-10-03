/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_usleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:17:59 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/03 17:32:28 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// long	get_time_death(t_thread	*philo)
// {
// 	long	new_time;

// 	new_time = 0;
// 	philo->elapsed_t = 0;
// 	new_time = get_time();
// 	if (new_time == -1)
// 		return (new_time);
// 	philo->elapsed_t = new_time - philo->start_time ;
// 	(void) philo;
// 	return (0);
// }

long	get_time()
{
	struct timeval now_t;
	long	elapsed_time;

	if (gettimeofday(&now_t, NULL) == -1)
		return (printf ("gettime failure\n"), -1);
	elapsed_time = (now_t.tv_sec * 1000) + (now_t.tv_usec / 1000); // t since epoch in ms
	return (elapsed_time);

}
void	*ft_usleep(long time_to_wait)
{
	long end_t;

	end_t = get_time() + time_to_wait;
	while (get_time() < end_t)
		usleep(200);
	return((void *)1);
}