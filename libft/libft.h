/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:31:10 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/03 09:24:28 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Tests if the character is an alphabetic character in the 
 * following set: 
 * 	 101 ``A'' 102 ``B'' 103 ``C'' 104 ``D'' 105 ``E''
     106 ``F'' 107 ``G'' 110 ``H'' 111 ``I'' 112 ``J''
     113 ``K'' 114 ``L'' 115 ``M'' 116 ``N'' 117 ``O''
     120 ``P'' 121 ``Q'' 122 ``R'' 123 ``S'' 124 ``T''
     125 ``U'' 126 ``V'' 127 ``W'' 130 ``X'' 131 ``Y''
     132 ``Z'' 141 ``a'' 142 ``b'' 143 ``c'' 144 ``d''
     145 ``e'' 146 ``f'' 147 ``g'' 150 ``h'' 151 ``i''
     152 ``j'' 153 ``k'' 154 ``l'' 155 ``m'' 156 ``n''
     157 ``o'' 160 ``p'' 161 ``q'' 162 ``r'' 163 ``s''
     164 ``t'' 165 ``u'' 166 ``v'' 167 ``w'' 170 ``x''
     171 ``y'' 172 ``z''
 * 
 * @param c 
 * @return Zero if the character tests false and returns non-zero if 
 * the character tests true.
 */
int		ft_isalpha(int c);

/**
 * @brief Tests for a decimal digit character. Character given in parameter 
 * must be in the following set:
 *	 ``0''``1''``2''``3''``4''
     ``5''``6''``7''``8''``9''
 * 
 * @param c 
 * @return Zero if the character tests false and return non-zero if the
 * character tests true.
 */
int		ft_isdigit(int c);

/**
 * @brief Tests for any character for which ft_isalpha or ft_isdigit is true.
 * The character must be in the following set: 
 * 	 060 ``0'' 061 ``1'' 062 ``2'' 063 ``3'' 064 ``4''
     065 ``5'' 066 ``6'' 067 ``7'' 070 ``8'' 071 ``9''
     101 ``A'' 102 ``B'' 103 ``C'' 104 ``D'' 105 ``E''
     106 ``F'' 107 ``G'' 110 ``H'' 111 ``I'' 112 ``J''
     113 ``K'' 114 ``L'' 115 ``M'' 116 ``N'' 117 ``O''
     120 ``P'' 121 ``Q'' 122 ``R'' 123 ``S'' 124 ``T''
     125 ``U'' 126 ``V'' 127 ``W'' 130 ``X'' 131 ``Y''
     132 ``Z'' 141 ``a'' 142 ``b'' 143 ``c'' 144 ``d''
     145 ``e'' 146 ``f'' 147 ``g'' 150 ``h'' 151 ``i''
     152 ``j'' 153 ``k'' 154 ``l'' 155 ``m'' 156 ``n''
     157 ``o'' 160 ``p'' 161 ``q'' 162 ``r'' 163 ``s''
     164 ``t'' 165 ``u'' 166 ``v'' 167 ``w'' 170 ``x''
     171 ``y'' 172 ``z''
 * 
 * @param c 
 * @return Zero if the character tests false and returns non-zero if the 
 * character tests true.
 */
int		ft_isalnum(int c);

/**
 * @brief Tests for an ASCII character, which is any character between 0 and 
 * decimal 127 inclusive.
 * 
 * @param c 
 * @return Zero if the character tests false and returns non-zero if the 
 * character tests true.
 */
int		ft_isascii(int c);

