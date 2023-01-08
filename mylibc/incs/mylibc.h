#ifndef MYLIBC_H
# define MYLIBC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "halloc.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_count
{
	char			format_char;
	char			type_c;
	char			*type_s;
	long			type_d_i;
	unsigned int	type_u;
	unsigned int	type_x_x;
	unsigned long	type_p;
	int				chars_printed;
}	t_count;

int		myisalpha(int c);
int		myisdigit(int c);
int		myisalnum(int c);
int		myisascii(int c);
int		myisprint(int c);
size_t	mystrlen(const char *s);
void	*mymemset(void *s, int c, size_t n);
void	mybzero(void *s, size_t n);
/*
incomplete type 'void' is not assignable
undefined behavior if dest||src NULL.
*/
void	*mymemcpy(void *dest, const void *src, size_t n);
void	*mymemmove(void *dest, const void *src, size_t n);
size_t	mystrlcpy(char *dst, const char *src, size_t size);
/*
mystrlcat(NULL, b, 0);
if size < dst_len, returns size + src_len w/o null termination
*/
size_t	mystrlcat(char *dst, const char *src, size_t size);
int		mytoupper(int c);
int		mytolower(int c);
/*
we need f functionality for both const str and non-const str
with no function overloading we do it by returning non-const ptr
*/
char	*mystrchr(const char *s, int c);
char	*mystrrchr(const char *s, int c);
//the dif between chars values interpreted as unsigned char C99
int		mystrncmp(const char *s1, const char *s2, size_t n);
//c and s contents are interpreted as unsigned char.
void	*mymemchr(const void *s, int c, size_t n);
int		mymemcmp(const void *s1, const void *s2, size_t n);
char	*mystrnstr(const char *big, const char *little, size_t len);
/*
if n int out of the range of int - undefined behavior.
-2147483648 input * (-1) -> (2147483648>2147483647)-2147483648
*/
int		myatoi(const char *nptr);
// mem is set to 0.  If nmemb or size is 0 returns NULL 
void	*mycalloc(size_t nmemb, size_t size);
char	*mystrdup(char *s);

char	*mysubstr(char const *s, unsigned int start, size_t len);
char	*mystrjoin(const char *s1, const char *s2);
char	*mystrtrim(char const *s1, char const *set);
char	**mysplit(char const *s, char c);
//-2147483648 input * (-1) -> (2147483648>2147483647)-2147483648
char	*myitoa(int n);
char	*mystrmapi(char const *s, char (*f)(unsigned int, char));
void	mystriteri(char *s, void (*f)(unsigned int, char*));
void	myputchar_fd(char c, int fd);
void	myputstr_fd(char *s, int fd);
void	myputendl_fd(char *s, int fd);
void	myputnbr_fd(int n, int fd);

t_list	*mylstnew(void *content);
/*
lst ptr to the head of the linked list
if new is NULL new->next may segfault
*/
void	mylstadd_front(t_list **lst, t_list *new);
int		mylstsize(t_list *lst);
t_list	*mylstlast(t_list *lst);
void	mylstadd_back(t_list **lst, t_list *new);
//free(NULL) results in noargction
void	mylstdelone(t_list *lst, void (*del)(void *));
void	mylstclear(t_list **lst, void (*del)(void*));
void	mylstiter(t_list *lst, void (*f)(void *));
t_list	*mylstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		myprintf(const char *s, ...);
void	print_format_string(const char *s, t_count *print, va_list args);
void	clear_struct(t_count *print);

void	print_arg(t_count *print, va_list args);
void	print_arg2(t_count *print, va_list args);
void	printf_putchar(t_count *print, char c, int fd);
void	printf_putstr(t_count *print, char *str, int fd);
void	printf_putnbr(t_count *print, int nbr, int fd);
void	print_u(t_count *print, unsigned int nbr, int fd);
void	print_x(t_count *print, unsigned int nbr, int fd);
void	print_p(t_count *print, unsigned long nbr, int fd);

char	*get_next_line(int fd);
char	*read_until_nl(int fd, char *str);
char	*chars_before_nl(char *str);
char	*chars_after_nl(char *str);

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char	*dst, const char *src, size_t size);
char	*gnl_strjoin(char *s1, char *s2);

#endif
