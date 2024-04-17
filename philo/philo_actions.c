/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/17 11:52:27 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	uint64_t	time;
	time =  (get_time_ms() - philo->lst_meal + philo->data->t_sleep) - philo->data->t0;
	//printf("%llu Philo: %d Time 1\n", time, philo->id);
	//printf("%llu Philo: %d Time 2\n", philo->data->t0 - time , philo->id);

	if (time > philo->data->t_death)
	{
		pthread_mutex_lock(&philo->data->lock);
		philo->data->is_dead = true;
		pthread_mutex_unlock(&philo->data->lock);
		printf("%llu Philo: %d died\n", time, philo->id);
		//pthread_join(philo->tid, NULL);
	}
	else
	{
		printf("%llu Philo: %d is thinking\n", time, philo->id);
		usleep(time * 1000);
	}
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->lock);
	philo->lst_meal = (get_time_ms() - philo->data->t0);
	pthread_mutex_unlock(&philo->lock);
	printf("%llu Philo: %d is eating\n", philo->lst_meal, philo->id);
	usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	//pthread_join(philo->tid, NULL);
}

void	ft_sleep(t_philo *philo)
{
	uint64_t	time;
	time = (get_time_ms() - philo->lst_meal) - philo->data->t0;
	printf("%llu Philo: %d is sleeping\n", time, philo->id);
	usleep(philo->data->t_sleep * 1000);
	//pthread_join(philo->tid, NULL);
}

void	*routine(void *aux)
{
	t_philo *philo;
	int	i;

	philo = aux;
	i = 0;

	ft_eat(philo);
	ft_sleep(philo);
	ft_think(philo);
	
	//ft_is_dead(&philo);
	return (NULL);
}


int	create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].tid, NULL, routine, &data->philo[i]);
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
	//i = 0;
	//while (i < data->nb_philo)
	//{
	//	pthread_join(data->philo[i].tid, NULL);
	//	i++;
	//}
	return (0);
}
