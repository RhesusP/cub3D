/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:18:54 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/24 18:43:05 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include "./../../includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*get_next_line(int fd);
void	*ft_free_stash(char **stash, int create_line);

#endif