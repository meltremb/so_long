# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:14:16 by meltremb          #+#    #+#              #
#    Updated: 2023/02/07 13:58:15 by meltremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

# Libraries
LIBMLX	=	MLX42/libmlx42.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"

# Dir and file names
NAME	=	so_long
SRCDIR	=	src/
OBJDIR	=	bin/
SRCS	=	src/so_long.c\
				src/data_utils.c\
				src/extra_functions.c\
				src/make_map.c\
				src/map_checker.c\
				src/map_reader.c\
				src/player_mover.c\
				src/get_next_line_bonus.c\
				src/get_next_line_utils_bonus.c\
				src/print_moves.c\
			
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(MLXDIR)/$(MLX42) $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $^ $(LIBMLX)
# @echo"$(GREEN)Files compiled$(DEF_COLOR)"

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
