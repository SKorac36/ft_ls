# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorac <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 11:13:00 by skorac            #+#    #+#              #
#    Updated: 2018/09/18 09:30:55 by skorac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CCLIB = -Llibft -lft
CCFLAGS = -Wall -Werror -Wextra
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft/includes

SRC =	  ft_handleall.c \
		  ft_addfile.c \
		  ft_getinfo.c \
		  ft_error.c \
		  ft_sort.c \
		  ft_doit.c \
		  ft_cmp.c \
		 ft_ls.c \
	   	ft_elem.c \
		ft_size.c \
		ft_link.c \
		ft_free.c	
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) $(OBJS)
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
re: fclean all

dev : all
	@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
