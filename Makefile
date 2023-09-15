
#program ------------------------------------------
NAME = minishell

#source directories
SRCS =	./srcs/minishell.c \
		./srcs/parsing/parsing.c \
		./srcs/parsing/signals.c \
		./srcs/exec/exec.c \

#colours ------------------------------------------
B_BLUE='\033[1;34m'
RED=\033[0;31m
YELLOW=\033[33m
MAGENTA=\033[35m
B_GREEN=\033[1;32m
PURPLE=\033[1;35m
COLOUR_END=\033[0m

#object directories and compilation instructions ----------
OBJS = $(SRCS:.c=.o)
.SILENT: $(OBJS)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -fr
LIBS = ./includes/Libft/libft.a ./includes/dlist/dlist.a ./includes/readline/libreadline.a ./includes/readline/libhistory.a -lreadline -lcurses

$(NAME): $(OBJS)
	@$(MAKE) -C ./includes/Libft
	@$(MAKE) lib -C ./includes/dlist
	@cd ./includes/readline && ./configure
	@$(MAKE) everything -C ./includes/readline
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "$(YELLOW)⚡️$(NAME) ⚡️$(B_GREEN)has been created $(COLOUR_END)!"
	
#rules ------------------------------------------
all: $(NAME)

clean:
	@$(MAKE) clean -C ./includes/Libft
	@$(RM) $(OBJS)
	@$(RM) $(ODIR)
	@echo "🧹"

fclean: clean
	@$(MAKE) fclean -C ./includes/Libft
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) has been deleted 🗑️$(COLOUR_END)"

rclean:
	@$(MAKE) clean -C ./includes/readline

re: fclean all

.PHONY: all clean fclean rclean re