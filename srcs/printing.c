/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:16:46 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/14 12:18:47 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	printing_2(int philo_id, int state, t_philo *philo)
{
	if (state == 4)
	{
		pthread_mutex_lock(&philo->data->print);
		printf(THINKING, ft_get_time() - philo->data->t_jour, philo_id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (state == 5)
	{
		pthread_mutex_lock(&philo->data->print);
		printf(FORK, ft_get_time() - philo->data->t_jour, philo_id);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	printing(int philo_id, int state, t_philo *philo)
{
	philo_id++;
	if (get_gameover(philo->data) == 1 || all_eaten(philo) == 1)
		return ;
	else if (state == 2)
	{
		pthread_mutex_lock(&philo->data->print);
		printf(EATING, ft_get_time() - philo->data->t_jour, philo_id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (state == 3)
	{
		pthread_mutex_lock(&philo->data->print);
		printf(SLEEPING, ft_get_time() - philo->data->t_jour, philo_id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (state == 4 || state == 5)
		printing_2(philo_id, state, philo);
}
