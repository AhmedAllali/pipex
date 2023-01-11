/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:25:05 by ahallali          #+#    #+#             */
/*   Updated: 2023/01/05 09:35:57 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<stdio.h>
# include<sys/types.h>
# include<errno.h>
# include<fcntl.h>
# include<string.h>
# include<stdlib.h>
# include "libft/libft.h"

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_free1(char *str, char *str1);
char	*checkcmd(char **ar, char *str);
char	*findpath(char **envp);
char	**ft_free2(char **ptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char	*str2, size_t lenght);

typedef struct def
{
	int		infile;
	int		outfile;
	char	*pat;
	char	**ar;
	char	**cmd;
	char	*a;
	char	*a2;
	char	**cmd2;
	int		fd[2];
	int		pid;
	int		pid2;
}	t_dec;
#endif