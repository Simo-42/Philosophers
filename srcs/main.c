/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:51:03 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:04:03 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long	timeval_to_ms(struct timeval tv)
{
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

int	main(int ac, char *argv[])
{
	t_data	*philo;

	philo = NULL;
	if (!(ac == 5 || ac == 6))
	{
		write(2, "Use 5 or 6 args !", 18);
		return (2);
	}
	if ((init_data(argv, philo, ac) != 0))
		return (3);
}
