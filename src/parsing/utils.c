/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:56:47 by skock             #+#    #+#             */
/*   Updated: 2025/07/02 12:34:40 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	ft_is_upper_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_atoi_rgb(const char *str)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (-1);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	if (result > 255 || result < 0)
		return (-1);
	return (result);
}

int	is_valid_char(t_cube *cube, char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == ' '
		|| c == 'W' || c == '\n')
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			cube->count++;
			return (1);
		}
		return (1);
	}
	else
		return (0);
}

int	is_valid_start(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}
