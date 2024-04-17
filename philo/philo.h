#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <stdbool.h>


/*
Strart trying to create 2 philos and that all input works correctly.
*/

// struct for each philo
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


//struct for all data needed for the program
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
uint64_t	get_time_ms(void);
uint64_t	get_curr_time(t_data *data);
uint64_t	eat_time(t_philo *philo);
uint64_t	sleep_time(t_philo *philo);

#endif
