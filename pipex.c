/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:09:48 by ahallali          #+#    #+#             */
/*   Updated: 2023/01/05 11:42:21 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msgerror(void)
{
	perror("");
	exit(1);
}

void	child(char **envp, t_dec declaration)
{
	declaration.pid = fork ();
	if (declaration.pid == 0)
	{
		close (declaration.fd[0]);
		dup2(declaration.infile, STDIN_FILENO);
		dup2(declaration.fd[1], STDOUT_FILENO);
		if (declaration.a == NULL)
			exit(1);
		else
			execve(declaration.a, declaration.cmd, envp);
		return ;
	}
	declaration.pid2 = fork();
	if (declaration.pid2 == 0)
	{
		close(declaration.fd[1]);
		dup2(declaration.fd[0], STDIN_FILENO);
		dup2(declaration.outfile, STDOUT_FILENO);
		if (declaration.a2 == NULL)
			exit (1);
		else
			execve(declaration.a2, declaration.cmd2, envp);
	}
}

void	normehack(char **envp, t_dec declaration)
{
	if (pipe(declaration.fd) == 0)
	{
		child(envp, declaration);
		close(declaration.fd[0]);
		close(declaration.fd[1]);
		waitpid(declaration.pid2, NULL, 0);
		waitpid(declaration.pid, NULL, 0);
		ft_free2(declaration.cmd);
		ft_free2(declaration.cmd2);
		ft_free2(declaration.ar);
		free(declaration.a);
		free(declaration.a2);
	}
}

int	main(int argc, char *argv[], char**envp)
{
	t_dec	declaration;

	if (argc != 5)
	{
		write (1, "retype arguments\n", ft_strlen("retype arguments\n"));
		exit (1);
	}
	declaration.infile = open (argv[1], O_RDONLY, 0444);
	declaration.outfile = open (argv[argc - 1], \
	O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (declaration.infile < 0)
		msgerror();
	if (declaration.outfile < 0)
		msgerror();
	declaration.pat = findpath (envp);
	declaration.ar = ft_split(declaration.pat, ':');
	declaration.cmd = ft_split(argv[2], ' ');
	declaration.cmd2 = ft_split(argv[3], ' ');
	declaration.a = checkcmd(declaration.ar, declaration.cmd[0]);
	declaration.a2 = checkcmd(declaration.ar, declaration.cmd2[0]);
	normehack(envp, declaration);
}
