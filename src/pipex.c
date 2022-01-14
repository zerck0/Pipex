/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:31:05 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/01/10 16:45:54 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, char **envp, int *p)
{
	int		fileout;

	fileout = open_file(argv[4], 1);
	dup2(p[READ_END], STDIN_FILENO);
	close(p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(p[WRITE_END]);
	execute(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *p)
{
	int		filein;

	filein = open_file(argv[1], 2);
	dup2(p[WRITE_END], STDOUT_FILENO);
	close(p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(p[READ_END]);
	execute(argv[2], envp);
}


int	main(int argc, char **argv, char **envp)
{
	int	p[2];
	int	pid1;

	if (argc == 5)
	{
		if (pipe(p) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, p);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, p);
	}
	else
		arg_error(0);
	return (0);
}