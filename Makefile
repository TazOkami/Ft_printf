# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 15:08:41 by Jpaulis           #+#    #+#              #
#    Updated: 2024/10/28 22:21:18 by Jpaulis          ###   ########.fr        #
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
RM = rm -rf

# Répertoires des sources et des objets
SRC_DIR = srcs
OBJ_DIR = obj

# Définition des fichiers source et objets
SRCS = $(addprefix $(SRC_DIR)/, ft_printf.c ft_handle_char.c ft_handle_string.c ft_handle_decimal.c ft_handle_unsigned.c ft_handle_hex.c ft_handle_pointer.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Chemin vers la bibliothèque libft
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Règle pour compiler les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

# Règle par défaut pour tout compiler
all: $(OBJ_DIR) $(NAME)

# Création de la bibliothèque statique
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Règle pour compiler la bibliothèque libft
$(LIBFT):
	make -C $(LIBFT_PATH) all

# Création du répertoire des objets s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Règle pour nettoyer les fichiers objets et la bibliothèque
clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

# Règle pour nettoyer complètement (fichiers objets, bibliothèque et libftprintf.a)
fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

# Règle pour tout recompiler
re: fclean all

.PHONY: all clean fclean re libft
