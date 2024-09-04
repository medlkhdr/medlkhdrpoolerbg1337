/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:54:43 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/12 22:56:14 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_dest;
	unsigned int	i_src;
	unsigned int	i;
	unsigned int	m;

	i_dest = len(dest);
	i_src = len(src);
	i = 0;
	m = 0;
	if (size == 0)
		return (i_src);
	if (i_dest >= size)
		return (size + i_src);
	while (src[m] && i_dest + m < size - 1)
	{
		dest[i_dest + m] = src[m];
		m++;
	}
	dest [m + i_dest] = '\0';
	return (i_src + i_dest);
}
