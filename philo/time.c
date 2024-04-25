/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:17 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:52:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	lst_meal_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = philo->lst_meal;
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

unsigned long long	death_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_death);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

unsigned long long	eat_time(t_philo *philo)
{
	unsigned long long	tm;

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

	i = (data->nb_meal);
	return (i);
}

unsigned long long	sleep_time(t_philo *philo)
{
	unsigned long long	tm;

	pthread_mutex_lock(&philo->lock);
	tm = (philo->t_sleep);
	pthread_mutex_unlock(&philo->lock);
	return (tm);
}

unsigned long long	get_curr_time(t_data *data)
{
	unsigned long long	tm;

	tm = get_time_ms();
	pthread_mutex_lock(&data->lock);
	tm = tm - data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

unsigned long long	get_curr_time_f(t_data *data)
{
	unsigned long long	tm;

	tm = get_time_ms();
	tm = tm - data->t0;
	return (tm);
}

unsigned long long	init_time(t_data *data)
{
	unsigned long long	tm;

	pthread_mutex_lock(&data->lock);
	tm = data->t0;
	pthread_mutex_unlock(&data->lock);
	return (tm);
}

unsigned long long	get_time_ms(void)
{
	struct timeval	time;
	unsigned long long		t;

	gettimeofday(&time, NULL);
	t = (unsigned long long)(time.tv_sec * 1000) + (unsigned long long)(time.tv_usec / 1000);
	return (t);
}
