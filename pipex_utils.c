/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:08:15 by ahallali          #+#    #+#             */
/*   Updated: 2023/01/05 11:04:16 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_free2(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	return (NULL);
}

char	*findpath(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp (*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*checkcmd(char **ar, char *str)
{
	char	*cmdpath;
	char	*tmp;

	if (str == NULL || *str == '\0')
	{
		perror("type the correct arguments");
		return (NULL);
	}
	while (*ar)
	{	
		tmp = ft_strjoin(*ar, "/");
		cmdpath = ft_strjoin(tmp, str);
		if (access(cmdpath, F_OK) == 0)
		{
			free(tmp);
			return (cmdpath);
		}
		ar++;
		ft_free1(tmp, cmdpath);
	}
	if (access(cmdpath, F_OK) < 0)
		return (ft_putstr_fd("cmd not found\n", 2), NULL);
	return (NULL);
}

void	ft_free1(char *str, char *str1)
{
	free(str);
	free(str1);
}
