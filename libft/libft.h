/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:08:30 by ohassani          #+#    #+#             */
/*   Updated: 2024/03/13 02:31:43 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

int		ft_is_string_digit(char *str);
size_t	ft_calcul(char *s, char c);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s);
long	ft_atoi(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(const void *dest, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd2(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd2(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_putchar_fd2(char d, int fd);
int		ft_printfx(unsigned long n, char *hexa);
int		ft_printadres(unsigned long n);
int		ft_printf(const char *s, ...);
int		ft_printfu(unsigned int i);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*mybuffer(int fd, char *accumulation, char *buffer);
char	*linesub(char *line_buffer);
size_t	ft_strlen1(const char *s);
char	*ft_strchr1(const char *s, int c);
char	*ft_strdup1(const char *s);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*mybuffer1(int fd, char *accumulation, char *buffer);
char	*linesub1(char *line_buffer);
void	displayerrors(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
