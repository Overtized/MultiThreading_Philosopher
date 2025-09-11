/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:35:00 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/11 15:40:24 by mchanlia         ###   ########.fr       */
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