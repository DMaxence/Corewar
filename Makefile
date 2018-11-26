# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 17:02:58 by maduhoux          #+#    #+#              #
#    Updated: 2018/11/13 17:12:23 by anaroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## NAMES ##

ASM = asm
VM = corewar


## FLAGS ##

FLAGS = -Wall -Wextra
ifneq ($(NOERR),yes)
FLAGS += -Werror
endif

CC = gcc $(FLAGS)


## SOURCES ##

ASM_PATH = sources/asm

ASM_SRC =	prog.c								\
				conv.c							\
					header.c					\
					pro.c						\
						realloc.c				\
						label.c					\
						opc.c					\
					check_pro.c					\
						arg.c					\
					translate.c					\
						byte.c					\
						jump.c					\
					head_step.c					\
					byte_step.c					\
				cor.c							\
				free.c							\
			error.c								\
			op.c								

VM_PATH = sources/vm

VM_EXEC_PATH = sources/vm/exec
VM_EXEC_SRC =		main.c						\
					free.c						\
					ft_execution.c				\
					ft_execution2.c				\
					ft_cycle_to_die.c			\
					ft_wait_instruction.c		\
					ft_execute_instruction.c	\
					ft_write_v.c				\

VM_READ_PATH = sources/vm/read
VM_READ_SRC =		init.c						\
					check_flag.c				\
					ft_read_champs.c			\
					ft_new_player.c				\
					ft_process.c				\
					ft_arrange_player.c			\
					ft_arrange_player_tools.c	\

VM_OPCODE_PATH = sources/vm/opcode
VM_OPCODE_SRC =		live.c						\
					ld.c						\
					st.c						\
					add.c						\
					sub.c						\
					and.c						\
					or.c						\
					xor.c						\
					zjmp.c						\
					ldi.c						\
					sti.c						\
					fork.c						\
					lld.c						\
					lldi.c						\
					lfork.c						\
					aff.c						\
					write_param.c				\
					read_param.c				\
					tools.c						\


## BONUS ##

BONUS_PATH	= bonus/visu

BONUS_SRC	=		ft_print_memory.c			\
					ft_init_map.c				\
					ft_print_sidebar.c			\
					ft_print_process.c			\
					ft_intercept_keypress.c		\
					ft_key_actions.c			\


## LIB ##

LIB_ASM = libft/lib_asm
LIB_VM = libft/lib_vm

OPTION = -c -include corewar.h

INC_PATH = ./includes
INC = -I $(INC_PATH)
HEAD_COR = $(INC_PATH)/corewar.h
HEAD_ASM = $(INC_PATH)/asm.h
HEAD_VISU = $(INC_PATH)/visu.h
HEAD_OP = $(INC_PATH)/op.h

NCURSE = -lncurses

## OBJECTS ##

OBJ_ASM_PATH = objects/asm_obj
OBJ_ASM = $(ASM_SRC:.c=.o)
OBJP_ASM = $(addprefix $(OBJ_ASM_PATH)/, $(OBJ_ASM))


OBJ_VM_EXEC_PATH = objects/vm_obj/exec
OBJ_VM_EXEC = $(VM_EXEC_SRC:.c=.o)
OBJP_VM_EXEC = $(addprefix $(OBJ_VM_EXEC_PATH)/, $(OBJ_VM_EXEC))

OBJ_VM_READ_PATH = objects/vm_obj/read
OBJ_VM_READ = $(VM_READ_SRC:.c=.o)
OBJP_VM_READ = $(addprefix $(OBJ_VM_READ_PATH)/, $(OBJ_VM_READ))

OBJ_VM_OPCODE_PATH = objects/vm_obj/opcode
OBJ_VM_OPCODE = $(VM_OPCODE_SRC:.c=.o)
OBJP_VM_OPCODE = $(addprefix $(OBJ_VM_OPCODE_PATH)/, $(OBJ_VM_OPCODE))


OBJ_BONUS_PATH = objects/visu_obj
OBJ_BONUS = $(BONUS_SRC:.c=.o)
OBJP_BONUS = $(addprefix $(OBJ_BONUS_PATH)/, $(OBJ_BONUS))

## RULES ##

all: makelibs $(OBJ_ASM_PATH) $(ASM) $(OBJ_VM_EXEC_PATH) $(OBJ_VM_READ_PATH) $(OBJ_VM_OPCODE_PATH) $(OBJ_BONUS_PATH) $(VM)

