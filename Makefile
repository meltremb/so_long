# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:14:16 by meltremb          #+#    #+#              #
#    Updated: 2023/02/22 15:40:09 by meltremb         ###   ########.fr        #
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
LIBMLX	=	MLX42/build/libmlx42.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
LDIR	=	reworked-libft/
LIBFT	=	libft.a

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
				src/print_moves.c\
				src/free.c\
			
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: submodule cmake $(LDIR)/$(LIBFT) $(NAME)


# Generates output file
$(NAME): $(OBJS) $(LDIR)/$(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $^ $(LIBMLX) $(LDIR)/$(LIBFT)

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Generates libft
$(LDIR)/$(LIBFT):
			$(HIDE)$(MAKE) -C $(LDIR)

update:
	git submodule update --init
	
submodule: update
	cd MLX42; cmake -B build && cmake --build build -j4
	
brew:
	brew --version || curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh

glfw: brew
	brew install glfw

cmake : glfw
	cmake --version | brew install cmake
	
# Removes objects
clean: 
	$(HIDE)$(RM) $(OBJDIR)/$(OBJS)
	$(HIDE)$(MAKE) -C $(LDIR) $(MAKE) clean

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(MAKE) -C $(LDIR) $(MAKE) fclean

# Removes objects and executables and remakes
re: fclean all
