/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:31:16 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/01/14 19:26:47 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0

int		open_file(char *argv, int i);
void	execute(char *argv, char **envp);
void	arg_error(int err);
void	error(void);
char	*find_path(char *cmd, char **envp);

#endif