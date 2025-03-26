YELLOW = [33m
GREEN  = [32m
BLUE   = [34m
RESET  = [0m
RED    = [31m
BOLD   = [1m

NAME = gnl_tester.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

DEBUG ?= 0
HIDE := $(if $(filter 0,$(DEBUG)),@,)

# default value for BUFFER_SIZE
BUFFER_SIZE ?= 100

# Request user input for BUFFER_SIZE
set-buffer-size:
	@echo "$(YELLOW)Enter $(BOLD)BUFFER_SIZE$(RESET)$(YELLOW) (default 100):$(RESET)"
	@read size; \
	if [ ! -z $$size ]; then \
		echo "Setting BUFFER_SIZE to $$size"; \
		echo $$size > buffer_size.txt; \
	else \
		echo "Using default BUFFER_SIZE = 100"; \
		echo 100 > buffer_size.txt; \
	fi
	@echo "BUFFER_SIZE set to $$size"

%.o: %.c
	$(HIDE)$(CC) -D BUFFER_SIZE=$(shell cat buffer_size.txt) $(CFLAGS) -c $< -o $@

all: set-buffer-size $(NAME)

$(NAME): $(OBJS)
	$(HIDE)ar rcs $(NAME) $(OBJS)

clean:
	$(HIDE)rm -f $(OBJS) buffer_size.txt

fclean: clean
	$(HIDE)rm -f $(NAME)

VALGRIND_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
FSANITIZE_CMD = -fsanitize=address
PROGRAM = my_program
TEST_FILES = test_file1.txt test_file2.txt test_file3.txt

test: all
	$(HIDE)printf "%s" "$(YELLOW)Start compiling: $(RESET)[" 
	$(HIDE)$(CC) $(CFLAGS) main.c gnl_tester.a -o my_program
	$(HIDE)printf "%s\n" "$(GREEN)OK$(RESET)]"
	$(HIDE)./$(PROGRAM) $(TEST_FILES)
	$(HIDE)printf "%s\n" "$(GREEN)Done with valgrind tests$(RESET)"
	$(HIDE)printf "%s" "$(BLUE)Cleaning files: $(RESET)"
	$(HIDE)make fclean
	$(HIDE)rm -f $(PROGRAM)
	$(HIDE)printf "%s" "$(GREEN)Done: $(RESET)"

leaks: all
	$(HIDE)printf "%s" "$(YELLOW)Start compiling: $(RESET)["
	$(HIDE)$(CC) $(CFLAGS) main.c gnl_tester.a -o $(PROGRAM)
	$(HIDE)printf "%s\n" "$(GREEN)OK$(RESET)]"
	$(HIDE)$(VALGRIND_CMD) ./$(PROGRAM) $(TEST_FILES)
	$(HIDE)printf "%s\n" "$(GREEN)Done with valgrind tests$(RESET)"
	$(HIDE)printf "%s" "$(BLUE)Cleaning files: $(RESET)"
	$(HIDE)make fclean
	$(HIDE)rm -f $(PROGRAM)
	$(HIDE)printf "%s" "$(GREEN)Done: $(RESET)"

re: fclean all
