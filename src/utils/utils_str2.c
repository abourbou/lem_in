/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:02:08 by abourbou          #+#    #+#             */
/*   Updated: 2023/03/02 06:55:34 by sbaranes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	atoi_sp(char *str, int *i)
{
	int	result;

	result = 0;
	while (ft_isnumber(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (result);
}

int	ft_substrlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (src[x])
		x++;
	dest = malloc((x + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[y])
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = '\0';
	return (dest);
}

void	ft_putstrln(char *line)
{
	ft_putstr(line);
	write(1, "\n", 1);
}

void	print_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
}
