/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:51:45 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:20:23 by codespace        ###   ########.fr       */
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
	ft_print_p(philo, get_curr_time_clean(philo->data), philo->id, "is thinking");
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_p(philo, get_curr_time_clean(philo->data), philo->id, "has R fork");
	pthread_mutex_lock(philo->l_fork);
	ft_print_p(philo, get_curr_time_clean(philo->data), philo->id, "has L fork");
	set_lst_meal(philo->data);
	philo_round(philo);
	ft_print_p(philo, get_curr_time_clean(philo->data), philo->id, "is eating");
	ft_usleep(philo->t_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_p(philo, get_curr_time_clean(philo->data), philo->id, "is sleeping");
	ft_usleep(philo->t_sleep);
}

void	*routine(void *aux)
{
	t_philo	*philo;

	philo = aux;
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_lock(&philo->lock);
	philo->lst_meal = get_time_ms();
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->data->lock);
	if(philo->id % 2 != 0)
		ft_usleep(50);
	while (check_philo_status(philo) == 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

