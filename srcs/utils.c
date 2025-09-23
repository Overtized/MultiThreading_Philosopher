/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:22:16 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/23 16:51:08 by mchanlia         ###   ########.fr       */
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
	return(result);
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
void	print_params(t_thread *params)
{
	printf("Param 0 is equal to %d this represent number of philos\n", params->nb_philo);
	printf("Param 1 is equal to %d this represent death timer\n", params->d_timer);
	printf("Param 2 is equal to %d this represent time to eat\n", params->e_timer);
	if (params->meal_nb != 0)
		printf("Param 4 is equal to %d this represent number of meal needed\n", params->meal_nb);
	printf("Param 3 is equal to %d this represent sleep time\n\n", params->s_timer);
}

