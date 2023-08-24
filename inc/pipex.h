/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:35:13 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/02 16:04:53 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sysexits.h>
# include <stdio.h>
# include <fcntl.h>

# include "ft_printf.h"
# include "libft.h"

void	child_pcs(int fd[], char *infile, char *cmd, char *envp[]);
void	parent_pcs(int fd[], char *outfile, char *cmd, char *envp[]);

#endif
