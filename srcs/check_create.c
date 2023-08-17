/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:12:16 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/14 11:12:16 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_thread(t_data *data)
{
	int	i;

	data->t_jour = ft_get_time();
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				&data->philo[i]) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
		i++;
	}
	usleep(data->time_to_die * 1000);
	if (check_time(data) == 0)
		return (0);
	ft_wait_check(data);
	return (0);
}

int	check_time(t_data *data)
{
	int	i;

	if (data->time_to_die < (data->time_to_eat + data->time_to_sleep))
	{
		printf("%lld 2 died\n", ft_get_time() - data->t_jour);
		pthread_mutex_lock(&data->philo->death_mutex);
		data->game_over = 1;
		pthread_mutex_unlock(&data->philo->death_mutex);
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_join(data->philo[i].thread, NULL);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_wait_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (check_if_death(&(data->philo[i])) == -1)
		{
			break ;
		}
		i++;
		if (i == data->nb_philo + 1)
		{
			usleep(8000);
			i = 0;
		}
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int	get_gameover(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->philo->death_mutex);
	if (data->game_over == 1)
		i = 1;
	pthread_mutex_unlock(&data->philo->death_mutex);
	return (i);
}

int	all_eaten(t_philo *philo)
{
	int	i;

	i = 0;
	if ((philo->data->nb_philo_must_eat)
		&& (philo->data->nb_philo_must_eat) <= (philo->index_eaten))
	{
		i = 1;
	}
	return (i);
}
