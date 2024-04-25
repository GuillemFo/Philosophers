/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:30:39 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/25 02:12:28 by gforns-s         ###   ########.fr       */
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
# define C_WHI   "\x1b[37m"

/*	Reset	*/
# define C_RESET   "\x1b[0m"

typedef struct s_philo
{
	int				id;
	int				round;
	bool			full;
	pthread_t		tid;
	struct s_data	*data;
	long long		lst_meal;
	long long		t_death;
	long long		t_eat;
	long long		t_sleep;
	int				nb_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	long long		t_death;
	long long		t_eat;
	long long		t_sleep;
	int				nb_meal;
	int				cnt_finish;
	pthread_mutex_t	*fork;	
	long long		t0;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_mutex_t	dead;
	bool			is_dead;
	t_philo			*philo;
}					t_data;

bool		check_input_valid(char **av);
int			ft_atoi(const char *str);
int			init_philos(t_data *data);
int			create_philos(t_data *data);
void		*routine(void *aux);
long long	get_time_ms(void);
long long	get_curr_time_clean(t_data *data);
long long	eat_time(t_philo *philo);
long long	sleep_time(t_philo *philo);
long long	death_time(t_philo *philo);
long long	lst_meal_time(t_philo *philo);
int			ft_is_dead(t_data *data);
void		ft_usleep(long long time);
void		philo_round(t_philo *philo);
void		ft_print_p(t_philo *philo, long long t, int p, char *s);
int			create_one_philo(t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
void		increase_finished(t_data *data);
int			ft_monitor(t_data *data);
int			check_philo_status(t_philo *philo);
int			ft_finished(t_data *data);
int			get_finished(t_data *data);
long long	get_curr_time_clean_u(t_data *data);
long long	get_lst_meal(t_philo *philo);
long long	get_death_time(t_data *data);

#endif
