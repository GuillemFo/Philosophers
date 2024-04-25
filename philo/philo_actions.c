/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 12:52:45 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if ((philo->data->is_dead) == true)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (-99);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

void	ft_think(t_philo *philo)
{
	ft_print_p(philo, get_curr_time_f(philo->data), philo->id, "is thinking");
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_p(philo, get_curr_time(philo->data), philo->id,
		"has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	ft_print_p(philo, get_curr_time(philo->data), philo->id,
		"has taken a fork");
	pthread_mutex_lock(&philo->lock);
	philo->lst_meal = get_time_ms();
	pthread_mutex_unlock(&philo->lock);
	p_meals(philo);
	ft_print_p(philo, get_curr_time(philo->data), philo->id, "is eating");
	ft_usleep(philo->t_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine(void *aux)
{
	t_philo	*philo;

	philo = aux;
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->lst_meal = philo->data->t0;
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_unlock(&philo->lock);
	if (philo->id % 2 == 0)
		ft_usleep(150);
	while (check_philo_status(philo) == 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	ft_monitor(t_data *data)
{
	int	p;
	int	j;

	while (check_philo_status(data->philo) == false)
	{
		j = ft_finished(data);
		p = ft_is_dead(data);
		if (p > 0)
		{
			ft_print_death(data->philo, get_curr_time(data), p, "died");
			return (1);
		}
		if (j == -20)
		{
			data->is_dead = true;
			return (2);
		}
	}
	return (0);
}
