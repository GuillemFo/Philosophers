/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:08:19 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 12:55:34 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned long long time)
{
	unsigned long long	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < time)
		usleep(100);
}

void	increase_finished(t_data *data)
{
	data->finished += 1;
}

int	get_finished(t_data *data)
{
	int	i;

	i = data->finished;
	return (i);
}

int	get_ph_meals(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->lock);
	i = philo->meals;
	pthread_mutex_unlock(&philo->lock);
	return (i);
}

void	ft_print_p(t_philo *philo, unsigned long long t, int p, char *s)
{
	bool	i;

	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->dead);
	i = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->dead);
	if (i == false || !ft_strcmp(s, "died"))
		printf("%llu %d %s\n", t, p, s);
	pthread_mutex_unlock(&philo->data->print);
}
