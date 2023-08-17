/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:52:24 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:01:48 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*init_philo(t_data *philo, char **argv, int ac)
{
	philo = NULL;
	philo = malloc(sizeof(t_data));
	if (!philo)
		return (NULL);
	ft_philo_value(argv, philo);
	if (ac == 6)
	{
		philo->nb_philo_must_eat = ft_atoi(argv[5]);
		if (philo->nb_philo_must_eat <= 0)
		{
			write(2, "Invalid argument\n", 18);
			free(philo);
			return (NULL);
		}
	}
	if (philo->nb_philo <= 0)
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}

void	ft_philo_value(char **argv, t_data *philo)
{
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->game_over = 0;
	philo->passed_time_eat = 0;
	philo->nb_philo_must_eat = 0;
}

int	init_philo_2(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (2);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].philo_id = i;
		data->philo[i].index_eaten = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].game_over = 0;
		i++;
	}
	return (0);
}

int	init_data(char **argv, t_data *philo, int ac)
{
	if (ft_parsing(argv) == 1)
		return (1);
	philo = init_philo(philo, argv, ac);
	if (!philo)
		return (4);
	if (philo->nb_philo == 1)
	{
		one_philo(philo);
		free(philo);
		return (0);
	}
	if (init_philo_2(philo) != 0)
		return (2);
	if (init_mutex(philo) != 0)
		return (5);
	if (init_thread(philo) != 0)
		return (3);
	cleanup_mutex(philo);
	ft_clean(philo);
	return (0);
}

void	ft_clean(t_data *data)
{
	free(data->mutex_array);
	data->mutex_array = NULL;
	free(data->philo);
	free(data);
}
