/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:58:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/28 00:50:11 by mchanlia         ###   ########.fr       */
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
	pthread_mutex_t *forks;
	int	nb_philo;
	int	d_timer;
	int	e_timer;
	int	s_timer;
	int	meal_nb;
}	t_philo_p;

typedef struct s_thread
{
	pthread_t		t;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	struct timeval	start_t;
	double	converted_time;
	double	last_meal;
	int	nb_philo;
	int	phil_name;
	int	d_timer;
	int	e_timer;
	int	s_timer;
	int	meal_nb;
	int	meal_taken;
}	t_thread;

void	*start_diner(void *params);
// bool	forks_init(t_thread *philo);
bool	init_threads(t_philo_p *params, t_thread *philos);
//
bool	check_args(t_philo_p *params, int ac, char *av[]);
bool	test_int(char *av[]);
//
bool	is_not_int(char *str);
bool	is_overflow(const char *str);
int		mini_atoi(const char *str);
void	*mini_calloc(size_t nmemb, size_t size);
//
bool	fill_struct(t_philo_p *params, char *av[]);
t_thread	*init_philos(t_philo_p *params, t_thread *phil);
//
void	is_eating(t_thread	*philo);
void	is_sleeping(t_thread	*philo);
void	is_thinking(t_thread	*philo);
bool	is_philo_dead(t_thread	*philo);
bool	take_fork(t_thread	*philo);
void	putdown_fork(t_thread	*philo);
//
void	print_params(t_thread *params);
void	free_struct(t_philo_p *params, t_thread	*philos);
//


#endif