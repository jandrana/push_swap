/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:28:44 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/13 18:23:00 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i--;
	}
	return (0);
}