makelibs:
	@make -C $(LIB_ASM)
	@make -C $(LIB_VM)

$(OBJ_ASM_PATH):
	@mkdir -p objects
	@mkdir -p objects/asm_obj
	@echo "$(BOLD)creating asm objects...$(END)\n"
$(OBJ_ASM_PATH)/%.o: $(ASM_PATH)/%.c $(HEAD_ASM) $(HEAD_OP)
	@$(CC) $(INC) -o $@ -c $<
	@echo "$(CYAN)Compilation:$(END)   $(GREEN)[OK]$(END)  " $<

$(ASM): $(OBJP_ASM)
	@$(CC) -o $(ASM) $(OBJP_ASM) -L./libft/lib_asm -lft
	@echo "\n$(UNDER)$(ASM)$(END) $(GREEN)compiled with success$(END)\n"

$(OBJ_VM_EXEC_PATH):
	@mkdir -p objects/vm_obj
	@mkdir -p objects/vm_obj/exec
	@echo "$(BOLD)creating corewar objects...$(END)\n"
$(OBJ_VM_EXEC_PATH)/%.o: $(VM_EXEC_PATH)/%.c $(HEAD_COR) $(HEAD_OP)
	@$(CC) $(INC) -o $@ -c $<
	@echo "$(BLUE)Compilation:$(END)   $(GREEN)[OK]$(END)  " $<

$(OBJ_VM_READ_PATH):
	@mkdir -p objects/vm_obj/read
$(OBJ_VM_READ_PATH)/%.o: $(VM_READ_PATH)/%.c $(HEAD_COR) $(HEAD_OP)
	@$(CC) $(INC) -o $@ -c $<
	@echo "$(BLUE)Compilation:$(END)   $(GREEN)[OK]$(END)  " $<

$(OBJ_VM_OPCODE_PATH):
	@mkdir -p objects/vm_obj/opcode
$(OBJ_VM_OPCODE_PATH)/%.o: $(VM_OPCODE_PATH)/%.c $(HEAD_COR) $(HEAD_OP)
	@$(CC) $(INC) -o $@ -c $<
	@echo "$(BLUE)Compilation:$(END)   $(GREEN)[OK]$(END)  " $<

$(OBJ_BONUS_PATH):
	@mkdir -p objects/visu_obj
	@echo "$(BOLD)creating visu objects...$(END)\n"
$(OBJ_BONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(HEAD_VISU) $(HEAD_OP)
	@$(CC) $(INC) -o $@ -c $<
	@echo "$(PURPLE)Compilation:$(END)   $(GREEN)[OK]$(END)  " $<

$(VM): $(OBJP_VM_EXEC) $(OBJP_VM_READ) $(OBJP_VM_OPCODE) $(OBJP_BONUS)
	@$(CC) -o $(VM) $(NCURSE) $(OBJP_VM_EXEC) $(OBJP_VM_READ) $(OBJP_VM_OPCODE) $(OBJP_BONUS) -L./libft/lib_vm -lft
	@echo "\n$(UNDER)$(VM)$(END) $(GREEN)compiled with success$(END)\n"

clean:
	@make clean -C $(LIB_ASM) MAKEFLAGS=s
	@make clean -C $(LIB_VM) MAKEFLAGS=s
	@rm -rf objects

fclean: clean
	@make fclean -C $(LIB_ASM) MAKEFLAGS=s
	@make fclean -C $(LIB_VM) MAKEFLAGS=s
	@rm -rf $(ASM) $(VM)
	@echo "$(UNDER)$(ASM)$(END) $(RED)and$(END) $(UNDER)$(VM)$(END)$(RED) cleaned with success$(END)\n"

re: fclean all

.PHONY: all makelibs clean fclean re

###############################################################################

# colors
GREY=\x1b[30m
RED=\x1b[31m
GREEN=\x1b[32m
YELLOW=\x1b[33m
BLUE=\x1b[34m
PURPLE=\x1b[35m
CYAN=\x1b[36m
WHITE=\x1b[37m

# colored backgrounds
IGREY=\x1b[40m
IRED=\x1b[41m
IGREEN=\x1b[42m
IYELLOW=\x1b[43m
IBLUE=\x1b[44m
IPURPLE=\x1b[45m
ICYAN=\x1b[46m
IWHITE=\x1b[47m

# text type
END=\x1b[0m
BOLD=\x1b[1m
UNDER=\x1b[4m
REV=\x1b[7m

###############################################################################