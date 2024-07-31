/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:11:58 by cgouveia          #+#    #+#             */
/*   Updated: 2024/07/30 17:12:03 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <string.h>

void	indenficador_sinal(int sinal);
void	env_caract(pid_t servidor_pid, char c);
void	env_mensagem(pid_t servidor_pid, const char *mensagem);
int		ft_atoi(const char *str);

#endif
