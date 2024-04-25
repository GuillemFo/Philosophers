/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:56:05 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 13:21:21 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_death(t_philo *philo, unsigned long long t, int p, char *s)
{
	bool	i;

	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->dead);
	i = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->dead);
	if (i == false || !ft_strcmp(s, "died"))
		printf(C_RED "%llu %d %s\n" C_RESET, t, p, s);
	pthread_mutex_unlock(&philo->data->print);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (0);
		else if (s1 == NULL)
			return (-1);
		else
			return (1);
	}
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
