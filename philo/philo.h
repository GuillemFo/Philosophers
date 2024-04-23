/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:30:39 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/23 09:37:50 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <stdbool.h>

/*	Regular Colors	*/
# define C_RED     "\x1b[31m"
# define C_GREEN   "\x1b[32m"
# define C_YELLOW  "\x1b[33m"
# define C_BLUE    "\x1b[34m"
# define C_MAGENTA "\x1b[35m"
# define C_CYAN    "\x1b[36m"
# define C_WHITE   "\x1b[37m"

/*	Reset	*/
# define C_RESET   "\x1b[0m"

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	struct s_data	*data;
	uint64_t		lst_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	uint64_t		t_death;
	uint64_t		t_eat;
	uint64_t		t_sleep;
	int				nb_meal;
	pthread_mutex_t	*fork;	
	uint64_t		t0;
	pthread_mutex_t	lock;
	bool			is_dead;
	t_philo			*philo;
}					t_data;

bool		check_input_valid(char **av);
int			ft_atoi(const char *str);
int			init_philos(t_data *data);
int			create_philos(t_data *data);
void		*routine(void *aux);
uint64_t	get_time_ms(void);
uint64_t	get_curr_time(t_data *data);
uint64_t	eat_time(t_philo *philo);
uint64_t	sleep_time(t_philo *philo);
uint64_t	death_time(t_philo *philo);
uint64_t	init_time(t_data *data);
uint64_t	lst_meal_time(t_philo *philo);
int			ft_is_dead(t_data *data);
int			check_philo_status(t_philo *philo);
int			ft_usleep(uint64_t time);

#endif
