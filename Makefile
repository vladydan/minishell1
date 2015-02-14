##
## Makefile for makefile in /home/danilo_d/rendu/PSU_2014_my_printf
## 
## Made by Dimitri Danilov
## Login   <danilo_d@epitech.net>
## 
## Started on  Sat Nov 15 13:07:25 2014 Dimitri Danilov
## Last update Sun Feb  1 19:17:11 2015 Danilov Dimitri
##

NAME	= mysh

SRCS	= sources/main.c \
	  sources/my_strdup.c \
	  sources/my_strcat.c \
	  sources/my_strncmp.c \
	  sources/my_strndup.c \
	  sources/command.c \
	  sources/env.c \
	  sources/directory.c \
	  sources/my_strdup_mod.c \
	  sources/add_to_list.c \
	  sources/my_realloc.c \
	  sources/my_aff_list.c \
	  sources/init_list.c \
	  sources/prompt.c \
	  sources/recup_argv.c \
	  sources/mysh.c \
	  sources/my_putchar.c \
	  sources/xmalloc.c \
	  sources/my_strcmp.c \
	  sources/my_putstr.c \
	  sources/my_strlen.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Iinclude/ -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
