/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:58:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/15 13:05:08 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo_p
{
	int	nb_philo;
	int	nb_fork;
	float	d_timer;
	float	e_timer;
	int	meal_nb;
}	t_philo_p;
typedef struct s_phil
{
	int	phil_name;
	int	nb_fork;
	float	d_timer;
	float	e_timer;
	int	meal_nb;
}	t_phil;

bool	check_args(t_philo_p *params, int ac, char *av[]);
void	*routine();
int	*pthread_init(void);

#endif