/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:22:59 by ana-cast          #+#    #+#             */
/*   Updated: 2023/12/22 12:54:26 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line_bon(int fd)
{
	static char	*buffer[1392];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd] || !ft_gn_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_add_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	return (get_result_buffer(&buffer[fd]));
}
