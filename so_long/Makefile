##### COLOR #####
BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

##### VAR #####
NAME   = so_long
CC    = gcc -Wall -Werror -Wextra -g3
# -MMD -MP

SRC  := ft_check_filemap.c \
		ft_check_format.c \
		ft_create_game.c \
		ft_so_long.c \
		ft_valid_path.c \
		ft_move.c \
		ft_free.c \
		ft_handle_p.c \

OBJ = $(SRC:%.c=%.o)
DEPS = $(OBJ:%.o=%.d)
LIBX = -L minilibx/ 
LIBXFLAGS = -lmlx -lXext -lX11 -lz -lm

##### RULES #####
all: $(NAME)

$(NAME) : $(OBJ)
	@echo
	@echo -e "${YELLOW} ----- compile -----${NC}"
	@echo
	$(MAKE) --no-print-directory -C libft
	$(MAKE) --no-print-directory -C minilibx
	$(CC) $(OBJ) minilibx/libmlx_Linux.a libft/libft.a $(LIBX) $(LIBXFLAGS) -o $(NAME) 

%.o : %.c Makefile
	$(CC) -c $< -o $@

clean:
	@echo
	@echo -e "${YELLOW} ----- clean...  -----${NC}"
	@echo
	rm -f $(OBJ)
	rm -f $(DEPS)
	make clean --no-print-directory -C minilibx
	make fclean --no-print-directory -C libft
	@echo
	@echo -e "${YELLOW} ----- ✅ clean done -----${NC}"
	@echo

fclean :
	@echo
	@echo -e "${YELLOW} ----- clean...  -----${NC}"
	@echo
	make clean --no-print-directory
	rm -f $(NAME)
	@echo
	@echo -e "${YELLOW} ----- ✅ fclean done -----${NC}"
	@echo

re : fclean all 

# -include ${DEPS}

.PHONY: clean fclean all re
