/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:44:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:19:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	siesta(t_philo *philo)
{
	if (get_gameover(philo->data) == 1)
		return ;
	printing(philo->philo_id, 3, philo);
	ft_usleep(philo->data->time_to_sleep, philo);
}

void	think(t_philo *philo)
{
	printing(philo->philo_id, 4, philo);
}

void	eat_last(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_array[0]));
	printing(philo->philo_id, 5, philo);
	pthread_mutex_lock(&(philo->data->mutex_array[philo->philo_id]));
	printing(philo->philo_id, 5, philo);
	printing(philo->philo_id, 2, philo);
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->eat);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&(philo->data->mutex_array[philo->philo_id]));
	pthread_mutex_unlock(&(philo->data->mutex_array[0]));
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_array[philo->philo_id]));
	printing(philo->philo_id, 5, philo);
	pthread_mutex_lock(&(philo->data->mutex_array[philo->philo_id + 1]));
	printing(philo->philo_id, 5, philo);
	printing(philo->philo_id, 2, philo);
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->eat);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&(philo->data->mutex_array[philo->philo_id + 1]));
	pthread_mutex_unlock(&(philo->data->mutex_array[philo->philo_id]));
}
