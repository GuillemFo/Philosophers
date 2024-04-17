/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:28:11 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/17 10:55:43 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_data *data)
{
	int i;

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
		printf("Valid input, loading data\n");
		data->nb_philo = ft_atoi(av[1]);
		printf("nb_philos:%d\n", data->nb_philo);
		data->t_death = ft_atoi(av[2]);
		printf("t_death:%llu\n", data->t_death);
		data->t_eat = ft_atoi(av[3]);
		printf("t_eat:%llu\n", data->t_eat);
		data->t_sleep = ft_atoi(av[4]);
		printf("t_sleep:%llu\n", data->t_sleep);
		data->nb_meal = -1;
		if (av[5])
		{
			data->nb_meal = ft_atoi(av[5]);
			printf("nb_meal:%d\n", data->nb_meal);
		}
		data->t0 = get_time_ms();
		pthread_mutex_init(&data->lock, NULL);
		data->is_dead = false;
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
	if	(load_data(av, &data) == -1)
		return (printf("Invalid argument/s\n"), 1);
	
	create_philos(&data);
	return (0);
}




/*
	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);

*/
/*
do check if num
do ft_atoi
Create a time calculator for u_int64_t !!!! ###### !!!!! #####
initialize all variables and allocate them.
prepare a free function for each malloc alocation


*/

/*		ARGS LIST
program
number philos
time philo must not eat to die
time it takes each to eat
time it takes to sleep
times philo must eat to terminate program

if (ac != 6)
		return (printf("Invalid number of argumnts\n"));
*/

///	TESTING	///
/*
	int	x;
	x = 0;
	int rc;
	pthread_t thread_id[20];
	int tid;

	tid = pthread_self();

	while (x < 9)
	{
		x++;
		rc = pthread_create(&thread_id[x], NULL, test_print, (void *)x);
		if (rc)
		{
			printf("\n ERROR: return (code from pthread_create id %d \n", rc);
			break ;
		}
		printf("\nI am thread (%u). Created new thread (%u) in iterarion
			%d ...\n", tid, thread_id[x], x);
		if (x % 5 == 0)
			sleep(1);
	}
		pthread_exit(NULL);

*/