/**
 * @brief Tests for any printing character, including space (‘ ’). The character 
 * must be ins the following set: 
 * 	 040 sp 041 ``!'' 042 ``"'' 043 ``#'' 044 ``$''
     045 ``%'' 046 ``&'' 047 ``''' 050 ``('' 051 ``)''
     052 ``*'' 053 ``+'' 054 ``,'' 055 ``-'' 056 ``.''
     057 ``/'' 060 ``0'' 061 ``1'' 062 ``2'' 063 ``3''
     064 ``4'' 065 ``5'' 066 ``6'' 067 ``7'' 070 ``8''
     071 ``9'' 072 ``:'' 073 ``;'' 074 ``<'' 075 ``=''
     076 ``>'' 077 ``?'' 100 ``@'' 101 ``A'' 102 ``B''
     103 ``C'' 104 ``D'' 105 ``E'' 106 ``F'' 107 ``G''
     110 ``H'' 111 ``I'' 112 ``J'' 113 ``K'' 114 ``L''
     115 ``M'' 116 ``N'' 117 ``O'' 120 ``P'' 121 ``Q''
     122 ``R'' 123 ``S'' 124 ``T'' 125 ``U'' 126 ``V''
     127 ``W'' 130 ``X'' 131 ``Y'' 132 ``Z'' 133 ``[''
     134 ``\'' 135 ``]'' 136 ``^'' 137 ``_'' 140 ```''
     141 ``a'' 142 ``b'' 143 ``c'' 144 ``d'' 145 ``e''
     146 ``f'' 147 ``g'' 150 ``h'' 151 ``i'' 152 ``j''
     153 ``k'' 154 ``l'' 155 ``m'' 156 ``n'' 157 ``o''
     160 ``p'' 161 ``q'' 162 ``r'' 163 ``s'' 164 ``t''
     165 ``u'' 166 ``v'' 167 ``w'' 170 ``x'' 171 ``y''
     172 ``z'' 173 ``{'' 174 ``|'' 175 ``}'' 176 ``~''
 * 
 * @param c 
 * @return int 
 */
int		ft_isprint(int c);

/**
 * @brief Computes the length of the string s.
 * 
 * @param s 
 * @return The number of characters that precede the terminating NUL character.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Writes len bytes of value c (converted to an unsigned char) to the 
 * string b.
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return Its first argument.
 */
void	*ft_memset(void *b, int c, size_t len);

/**
 * @brief Writes n zeroed bytes to the string s.  If n is zero, it does nothing.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dst. 
 * If dst and src overlap, behavior is undefined. Applications in which
 * dst and src might overlap should use ft_memmove instead.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return The original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies len bytes from string src to string dst. The two strings 
 * may overlap; the copy is always done in a non-destructive manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return The original value of dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Copies strings. Ii takes the full size of the destination buffer and 
 * guarantee NUL-termination if there is room.  Note that room for the NUL
 * should be included in dstsize.
 * It copies up to dstsize - 1 characters from the string src to dst, 
 * NUL-terminating the result if dstsize is not 0.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return The total length of the string it tries to create. Here, that 
 * that means the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Concatenes strings. It takes the full size of the destination buffer 
 * and guarantee NUL-termination if there is room.  Note that room for the NUL
 * should be included in dstsize.
 * It appends string src to the end of dst.  It will append at most 
 * dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
 * dstsize is 0 or the original dst string was longer than dstsize.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return The total length of the string it tries to create. Here, that 
 * that means the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 * 
 * @param c 
 * @return If the argument is a lower-case letter, the function returns the 
 * corresponding upper-case letter if there is one; otherwise, the argument
 * is returned unchanged.
 */
int		ft_toupper(int c);

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 * 
 * @param c 
 * @return If the argument is an upper-case letter, the function returns the 
 * corresponding lower-case letter if there is one; otherwise, the argument
 * is returned unchanged.
 */
int		ft_tolower(int c);

/**
 * @brief Locates the first occurrence of c (converted to a char) in the string 
 * pointed to by s.  The terminating null character is considered to be part of 
 * the string; therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
 * 
 * @param s
 * @param c 
 * @return A pointer to the located character, or NULL if the character does 
 * not appear in the string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of c (converted to a char) in the string 
 * pointed to by s.  The terminating null character is considered to be part of 
 * the string; therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
 * 
 * @param s 
 * @param c 
 * @return A pointer to the located character, or NULL if the character does 
 * not appear in the string.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Lexicographically compare the null-terminated strings s1 and s2 
 * (for not more than n characters).
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return An integer greater than, equal to, or less than 0, according as the
 * string s1 is greater than, equal to, or less than the string s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of c (converted to an unsigned char)
 * in string s.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return A pointer to the byte located, or NULL if no such byte exists
 * within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares byte string s1 against byte string s2.  Both strings 
 * are assumed to be n bytes long.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return Zero if the two strings are identical, otherwise returns the 
 * differencebetween the first two differing bytes (treated as unsigned
 * char values). Zero-length strings are always identical.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string needle in
 * the string haystack, where not more than len characters are searched.  
 * Characters that appear after a ‘\0’ character are not searched.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return If needle is an empty string, haystack is returned; if needle occurs 
 * nowhere in haystack, NULL is returned; otherwise a pointer to the first
 * character of the first occurrence of needle is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Converts the initial portion of the string pointed to by str to 
 * int representation.
 * 
 * @param str 
 * @return 
 */
