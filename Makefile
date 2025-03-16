YELLOW = [33m
GREEN  = [32m
BLUE   = [34m
RESET  = [0m

NAME = gnl_tester.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

DEBUG ?= 0
HIDE := $(if $(filter 0,$(DEBUG)),@,)

%.o: %.c
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(HIDE)ar rcs $(NAME) $(OBJS)

clean:
	$(HIDE)rm -f $(OBJS)

fclean: clean
	$(HIDE)rm -f $(NAME) my_program

test: re
	$(HIDE)printf "%s" "$(YELLOW)Start compiling: $(RESET)["
	$(HIDE)$(CC) main.c $(NAME) -o my_program
	$(HIDE)printf "%s\n" "$(GREEN)OK$(RESET)]"
	$(HIDE)./my_program test_file1.txt test_file2.txt test_file3.txt
	$(HIDE)printf "%s" "$(BLUE)Cleaning files: $(RESET)"
	$(HIDE)make fclean
	$(HIDE)printf "%s" "$(GREEN)Done: $(RESET)"

re: fclean all