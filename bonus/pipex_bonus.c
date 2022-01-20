/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:01:14 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/01/20 15:53:19 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_ppx	pip;
	int		filein;
	int		fileout;

	if (argc >= 5)
	{
		init_pipex(pip, argc, argv, envp);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (pip.cmd_cnt != 0)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
		pip.cmd_cnt--;
	}
	arg_error(1);
}
