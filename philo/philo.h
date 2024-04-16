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
Strart trying to create 2 filos and that all input works correctly.
*/

// struct for each philo
typedef struct s_philo
{
	int				id;
	pthread_t		*tid;
	struct s_data	*data;
	//pthread_mutex_t	*r_fork;
	//pthread_mutex_t	*l_fork;
}					t_philo;


//struct for all data needed for the program
typedef struct s_data
{
	int				nb_philo;
	uint64_t		t_death;
	uint64_t		t_eat;
	uint64_t		t_sleep;
	int				nb_meal;
	t_philo			*philo;
	bool			is_dead;
}					t_data;

bool	check_input_valid(char **av);
int		ft_atoi(const char *str);
int		init_philo(t_data *data, int philo_id);

#endif
