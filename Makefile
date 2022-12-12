GREEN=\033[38;5;046m
YELLOW =\033[38;5;220m
END=\033[0m
NEWSECTION = "$(GREEN)--------------------------------------------------$(END)"

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER= push_swap.h

LIBFTPRINTF=libftprintf/libftprintf.a

src  = 		cost.c\
			do_move.c\
			initialisation.c\
			input_correct_check.c\
			main.c\
			position.c\
			push.c\
			reverse_rotate.c\
			rotate.c\
			sort_tiny.c\
			sort.c\
			swap.c\
			utils.c\

SRCS = $(addprefix ./SRCS/, $(src))
OBJS = $(SRCS:c=o)

$(LIBFTPRINTF):
	@echo "$(YELLOW)Building libftprintf library...$(END)"
	$(MAKE) -C ./libftprintf
	@echo "$(GREEN)Libftprintf library built successfully!$(END)"
	@echo $(NEWSECTION)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	@echo "$(YELLOW)Compiling push_swap program...$(END)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME)
	@echo "$(GREEN)push_swap program compiled!$(END)"
	@echo $(NEWSECTION)

######### RULES ########
all: $(NAME)

clean:
	@echo "$(YELLOW)Removing object files...$(END)"
	@rm -rf ./SRCS/*.o
	$(MAKE) clean -C ./libftprintf
	@echo "$(GREEN)Object files deleted!$(END)"
	@echo $(NEWSECTION)

fclean: clean
	@echo "$(YELLOW)Removing object files and program...$(END)"
	$(MAKE) fclean -C ./libftprintf
	@rm -rf $(NAME)
	@echo "$(GREEN)fclean completed!$(END)"
	@echo $(NEWSECTION)
	
re: fclean all