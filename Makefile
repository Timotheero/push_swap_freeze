# mandatory rules:
# $(NAME), clean, fclean, re, all
# all must be default when typing make 

# no unnecessary relinks -> if so: fail
# if multibinary pproject: rule for each binary (eg. $(NAME_1), $(NAME_2), ...). all should comipile all binarys

# if non-system libary is called (eg. libft) Makefile should compile this libary automaticly

# All src files must be named in your Makefile (eg. no *c, *.o)

# =============================================================================
#								SOURCES
# =============================================================================

# variables
NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
LIBFT_DIR	:= libft
INCLUDES	:= -I. -I$(LIBFT_DIR) 
OBJ_DIR		:= obj

# SRC files
SRCS =	input_parsing/input_check.c\
		input_parsing/input_receiver.c\
		operations/push.c\
		operations/rotate.c\
		operations/swap.c\
		push_swap.c\
		utils.c

# Object files
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))


# compile object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# including libarys
LIBFT		:= $(LIBFT_DIR)/libft.a

# all rule
all: $(NAME)

# create directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# compile executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@


# build libarys
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


# clean
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) 
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re