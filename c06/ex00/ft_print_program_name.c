/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:47:21 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/10 01:50:06 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac >= 1)
	{
		while (av[0][i])
		{
			write(1, &av[0][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
