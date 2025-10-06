/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:22:16 by mchanlia          #+#    #+#             */
/*   Updated: 2025/10/06 18:00:31 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_not_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	is_overflow(const char *str)
{
	int		i;
	long	result;

	result = 0;
	i = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (printf ("overflow \n"), false);
		i++;
	}
	return (true);
}

int	mini_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	*mini_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	i;
	size_t	n;

	i = 0;
	if (nmemb == 0 || size == 0 || nmemb > ULONG_MAX / size)
		return (NULL);
	if (nmemb * size > __SIZE_MAX__)
		return (NULL);
	n = nmemb * size;
	allocated = malloc (nmemb * size);
	if (!allocated)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) allocated)[i] = '\0';
		i++;
	}
	return (allocated);
}

// void	print_params(t_thread *philos)
// {
// 	printf("Param 1 is %d this is number of philos\n", philos->nb_philo);
// 	printf("Param 2 is %d this is death timer in ms\n", philos->d_timer);
// 	printf("Param 3 is %d this is time spent to eat in ms\n", philos->e_timer);
// 	printf("Param 4 is %d this is sleep time in ms\n", philos->s_timer);
// 	if (philos->meal_nb != -1)
// 		printf("Param 5 is %d this is meal needed\n", philos->meal_nb);
// }
