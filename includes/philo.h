/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:58:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 18:36:42 by mchanlia         ###   ########.fr       */
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
	pthread_mutex_t print;
	pthread_mutex_t death;
	bool	stop;
	bool	someone_died;
	int	meal_complete;
	int	phil_name;
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
	pthread_mutex_t last_meal;
	t_philo_p	*params;
	long	start_time;
	bool	ready_to_eat;
	bool	is_alive;
	bool	state_change;
	bool	stop;
	int		elapsed_t;
	long	last_meal_t;
	int	nb_philo;
	int	phil_name;
	int	d_timer;
	int	e_timer;
	int	s_timer;
	int	meal_nb;
	int	meal_taken;
}	t_thread;


void	*start_diner(void *params);
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
void	*init_philos(t_philo_p *params, t_thread *phil);
//
void	*is_eating(t_thread	*philo);
void	*is_sleeping(t_thread	*philo);
void	*is_thinking(t_thread	*philo);
void	*take_fork(t_thread	*philo);
void	putdown_fork(t_thread	*philo);
//
void	print_params(t_thread *params);
void	*check_thread_death(t_thread *philos);
void	print_message(t_thread *philos, const char *msg);
void	free_struct(t_philo_p *params, t_thread	*philos);
long	get_time_death(t_thread	*philo);
long	get_time(void);
void	*ft_usleep(long time_to_wait, t_thread *philo);
//

#endif