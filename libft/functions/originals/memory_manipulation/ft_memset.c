/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:24:18 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/13 18:22:30 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*ptr;
	unsigned long	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = (char)c;
	return (s);
}
