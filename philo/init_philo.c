/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:20:31 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 15:16:26 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_p(uint64_t t, int p, char *s)
{
	printf("%llu %d %s\n", t, p, s);
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
			pthread_mutex_lock(&data->lock);
			data->is_dead = true;
			pthread_mutex_unlock(&data->lock);
			return (data->philo[i].id);
		}
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
		data->philo[i].r_fork = &data->fork[i];
		if (i < data->nb_philo - 1)
			data->philo[i].l_fork = &data->fork[i + 1];
		else
			data->philo[i].l_fork = &data->fork[0];
		data->philo[i].t_death = data->t_death;
		data->philo[i].t_eat = data->t_eat;
		data->philo[i].t_sleep = data->t_sleep;
		data->philo[i].nb_meal = data->nb_meal;
		data->philo[i].meals_cnt = 0;
		data->philo[i].lst_meal = get_time_ms();
		i++;
	}
	return (0);
}

int	create_philos(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->lock);
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].tid, NULL, routine, &data->philo[i]);
		i++;
	}
	//data->t0 = get_time_ms();
	pthread_mutex_unlock(&data->lock);
	while (data->is_dead == false)
	{
		int	p;
		
		p = ft_is_dead(data);
		if (p > 0)
	printf("hola?\n");
		{
			printf(C_RED "%llu Philo: %d  died\n"C_WHI, get_curr_time(data), p);
		}
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_join(data->philo[i].tid, NULL);
	}
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(data->philo[i].r_fork);
	return (0);
}
