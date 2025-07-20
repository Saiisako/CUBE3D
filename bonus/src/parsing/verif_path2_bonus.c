/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:20:28 by skock             #+#    #+#             */
/*   Updated: 2025/07/20 13:23:47 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_bonus.h"

void	process_path(t_cube *cube, char **str)
{
	char	*new_str;
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == ' ' || (*str)[i] == '\n' || (*str)[i] == '\t')
			break ;
		i++;
	}
	new_str = ft_substr(*str, 0, i);
	if (ft_strcmp(new_str + (ft_strlen(new_str) - 4), ".xpm") != 0)
	{
		free(new_str);
		free((*str));
		ft_error_parsing(cube, "Need .xpm extension for a texture.");
	}
	free(*str);
	*str = new_str;
}

void	verif_path(t_cube *cube, char **str)
{
	int	i;

	i = 0;
	if (ft_strlen((*str)) < 4)
	{
		free((*str));
		ft_error_parsing(cube, "Need .xpm extension for a texture.");
	}
	while ((*str)[i] && !ft_iswhitespace((*str)[i]))
		i++;
	if (!(*str)[i])
		process_path(cube, str);
	else
	{
		while (ft_iswhitespace((*str)[i]))
			i++;
		if (!(*str)[i])
			process_path(cube, str);
		else
		{
			free((*str));
			ft_error_parsing(cube, "Cannot have 2 arguments as texture file.");
		}
	}
}
