/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:28:11 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 21:16:51 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (0);
}

int	load_data(char **av, t_data *data)
{
	if (check_input_valid(av) == true)
	{
		data->nb_philo = ft_atoi(av[1]);
		data->t_death = ft_atoi(av[2]);
		data->t_eat = ft_atoi(av[3]);
		data->t_sleep = ft_atoi(av[4]);
		data->nb_meal = 0;
		if (av[5])
			data->nb_meal = ft_atoi(av[5]);
		pthread_mutex_init(&data->lock, NULL);
		pthread_mutex_init(&data->print, NULL);
		pthread_mutex_init(&data->dead, NULL);
		pthread_mutex_lock(&data->lock);
		data->is_dead = false;
		data->finished = 0;
		data->fork = malloc(data->nb_philo * sizeof(pthread_mutex_t));
		init_fork(data);
		data->philo = malloc(data->nb_philo * sizeof(t_philo));
		init_philos(data);
	}
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac < 5 || ac > 6)
		return (printf("Invalid number of arguments\n"), 1);
	if (load_data(av, &data) == -1)
		return (printf("Invalid argument/s\n"), 1);
	if (data.nb_philo == 1)
		create_one_philo(&data);
	else
		create_philos(&data);
	free (data.fork);
	free (data.philo);
	return (0);
}

/*
try lock the prints and create a specific function for them.
*/