int		ft_atoi(const char *str);

/**
 * @brief Contiguously allocates enough space for count objects that are size
 * bytes of memory each and returns a pointer to the allocated memory. The 
 * allocated memory is filled with bytes of value zero.
 * 
 * @param count 
 * @param size 
 * @return If successfull, it returns a pointer to allocated memory. If there is
 * an error, it returns a NULL pointer.
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * @brief Allocates sufficient memory for a copy of the string s1, does the copy,
 * and returns a pointer to it.  The pointer may subsequently be used as
 * an argument to the function free(3).
 * 
 * @param s1 
 * @return If successfull, it returns a pointer to allocated memory. If there is
 * an error, it returns a NULL pointer.
 */
char	*ft_strdup(const char *s1);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return If successfull, it returns a pointer to allocated substring. 
 * If there is an error, it returns a NULL pointer.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is
 * the result of the concatenation of ’s1’ and ’s2’.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return If successfull, it returns a pointer to the new allocated string.
 * If there is an error, it returns a NULL pointer.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of s1 with the characters
 * specified in ’set’ removed from the beginning and the end of the string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return If successfull, it returns a pointer to the trimmed string. If 
 * there is an error, it returns a NULL pointer.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained
 * by splitting ’s’ using the character ’c’ as a delimiter. The array end
 * with a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return If successfull, it returns an array of strings. If there is an 
 * error, it returns a NULL pointer.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the 
 * integer received as an argument.
 * 
 * @param n the integer to convert.
 * @return If successfull, it returns a string representing the integer. If 
 * there is an error, it returns a NULL pointer.
 */
char	*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’, 
 * and passing its index as first argument to create a new string 
 * (with malloc(3)) resulting from successive applications of ’f’.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return If successfull, it returns the string created from the successive
 * applications of ’f’. If there is an error, it returns a NULL pointer.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function ’f’ on each character of the string passed
 * as argument, passing its index as first argument. Each character is 
 * passed by address to ’f’ to be modified if necessary.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor followed
 * by a newline.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * 
 * @param nb The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int nb, int fd);

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member
 * variable ’content’ is initialized with the value of the parameter
 * ’content’. The variable ’next’ is initialized to NULL.
 * 
 * @param content The content to create the node with.
 * @return If successfull, it returns the new node. If there is an
 * error, it returns a NULL pointer.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * 
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * 
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 * 
 * @param lst The beginning of the list.
 * @return Last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * 
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s 
 * content using the function ’del’ given as a parameter and free the node.
 * The memory of ’next’ is freed.
 * 
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free(3). Finally, the pointer to the list is
 * set to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content 
 * of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node.
 * 
 * @param lst  The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node. Creates a new list resulting of the successive applications of
 * delete the content of a node if needed. the function ’f’. The ’del’ function
 * is used to delete the content of a node if needed.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node
 * if needed.
 * @return If successfull, it returns the new list. If there is an
 * error, it returns a NULL pointer.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Returns a line read from a file descriptor.
 * 
 * @param fd The file descriptor to read from.
 * @return The read line or NULL if there is nothing else to read, or an error
occurred.
 */
char	*get_next_line(int fd);

/**
 * @brief Formats and prints its arguments. The supported format specifiers are:
 * %c	a single character
 * %s	a string (as defined by the common C convention)
 * %p	a void * pointer printed in hexadecimal format
 * %d	a decimal (base 10) number
 * %i	an integer in base 10
 * %u	an unsigned decimal (base 10) number
 * %x	a number in hexadecimal lowercase format
 * %X	a number in hexadecimal uppercase format
 * %%	a percent sign
 * 
 * @param str 
 * @param ... 
 * @return The size of the written string.
 */
int		ft_printf(const char *str, ...);
int		ft_print_char(unsigned char c);
int		ft_print_str(char *s);
int		ft_print_int(int nb);
int		ft_print_int_base(long nbr, char *base);
int		ft_print_ptr(unsigned long long nbr);
int		ft_print_uint(unsigned int nb);

#endif