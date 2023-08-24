/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:08:14 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/03 09:32:56 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
	{
		perror("Pipe");
		exit(-1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("Fork");
		exit(-1);
	}
	else if (pid1 == 0)
		child_pcs(fd, argv[0], argv[1], envp);
	else
		parent_pcs(fd, argv[3], argv[2], envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		perror("Input invalid");
		exit(1);
	}
	pipex(argv + 1, envp);
	return (0);
}
