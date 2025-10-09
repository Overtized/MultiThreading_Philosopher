/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:58:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/09 13:58:07 by mchanlia         ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	meal_complete_m;
	pthread_mutex_t	p_start_m;
	bool			stop;
	bool			someone_died;
	int				fork_clean;
	int				last_meal_clean;
	int				meal_taken_clean;
	int				elapsed_m_clean;
	int				meal_complete;
	int				phil_name;
	int				p_start;
	int				nb_philo;
	int				d_timer;
	int				e_timer;
	int				s_timer;
	int				meal_nb;
	int				thread_fail_nb;
}	t_philo_p;

typedef struct s_thread
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	elapsed_m;
	pthread_mutex_t	meal_taken_m;
	pthread_t		t;
	t_philo_p		*params;
	bool			is_alive;
	bool			state_change;
	bool			stop;
	long			start_time;
	long			last_meal_t;
	int				elapsed_t;
	int				nb_philo;
	int				phil_name;
	int				d_timer;
	int				e_timer;
	int				s_timer;
	int				meal_nb;
	int				meal_taken;
}	t_thread;

// check args
bool	test_int(char *av[]);
bool	fill_struct(t_philo_p *params, char *av[]);
bool	check_args(t_philo_p *params, int ac, char *av[]);
// fork init
bool	take_fork(t_thread	*philo);
void	putdown_fork(t_thread	*philo);
// free struct
void	free_struct(t_philo_p *params, t_thread	*philos);
// get time
long	get_time(void);
bool	ft_usleep(long time_to_wait, t_thread *philo);
bool	update_elasped_time(t_thread	*philo);
bool	update_e_time_last_meal(t_thread	*philo);
// init philo
void	*init_philos(t_philo_p *params, t_thread *phil);
// init-thread
void	*monitor(t_philo_p *params, t_thread *philos);
void	*start_diner(void *params);
bool	init_threads(t_philo_p *params, t_thread *philos);
// mutexes_check
void	meal_complete_mutex(t_thread	*philo);
void	meal_taken_mutex(t_thread *philo, long *meal_taken);
bool	check_meal_complete(t_philo_p *params);
void	increase_meal_taken(t_thread *philo);
void	*meal_is_set_case(t_thread *philo);
// mutexes check2
bool	wait_all_thread_c(t_thread *philo);
void	wait_all_thread_m(t_thread *philo);
bool	check_philo_done(t_philo_p *params, t_thread *philos, int *i);
// philo routine
bool	philos_routine(t_thread	*philo);
// philo func
bool	is_eating(t_thread	*philo);
bool	is_sleeping(t_thread	*philo);
bool	is_thinking(t_thread	*philo);
// print message
void	print_message(t_thread *philos, const char *msg);
bool	check_thread_death(t_thread *philos);
// utils
bool	is_not_int(char *str);
bool	is_overflow(const char *str);
int		mini_atoi(const char *str);
void	*mini_calloc(size_t nmemb, size_t size);
void	print_params(t_thread *params);

#endif