/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:31:05 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/01/20 13:01:10 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, char **envp, t_ppx *pip)
{
	int		fileout;

	fileout = open_file(argv[4], 1);
	dup2(pip->p[READ_END], STDIN_FILENO);
	close(pip->p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(pip->p[WRITE_END]);
	exec(argv[3], envp);
}

void	child_process(char **argv, char **envp, t_ppx *pip)
{
	int		filein;

	filein = open_file(argv[1], 2);
	dup2(pip->p[WRITE_END], STDOUT_FILENO);
	close(pip->p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(pip->p[READ_END]);
	exec(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid1;
	t_ppx	pip;

	if (argc == 5)
	{
		init_pipex(pip, argc, argv, envp);
		if (pipe(pip.p) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, &pip);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, &pip);
	}
	else
		arg_error(0);
	return (0);
}
