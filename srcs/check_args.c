/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:35:00 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/15 14:05:33 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_args(t_philo_p *params, int ac, char *av[])
{
	if (ac < 5 || ac > 6)
		return (printf(" Wrong args numbere, args should be at least 5\n"), false);
	// check les arguments pour verifier leurs validité et les ranger dans une struct.
	(void) params;
	(void) av;
	return (true);
}
int	*pthread_init(void)
{
	int i;
	int *res;
	int *total;
	pthread_t t[3];

	i = 0;
	total = malloc(sizeof(int) * 1);
	*total = 0;
	while (i < 3)
	{
		if (pthread_create(&t[i], NULL, routine, NULL) != 0)
		return (NULL);
		printf("thead %d has started \n", i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (pthread_join(t[i], (void **) &res) != 0)
			return (NULL);
		*total += *res;
		printf("thead %d has finished \n", i);
		i++;
	}
	return (total);
}
