/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:12:37 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/14 11:12:37 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_data *philo)
{
	int	i;

	i = 0;
	philo->mutex_array = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->mutex_array)
		return (3);
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->mutex_array[i], NULL) != 0)
		{
			perror("Mutex error");
			return (1);
		}
		i++;
	}
	if (init_mutex_3(philo) == 1)
		return (1);
	return (0);
}

void	cleanup_mutex(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->mutex_array[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->print);
	pthread_mutex_destroy(&philo->philo->death_mutex);
	pthread_mutex_destroy(&philo->philo->eat);
	pthread_mutex_destroy(&philo->philo->eto);
}

int	init_mutex_3(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->philo[i].eat, NULL) != 0)
		{
			perror("Failed to initialize eat");
			return (1);
		}
		if (pthread_mutex_init(&data->philo[i].death_mutex, NULL) != 0)
		{
			perror("Failed to initialize death mutex");
			return (1);
		}
		if (pthread_mutex_init(&data->philo[i].eto, NULL) != 0)
		{
			perror("Failed to initialize death mutex");
			return (1);
		}
		i++;
	}
	if (last_mutex_init(data) == 1)
		return (1);
	return (0);
}

int	last_mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		perror("Failed to initialize print");
		return (1);
	}
	return (0);
}
