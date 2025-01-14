/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:32:52 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/06 14:32:52 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

////////FUNCTION//////////

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isgraph(int c);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);
//////////BONUS_LIBFT//////////
////////STRUCT_LIBFT//////////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
////////GNL//////////
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_bzero_gnl(char *s);
void	ft_clean_str_gnl(char *str);
int		ft_check_return_gnl(char *str);
char	*ft_strdup_gnl(const char *s);
char	*get_next_line(int fd);

////////PRINTF//////////
//////STRUCT_PRINTF//////
typedef struct s_left_and_zero
{
	int		left_align;
	int		zero_pad;
}			t_left_and_zero;

//////MAIN///////
int		ft_printf(const char *format, ...);
int		ft_handle_conversion(const char **format, va_list args);

//////PARSING//////
void	ft_parse_flags(const char **format, int *width, t_left_and_zero *laf);
void	ft_handle_padding(int width, int len, int left_align, int zero_pad);

//////LEN//////
int		ft_ptrlen(uintptr_t ptr);
int		ft_numlen_hex(unsigned int num);
int		ft_numlen(int n);

//////PUT//////
int		ft_putnstr(char *str, int n);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(uintptr_t num, int is_uppercase);
int		ft_putptr(uintptr_t ptr);

//////HANDLE//////
int		ft_handle_char(char c, int width, int left_align, int zero_pad);
int		ft_handle_string(char *str, int width, int left_align);
int		ft_handle_int(int num, int width, int left_align, int zero_pad);
int		ft_handle_unsigned(unsigned int num, int width, int left_align,
			int zero_pad);
int		ft_handle_pointer(void *ptr, int width, int left_align);
int		ft_handle_hex(unsigned int num, int width, t_left_and_zero laf,
			int is_uppercase);

#endif