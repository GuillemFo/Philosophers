/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:48:34 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:14:40 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_data *data)
{
	int			i;
	long long	sum;

	i = 0;
	while (i < data->nb_philo)
	{
		sum = (get_lst_meal(&data->philo[i]));
		printf("*****%llu ******\n", sum);
		if ( sum >=  get_death_time(data))
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

int	create_philos(t_data *data)
{
	int	i;

	i = 0;

	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].tid, NULL, routine, &data->philo[i]);
		i++;
	}
	data->t0 = get_time_ms();	//real time
	pthread_mutex_unlock(&data->lock);
	while (check_philo_status(data->philo) == false)
	{
		int	p;
		
		p = ft_is_dead(data);
		if (p > 0)
		{
			ft_print_p(data->philo, get_curr_time_clean_u(data), p, "died");
			return (1);
		}
	}
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
			ft_print_p(data->philo, get_curr_time_clean_u(data), p, "died");
			break ;
		}
	}
	pthread_detach(data->philo[0].tid);
	pthread_mutex_destroy(&data->fork[0]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	return (0);
}
