/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:21:19 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:26:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define DEAD "%lld %d died\n"
# define EATING "%lld %d is eating\n"
# define SLEEPING "%lld %d is sleeping\n"
# define THINKING "%lld %d is thinking\n"
# define FORK "%lld %d has taken a fork\n"

struct	s_data;

typedef struct t_data
{
	struct s_philo	*philo;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo_must_eat;
	int				nb_have_eaten;
	int				game_over;
	long long		passed_time_eat;
	long long		passed_time_to_sleep;
	long long		passed_time_to_fork;
	long long		t_jour;
	int				philo_id;
	pthread_mutex_t	*mutex_array;
	pthread_mutex_t	print;
	pthread_mutex_t	death;

}					t_data;

typedef struct s_philo
{
	t_data			*data;
	int				philo_id;
	int				game_over;
	long long		last_meal;
	pthread_t		thread;
	pthread_t		check_death;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	eat;
	pthread_mutex_t	eto;
	int				index_eaten;

}					t_philo;

/////////PARSING///////////////////////////
int					ft_atoi(const char *str);
int					ft_is_num(char *str);
int					ft_parsing(char **argv);
///////initialisation//////////////////////////
int					init_thread(t_data *philo);
int					init_data(char **argv, t_data *philo, int ac);
t_data				*init_philo(t_data *philo, char **argv, int ac);
int					init_philo_2(t_data *data);
int					init_mutex(t_data *philo);
int					init_mutex_3(t_data *data);
int					one_philo(t_data *philos);
long long			timeval_to_ms(struct timeval tv);
void				ft_philo_value(char **argv, t_data *philo);
int					last_mutex_init(t_data *data);

///////////ACTION///////////////////////////
void				ft_wait_check(t_data *data);
void				printing(int philo_id, int state, t_philo *philo);
int					get_gameover(t_data *data);
int					check_if_all_eaten(t_data **data);
void				eat(t_philo *philo);
void				eat_last(t_philo *philo);
void				siesta(t_philo *philo);
void				think(t_philo *philo);
void				passed_eat(t_data *philo);
void				ft_usleep(long long time, t_philo *philo);
int					check_if_death(t_philo *philo);
void				*routine(void *phil);

void				ft_start(t_philo *philo);
int					all_eaten(t_philo *philo);
long long			ft_get_time(void);
int					check_time(t_data *data);
void				printing_2(int philo_id, int state, t_philo *philo);

////////CLEANING///////
void				cleanup_mutex(t_data *philo);
void				ft_clean(t_data *data);

//////////////////////////////////////////////////////////////////////////
#endif