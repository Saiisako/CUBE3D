/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:52:42 by skock             #+#    #+#             */
/*   Updated: 2025/07/13 21:52:35 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	rush(int x, int y)
{
	int	l;
	int	h;

	if (ft_error(x, y) == 1)
		return ;
	h = 1;
	while (h <= y)
	{
		l = 1;
		while (l <= x)
		{
			if ((l == 1 && h == 1) || (l == x && h == 1)
				|| (l == 1 && h == y) || (l == x && h == y))
				ft_putchar('o');
			else if (h == 1 || h == y)
				ft_putchar('-');
			else if (l == 1 || l == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			l++;
		}
		ft_putchar('\n');
		h++;
	}
}

int	main(void)
{
	rush(5, 5);
	return (1);
}
