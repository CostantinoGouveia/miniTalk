/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:45:01 by cgouveia          #+#    #+#             */
/*   Updated: 2024/07/29 14:45:04 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	is_negative;

	nb = 0;
	is_negative = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			is_negative = -1;
	while (*str >= '0' && *str <= '9')
	{
		if ((nb > INT_MAX / 10)
			|| (nb == INT_MAX / 10 && (*str - '0' > INT_MAX % 10)))
		{
			if (is_negative == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		nb = nb * 10 + (*str++ - '0');
	}
	return (nb * is_negative);
}

void	env_caract(int servidor_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(servidor_pid, SIGUSR2);
		else
			kill(servidor_pid, SIGUSR1);
		usleep(400);
		i++;
	}
}

void	env_mensagem(int servidor_pid, const char *mensagem)
{
	size_t	i;

	i = 0;
	while (mensagem[i])
	{
		env_caract(servidor_pid, mensagem[i]);
		i++;
	}
	env_caract(servidor_pid, '\n');
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Deve ser nesta ordem: <PID do servidor> <mensagem>\n");
		exit(1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_printf("O pid só pode conter caracter de 0 a 9.\n");
			exit(1);
		}
		i++;
	}
	env_mensagem(ft_atoi(argv[1]), argv[2]);
	return (0);
}
