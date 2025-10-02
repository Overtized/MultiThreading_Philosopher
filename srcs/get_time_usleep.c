/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_usleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:17:59 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/02 18:44:21 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_death(t_thread	*philo)
{
	long	new_time;

	new_time = 0;
	philo->elapsed_t = 0;
	new_time = get_time();
	if (new_time == -1)
		return (new_time);
	philo->elapsed_t = new_time - philo->start_time ;
	// printf("elapsed time is %ld micro seconds\n", elapsed_time);
	// printf("converted time is %d miliseconds\n", philo->converted_time);
	return (0);
}
// long	get_eat_time(t_thread *philo)
// {
// 	long	elapsed_time;

// 	elapsed_time = 0;
// 	elapsed_time = get_time();
// 	if (elapsed_time == -1)
// 		return(elapsed_time);
// 	printf("%ld\n",elapsed_time);
// 	// printf("%ld\n",philo->last_meal_t);
// 	elapsed_time = elapsed_time - philo->start_time;
// 	printf("%ld\n",elapsed_time);
// 	// printf ("%ld\n", elapsed_time);
// 	return (elapsed_time);
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
void	*ft_usleep(long time_to_wait, t_thread *philo)
{
	long end_t;

	if (is_philo_dead(philo) == NULL)
		return (NULL);
	end_t = get_time() + time_to_wait;
	while (get_time() < end_t)
	{
		usleep(200);
		if (is_philo_dead(philo) == NULL)
			return (NULL);
	}
	return((void *)1);
}