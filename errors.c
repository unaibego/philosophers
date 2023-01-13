/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:45:44 by ubegona           #+#    #+#             */
/*   Updated: 2023/01/13 14:23:52 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_erros(int argc, char **argv)
{
	int	i;
	int	start;

	if (argc != 6 && argc != 5)
		return (printf("Error: Cantidad de argumentos erronea\n"), 1);
	start = 1;
	while (argv[start])
	{
		i = -1;
		while (argv[start][++i])
		{
			if ((argv[start][i] < '0' || argv[start][i] > '9'))
				return (printf("Error: Un argumento no es numérico\n"), 1);
		}
		if ((ft_atoi(argv[start]) > 2147483647 || ft_atoi(argv[start]) < 1))
			return (printf("Error : Valor fuera de los límites\n"), 1);
		start++;
	}
	if (ft_atoi(argv[1]) > 250)
		return (printf("Error : Valor de filosofos fuera de los límites\n"), 1);
	return (0);
}
