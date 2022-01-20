/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:31:16 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/01/20 14:40:28 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0

typedef struct pipex
{
	int		ac;
	char	**av;
	char	**envp;
	int		p[2];
	int		infile;
	int		outfile;
	int		cmd_cnt;
}				t_ppx;

int		open_file(char *argv, int i);
void	exec(char *argv, char **envp);
void	arg_error(int err);
void	init_pipex(t_ppx pipex, int ac, char **av, char **envp);
void	error(void);
char	*path(char *cmd, char **envp);

#endif