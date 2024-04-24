/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:08:19 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 21:07:02 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(uint64_t time)
{
	uint64_t	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < time)
		usleep(50);

}

void	increase_finished(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	data->finished += 1;
	pthread_mutex_unlock(&data->lock);
}

int	get_finished(t_data *data)
{
	int	i;
	pthread_mutex_lock(&data->lock);
	i = data->finished;
	pthread_mutex_unlock(&data->lock);
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

void	p_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->meals = philo->meals + 1;
	pthread_mutex_unlock(&philo->lock);
}

void	ft_print_p(t_philo *philo, uint64_t t, int p, char *s)
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
