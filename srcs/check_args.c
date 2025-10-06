/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:35:00 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 21:13:51 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	test_int(char *av[])
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_not_int(av[i]))
			return (false);
		if (!is_overflow(av[i]))
			return (false);
		i++;
	}
	if (av[0][0] == '0')
		return (printf ("wrong nb of philos\n"), false);
	return (true);
}

static bool	init_m_tab(t_philo_p *params)
{
	int	i;

	i = 0;
	params->forks = mini_calloc(params->nb_philo, sizeof(pthread_mutex_t));
	if (!params->forks)
		return (false);
	while (i < params->nb_philo)
	{
		if (pthread_mutex_init(&params->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	pthread_mutex_init(&params->death, NULL);
	pthread_mutex_init(&params->print, NULL);
	pthread_mutex_init(&params->meal_complete_m, NULL);
	return (true);
}

bool	fill_struct(t_philo_p *params, char *av[])
{
	params->nb_philo = mini_atoi(av[0]);
	params->d_timer = mini_atoi(av[1]);
	params->e_timer = mini_atoi(av[2]);
	params->s_timer = mini_atoi(av[3]);
	if (av[4])
		params->meal_nb = mini_atoi(av[4]);
	else
		params->meal_nb = -1;
	params->phil_name = -1;
	if (!init_m_tab(params))
		return (false);
	params->stop = false;
	return (true);
}

bool	check_args(t_philo_p *params, int ac, char *av[])
{
	if (ac < 5 || ac > 6)
		return (printf(" Wrong args number, should be at least 5\n"), false);
	if (!test_int(&av[1]))
		return (printf("invalid arguments\n"), false);
	if (!fill_struct(params, &av[1]))
		return (printf ("fill struct failed\n"), false);
	return (true);
}
// check les arguments pour verifier leurs validité et les ranger dans une struc