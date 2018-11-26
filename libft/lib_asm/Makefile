# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:26 by bvigne            #+#    #+#              #
#    Updated: 2018/05/26 10:21:49 by bvigne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#### COMMAND ####

AR = ar rc
CC = gcc $(FLAGS)

#### FLAGS ####

FLAGS = -Wall -Wextra
ifneq ($(NOERR),yes)
FLAGS += -Werror
endif

#### SOURCES ####

LIBFT = ft_abs.c					\
		ft_atoi.c 					\
		ft_atobase.c				\
		ft_biggest.c				\
		ft_bzero.c 					\
		ft_charjoinfree.c 			\
		ft_count_white.c			\
		ft_ctostr.c					\
		ft_isalnum.c 				\
		ft_isalpha.c 				\
		ft_isascii.c 				\
		ft_isblank.c 				\
		ft_isdigit.c 				\
		ft_islower.c 				\
		ft_isprint.c 				\
		ft_isupper.c 				\
		ft_itoa.c 					\
		ft_itoa_base.c 				\
		ft_lstadd.c 				\
		ft_lstaddend.c				\
		ft_lstcount.c 				\
		ft_lstdel.c 				\
		ft_lstdelone.c 				\
		ft_lstiter.c 				\
		ft_lstlast.c 				\
		ft_lstmap.c 				\
		ft_lstnew.c 				\
		ft_memalloc.c 				\
		ft_memccpy.c 				\
		ft_memchr.c 				\
		ft_memcmp.c 				\
		ft_memcpy.c 				\
		ft_memdel.c 				\
		ft_memmove.c 				\
		ft_memset.c 				\
		ft_nbrlen.c					\
		ft_nbrlen_base.c			\
		ft_nbr_split_whitespaces.c	\
		ft_power.c 					\
		ft_putchar.c 				\
		ft_putchar_fd.c 			\
		ft_putendl.c 				\
		ft_putendl_fd.c 			\
		ft_putnchar.c				\
		ft_putnbr.c 				\
		ft_putnbr_fd.c 				\
		ft_putnbr_base.c 			\
		ft_putnstr.c				\
		ft_putstr.c 				\
		ft_putunbr.c				\
		ft_put_hex.c				\
		ft_put_uhex.c				\
		ft_put_uhex_maj.c			\
		ft_putstr_fd.c 				\
		ft_smallest.c				\
		ft_split_whitespaces.c		\
		ft_strcapitalize.c 			\
		ft_strcat.c 				\
		ft_strccpy.c				\
		ft_strcdup.c				\
		ft_strcend.c				\
		ft_strchr.c 				\
		ft_strclr.c 				\
		ft_strcmp.c 				\
		ft_strcpy.c 				\
		ft_strdel.c 				\
		ft_strdup.c 				\
		ft_strequ.c 				\
		ft_strend.c					\
		ft_str_is_alpha.c 			\
		ft_str_is_lowercase.c 		\
		ft_str_is_printable.c 		\
		ft_str_is_uppercase.c 		\
		ft_striter.c 				\
		ft_striteri.c 				\
		ft_strjoin.c 				\
		ft_strjoinfree.c			\
		ft_strlcat.c 				\
		ft_strlen.c 				\
		ft_strlowcase.c 			\
		ft_strmap.c 				\
		ft_strmapi.c 				\
		ft_strncat.c 				\
		ft_strncmp.c 				\
		ft_strncpy.c 				\
		ft_strnchar.c				\
		ft_strndup.c				\
		ft_strwdup.c				\
		ft_strnequ.c 				\
		ft_strnew.c 				\
		ft_strnsep.c				\
		ft_strnstr.c 				\
		ft_strrchr.c 				\
		ft_strrev.c 				\
		ft_strsplit.c 				\
		ft_strstr.c 				\
		ft_strsub.c 				\
		ft_strsubdel.c 				\
		ft_strtrim.c 				\
		ft_strupcase.c 				\
		ft_strwth.c					\
		ft_swap.c 					\
		ft_tabcpy.c					\
		ft_tabadd.c					\
		ft_tabdel.c					\
		ft_tablen.c 				\
		ft_tolower.c 				\
		ft_toupper.c				\
		get_next_line.c

PRINTF = ft_printf.c 				\
		 get_len.c					\
		 parsing.c					\
		 get_flags.c				\
		 get_conv.c					\
		 get_unicode.c				\
		 conv_c.c					\
		 conv_id.c					\
		 conv_maj_c.c				\
		 conv_maj_s.c				\
		 conv_maj_d.c				\
		 conv_maj_o.c				\
		 conv_maj_u.c				\
		 conv_maj_x.c				\
		 conv_o.c					\
		 conv_p.c					\
		 conv_s.c					\
		 conv_u.c					\
		 conv_x.c					\
		 lib_put.c 					\
		 lib_nbr.c					\
		 lib_str.c					\
		 lib_str_2.c				\
		 lib_join.c					\
		 lib_conv.c

#### PATH ####

INC_PATH = ./includes/
SRCS_PATH = sources
OBJ_PATH  = objects
LIB_PATH  = libft
PRINTF_PATH = ft_printf
HEAD = $(INC_PATH)/libft.h			\
	   $(INC_PATH)/ft_printf.h

INC += -I $(INC_PATH)
INC += -I $(LIB_PATH)

#### MERGING OBJECTS ####

SRCS_LIB    += $(addprefix $(LIB_PATH)/, $(LIBFT))
SRCS_PRINTF += $(addprefix $(PRINTF_PATH)/, $(PRINTF))

SRCS += $(addprefix $(SRCS_PATH)/, $(SRCS_LIB))
SRCS += $(addprefix $(SRCS_PATH)/, $(SRCS_PRINTF))

OBJP += $(addprefix ./$(OBJ_PATH)/, $(LIB_PATH))
OBJP += $(addprefix ./$(OBJ_PATH)/, $(PRINTF_PATH))

OBJ += $(addprefix ./$(OBJ_PATH)/, $(SRCS_LIB:.c=.o))
OBJ += $(addprefix ./$(OBJ_PATH)/, $(SRCS_PRINTF:.c=.o))

#### RULES ####

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJP)
	@echo "$(BOLD)creating libft object...$(END)\n"

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(HEAD)
	@$(CC) $(INC) -o $@ -c $<
	@echo "$(YELLOW)Compilation:$(END)   $(GREEN)[OK]$(END)  " $<

$(NAME): $(OBJ)
	@$(AR) $(NAME) $^
	@ranlib $(NAME)
	@echo "\n$(UNDER)libft$(END) $(GREEN)compiled with success$(END)\n"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)
	@echo "\n$(UNDER)libft$(END) $(RED)cleaned with success$(END)\n"

re: fclean all

.PHONY: all clean fclean re

###############################################################################

# This is a minimal set of ANSI/VT100 color codes
END=\x1b[0m
BOLD=\x1b[1m
UNDER=\x1b[4m
REV=\x1b[7m

# Colors
GREY=\x1b[30m
RED=\x1b[31m
GREEN=\x1b[32m
YELLOW=\x1b[33m
BLUE=\x1b[34m
PURPLE=\x1b[35m
CYAN=\x1b[36m
WHITE=\x1b[37m

# Inverted, i.e. colored backgrounds
IGREY=\x1b[40m
IRED=\x1b[41m
IGREEN=\x1b[42m
IYELLOW=\x1b[43m
IBLUE=\x1b[44m
IPURPLE=\x1b[45m
ICYAN=\x1b[46m
IWHITE=\x1b[47m

###############################################################################