# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakoh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 17:17:36 by hakoh             #+#    #+#              #
#    Updated: 2021/09/15 17:17:38 by hakoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ---------------------------------------------------------------------------- #
############################### PROGRAM NAME ###################################
# ---------------------------------------------------------------------------- #
NAME		=	push_swap

# ---------------------------------------------------------------------------- #
############################### COMPILATION ####################################
# ---------------------------------------------------------------------------- #
CC 			=	clang

# ---------------------------------------------------------------------------- #
################################## FLAGS #######################################
# ---------------------------------------------------------------------------- #
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

# ---------------------------------------------------------------------------- #
################################# INCLUDES #####################################
# ---------------------------------------------------------------------------- #
INCLUDES	=	-I $(PATH_INC)				\
				-I $(PATH_LIBFT)inc/

# ---------------------------------------------------------------------------- #
################################# SOURCES ######################################
# ---------------------------------------------------------------------------- #
SRCS		=	$(addprefix $(PATH_SRCS),	\
				$(addsuffix .c,				\
				main						\
				error						\
				parse						\
				operations1					\
				operations2					\
				operations3					\
				operations4					\
				algo						\
				algo2))

# ---------------------------------------------------------------------------- #
################################## OBJECTS #####################################
# ---------------------------------------------------------------------------- #
OBJS		=	$(SRCS:.c=.o)

# ---------------------------------------------------------------------------- #
################################### PATHS ######################################
# ---------------------------------------------------------------------------- #
PATH_INC	=	./inc/
PATH_SRCS	=	./src/
PATH_LIBFT	=	./libft/

# ---------------------------------------------------------------------------- #
################################# LIBRARIES ####################################
# ---------------------------------------------------------------------------- #
LDFLAGS		=	-L$(PATH_LIBFT)
LDLIBS		=	-lft

# ---------------------------------------------------------------------------- #
################################### RULES ######################################
# ---------------------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(PATH_LIBFT)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

%.o: %.c Makefile $(PATH_INC)push_swap.h
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

clean:
	$(MAKE) -C $(PATH_LIBFT) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIBFT) fclean
	rm -rf $(NAME)

re:	fclean all

# ---------------------------------------------------------------------------- #
################################## OTHER #######################################
# ---------------------------------------------------------------------------- #
.PHONY		: all clean fclean re