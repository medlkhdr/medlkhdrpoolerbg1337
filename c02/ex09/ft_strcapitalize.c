/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:46:32 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/04 19:16:52 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_l(char *str, int i)
{
	return (str[i] >= 'a' && str[i] <= 'z' );
}

int	is_u(char *str, int i)
{
	return (str[i] >= 'A' && str[i] <= 'Z' );
}

int	is_n(char *str, int i)
{
	return (str[i] >= '0' && str[i] <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	sword;

	i = 0;
	sword = 1;
	while (str[i])
	{
		if (is_l(str, i) || is_u(str, i) || is_n(str, i))
		{
			if (sword && (str[i] >= 'a' && str[i] <= 'z' ))
			{
				str[i] -= 32;
				sword = 0;
			}
			else if (!(sword) && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			else
				sword = 0;
		}
		else
			sword = 1;
		i++;
	}
	return (str);
}
