/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:12:08 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/13 18:22:21 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr_s;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char) c)
			return (&ptr_s[i]);
		i++;
	}
	return (NULL);
}
