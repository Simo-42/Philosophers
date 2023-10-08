/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:19:38 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/08 16:32:54 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

void	ft_usleep(long long time, t_philo *philo)
{
	long long	past;

	(void)(philo);
	past = ft_get_time();
	while (ft_get_time() - past < time)
	{
		usleep(200);
		if (get_gameover(philo->data) == 1)
			break ;
	}
	return ;
}

int	check_if_death(t_philo *philo)
{
	long long int	actual;

	pthread_mutex_lock(&philo->eat);
	actual = ft_get_time();
	if (actual - philo->last_meal > philo->data->time_to_die)
	{
		printf(DEAD, ft_get_time() - philo->data->t_jour, philo->philo_id + 1);
		pthread_mutex_lock(&philo->death_mutex);
		philo->data->game_over = 1;
		pthread_mutex_unlock(&philo->death_mutex);
		pthread_mutex_unlock(&philo->eat);
		return (-1);
	}
	pthread_mutex_unlock(&philo->eat);
	return (0);
}

void	ft_start(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = philo->data->t_jour;
	pthread_mutex_unlock(&philo->eat);
	if (philo->philo_id % 2)
		ft_usleep((philo->data->time_to_eat - 10), philo);
}

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	(void)(philo);
	ft_start(philo);
	while (42)
	{
		if (get_gameover(philo->data) == 1 || all_eaten(philo) == 1)
			return (NULL);
		if (philo->philo_id == philo->data->nb_philo - 1)
			eat_last(philo);
		else
			eat(philo);
		pthread_mutex_lock(&philo->eat);
		philo->index_eaten++;
		pthread_mutex_unlock(&philo->eat);
		if (get_gameover(philo->data) == 1 || all_eaten(philo) == 1)
			return (NULL);
		siesta(philo);
		if (get_gameover(philo->data) == 1 || all_eaten(philo) == 1)
			return (NULL);
		think(philo);
	}
	return (NULL);
}
