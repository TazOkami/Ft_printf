# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 15:08:41 by Jpaulis           #+#    #+#              #
#    Updated: 2024/11/02 08:25:35 by Jpaulis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la bibliothèque
NAME = libftprintf.a

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Commandes pour l'archive et la suppression
AR = ar
ARFLAGS = rcs
RM = rm -f

# Fichiers source et objets
SRCS = ft_handle_char.c ft_handle_decimal.c ft_handle_hex.c ft_handle_pointer.c ft_handle_string.c ft_handle_unsigned.c ft_printf.c ft_utils.c
OBJS = $(SRCS:.c=.o)

# Règle par défaut pour tout compiler
all: $(NAME)

# Création de la bibliothèque statique
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Règle pour compiler les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	$(RM) $(OBJS)

# Règle pour nettoyer complètement (fichiers objets et bibliothèque)
fclean: clean
	$(RM) $(NAME)

# Règle pour tout recompiler
re: fclean all

.PHONY: all clean fclean re
