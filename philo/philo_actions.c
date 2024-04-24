/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/24 15:16:59 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	check_philo_status(t_philo *philo)
{
	if ((philo->data->is_dead) == true)
		return (-99);
	return (0);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (check_philo_status(philo) == -99)
		return ;
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	ft_print_p(get_curr_time_f(philo->data), philo->id, "is thinking");
	pthread_mutex_unlock(&philo->data->lock);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (check_philo_status(philo) == -99)
		return ;
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->data->lock);
	ft_print_p(get_curr_time_f(philo->data), philo->id, "has taken a fork");
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	if (check_philo_status(philo) == -99)
	{
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->data->lock);
	ft_print_p(get_curr_time_f(philo->data), philo->id, "has taken a fork");
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	if (check_philo_status(philo) == -99)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	//pthread_mutex_unlock(&philo->data->lock);
	philo->lst_meal = get_time_ms();
	//pthread_mutex_lock(&philo->data->lock);
	p_meals(philo);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	ft_print_p(get_curr_time_f(philo->data), philo->id, "is eating");
	pthread_mutex_unlock(&philo->data->lock);
	ft_usleep(eat_time(philo), philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (check_philo_status(philo) == -99)
		return ;
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	ft_print_p(get_curr_time_f(philo->data), philo->id, "is sleeping");
	pthread_mutex_unlock(&philo->data->lock);
	ft_usleep(sleep_time(philo), philo);
}

void	*routine(void *aux)
{
	t_philo	*philo;
	
	philo = aux;
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->lock);
	while (philo->data->is_dead == false)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
