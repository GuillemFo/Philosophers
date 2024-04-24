/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:17 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 19:09:59 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	lst_meal_time(t_philo *philo)
{
	uint64_t	tm;

	pthread_mutex_lock(&philo->lock);
	tm = philo->lst_meal;
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

uint64_t	death_time(t_philo *philo)
{
	uint64_t	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_death);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

uint64_t	eat_time(t_philo *philo)
{
	uint64_t	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_eat);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

int	get_nb_philo(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->lock);
	i = (data->nb_philo);
	pthread_mutex_unlock(&data->lock);
	return (i);
}

int	get_data_meal(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->lock);
	i = (data->nb_meal);
	pthread_mutex_unlock(&data->lock);
	return (i);
}

uint64_t	sleep_time(t_philo *philo)
{
	uint64_t	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_sleep);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

uint64_t	get_curr_time(t_data *data)
{
	uint64_t	tm;

	tm = get_time_ms();
	pthread_mutex_lock(&data->lock);
	tm = tm - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

uint64_t	get_curr_time_f(t_data *data)
{
	uint64_t	tm;

	tm = get_time_ms();
	tm = tm - data->t0;
	return (tm);
}

uint64_t	init_time(t_data *data)
{
	uint64_t	tm;

	pthread_mutex_lock(&data->lock);
	tm = data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

uint64_t	get_time_ms(void)
{
	struct timeval	time;
	uint64_t		t;

	gettimeofday(&time, NULL);
	t = (uint64_t)(time.tv_sec * 1000) + (uint64_t)(time.tv_usec / 1000);
	return (t);
}
