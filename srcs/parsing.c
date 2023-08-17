/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:50:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:09:50 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(2, "bad arguments !\n", 17);
			return (2);
		}
		i++;
	}
	return (0);
}

int	ft_parsing(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_num(argv[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}
