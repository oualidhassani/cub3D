/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:49:58 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 20:04:19 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*get_linee(t_list *lst);
void				read_to_list(t_list **lst, int fd);
void				add_buffer_to_list(t_list **lst, char *buffer);
t_list				*ft_lstlast(t_list *lst);
int					count_my_line(t_list *lst);
void				copy_lstline(t_list *lst, char *line);
void				clearlst(t_list **lst);
void				free_all(t_list *clean_node, char *buf, t_list **list);
#endif