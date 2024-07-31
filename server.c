/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:44:45 by cgouveia          #+#    #+#             */
/*   Updated: 2024/07/29 14:44:48 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	indenficador_sinal(int sinal)
{
	static int	cont_bit;
	static char	caract;

	if (sinal == SIGUSR2)
		caract |= (1 << cont_bit);
	cont_bit++;
	if (cont_bit == 8)
	{
		ft_printf("%c", caract);
		cont_bit = 0;
		caract = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Este é o pid do servidor -> %d \n", getpid());
	sa.sa_handler = &indenficador_sinal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
