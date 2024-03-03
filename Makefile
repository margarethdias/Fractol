NAME	:= fractol
CFLAGS	:= -Wunreachable-code -Ofast -g3 -Wextra -Wall -Werror
LIBMLX	:= ./.lib/MLX42
BIN		:= bin

FILES	= fractal_init.c colors.c utils.c \
			main.c cursor_hooks.c key_hooks.c \
			mandelbrot.c julia.c tricorn.c \
			messages.c complex_math.c \

M_PATH	= src

HEADERS	 = -I ./include -I $(LIBMLX)/include
LIBMLX42 = $(LIBMLX)/build/libmlx42.a
LIBS	 = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	 = $(addprefix  $(M_PATH)/, $(FILES))
OBJS	 = $(patsubst %, $(BIN)/%, $(notdir $(SRCS:.c=.o)))

all: $(BIN) $(LIBMLX42) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(LIBMLX42):
	@cd ./.lib/MLX42/ && cmake -B build
	@cd ./.lib/MLX42/ && cmake --build build -j4

$(BIN):
	@mkdir -p $(BIN)

$(BIN)/%.o: $(M_PATH)/%.c | $(BIN)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(LIBMLX42)
	@rm -rf $(BIN)

fclean: clean
	@rm -rf $(NAME)

re: clean all

bonus: all

.PHONY: all, clean, fclean, re, bonus