NAME = libftprintf.a

# Compiler
CC = cc

# Remove command
RM = rm -f

# Directory containing the source files
SRC_DIR = .

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files to be compiled into objects
SRCS = ft_printf.c ft_printf_aux.c

# Object files generated from source files
OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

# Rule to compile individual source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the target library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Rule to build the library
all: $(NAME)

# Rule to remove object files
clean:
	@$(RM) $(OBJS)

# Rule to remove object files and the target library
fclean: clean
	@$(RM) $(NAME)

# Rule to perform a full rebuild
re: fclean all

#PHONY
.PHONY: all clean fclean re

# End of Makefile
