/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:23:02 by ana-cast          #+#    #+#             */
/*   Updated: 2023/12/22 13:20:08 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_gn_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_gn_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = len_s1 + len_s2;
	result = (char *)malloc(sizeof(char) * i + 1);
	if (!result)
		return (free_str((char **)(&s1)));
	i = -1;
	while (++i < len_s1)
		result[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		result[i + len_s1] = s2[i];
	result[i + len_s1] = '\0';
	free_str((char **)(&s1));
	return (result);
}
