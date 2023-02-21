#include "../../include/lib.h"

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
	int i = 0;

	if (!str)
		return 0;
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
	dest = wrmalloc((x + 1) * sizeof(char));
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