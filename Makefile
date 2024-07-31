# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 16:43:24 by cgouveia          #+#    #+#              #
#    Updated: 2024/07/29 16:43:31 by cgouveia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile principal
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lft_printf -lftprintf
LIBFT_DIR = ft_printf
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a
OBJ = server.c
OBJ1 = client.c
TARGET = server
TARGET1 = client

# Regra padrão
all: $(TARGET) $(TARGET1)

# Regra para criar o executável
$(TARGET): $(OBJ) $(LIBFT_LIB)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

# Regra para criar o executável
$(TARGET1): $(OBJ1) $(LIBFT_LIB)
	$(CC) $(OBJ1) $(LDFLAGS) -o $(TARGET1)

# Compila os arquivos .c do projeto em arquivos .o
./%.o: ./%.c
	$(CC) $(CFLAGS) -I -c $< -o $@
# Regra para invocar o Makefile da ft_printf
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Limpa arquivos objeto e o executável
clean:
	rm -f *.o
	$(MAKE) clean -C $(LIBFT_DIR)

# Limpa arquivos adicionais
fclean: clean
	rm -f $(TARGET) $(TARGET1)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Recompila tudo
re: fclean all

