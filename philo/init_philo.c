/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:20:31 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 21:29:11 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_finished(t_data *data)
{
	int			i;
	int			k;

	i = 0;
	k = get_data_meal(data);
	while (i < get_nb_philo(data))
	{	
		if (k != 0 && get_ph_meals(&data->philo[i]) >= k)
		{
			if (get_ph_meals(&data->philo[i]) == k)
				increase_finished(data);
			if (get_finished(data) >= k)
				return (-20);
		}
		i++;
	}
	return (0);
}

int	ft_is_dead(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nb_philo)
	{	
		if (get_time_ms() -  lst_meal_time(&data->philo[i]) >=
			death_time(&data->philo[i]))
		{
			pthread_mutex_lock(&data->dead);
			data->is_dead = true;
			pthread_mutex_unlock(&data->dead);
			return (data->philo[i].id);
		}
		usleep(10);
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].meals = -1;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		data->philo[i].r_fork = &data->fork[i];
		if (i < data->nb_philo - 1)
			data->philo[i].l_fork = &data->fork[i + 1];
		else
			data->philo[i].l_fork = &data->fork[0];
		data->philo[i].t_death = data->t_death;
		data->philo[i].t_eat = data->t_eat;
		data->philo[i].t_sleep = data->t_sleep;
		data->philo[i].nb_meal = data->nb_meal;
		data->philo[i].lst_meal = get_time_ms();
		i++;
	}
	return (0);
}

int	create_philos(t_data *data)
{
	int	i;

	i = 0;

	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].tid, NULL, routine, &data->philo[i]);
		i++;
	}
	data->t0 = get_time_ms();
	pthread_mutex_unlock(&data->lock);
	if (ft_monitor(data) != 0)
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_join(data->philo[i].tid, NULL);
			i++;
		}
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_mutex_destroy(&data->fork[i]);
			pthread_mutex_destroy(&data->philo[i].lock);
			i++;
		}
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->lock);
	return (0);
}

int	create_one_philo(t_data *data)
{
	pthread_create(&data->philo[0].tid, NULL, routine, &data->philo[0]);
	while (data->is_dead == false)
	{
		int	p;
		
		p = ft_is_dead(data);
		if (p > 0)
		{
			ft_print_p(data->philo, get_curr_time_f(data), p, "is eating");
			break ;
		}
	}
	pthread_detach(data->philo[0].tid);
	pthread_mutex_destroy(&data->fork[0]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	return (0);
}
