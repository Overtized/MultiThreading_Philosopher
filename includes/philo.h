/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:58:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/19 14:58:52 by mchanlia         ###   ########.fr       */
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
# include <limits.h>

typedef struct s_philo_p
{
	int	nb_philo;
	int	d_timer;
	int	e_timer;
	int	s_timer;
	int	meal_nb;
}	t_philo_p;
typedef struct s_phil
{
	int	phil_name;
	int	d_timer;
	int	e_timer;
	int	s_timer;
	int	meal_nb;
}	t_phil;
typedef struct s_thread
{
	pthread_t		t[6];
	pthread_mutex_t	fork;
	t_phil	*philo_p;
}	t_thread;

void	*routine(void *params);
int		*pthread_init(void);
//
bool	check_args(t_philo_p *params, int ac, char *av[]);
bool	test_int(char *av[]);
//
bool	is_not_int(char *str);
bool	is_overflow(const char *str);
int		mini_atoi(const char *str);
//
bool	fill_struct(t_philo_p *params, char *av[]);
t_phil	*init_philos(t_philo_p params);
//
bool	init_threads(t_philo_p params, t_phil *philos);
// void	*routine2(void *params);
//
void	is_sleeping(t_phil *philo, t_phil params);
void	is_thinking(t_phil *philo, t_phil params);
void	is_eating(t_phil *philo, t_phil params);

#endif