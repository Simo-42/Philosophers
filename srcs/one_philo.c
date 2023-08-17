/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:02:53 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:09:21 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	one_philo(t_data *philos)
{
	printf("0 1 has taken a fork\n");
	usleep(philos->time_to_die * 1000);
	printf("%i 1 died\n", philos->time_to_die);
	return (0);
}
