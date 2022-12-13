NAME = cube3d

COLOR_ESC			= \033
COLOR_WHITE			= $(COLOR_ESC)[97m
COLOR_CYAN			= $(COLOR_ESC)[96m
COLOR_GREEN			= $(COLOR_ESC)[32m
COLOR_BLUE			= $(COLOR_ESC)[34m
COLOR_YELLOW		= $(COLOR_ESC)[33m
COLOR_MAGENTA 		= $(COLOR_ESC)[35m
COLOR_BOLD			= $(COLOR_ESC)[1m
COLOR_RESET			= $(COLOR_ESC)[0m
COLOR_RESET_BOLD	= $(COLOR_ESC)[21m

PATH_HEADER			= includes/
PATH_PARSER			= src_parser/
PATH_ROUTINE		= src_routine/
PATH_RAYTRACING		= src_raytracing/
PATH_GARBAGE		= src_garbage/
PATH_UTIL			= src_util/
PATH_OBJ			= objs/

HEADER				= 	data.h includes.h parser.h routine.h raycasting.h garbage.h utils.h
SRC_PARSER			= 	parser.c valid_arg.c
SRC_ROUTINE			= 	routine.c init_mlx.c render_frame.c
SRC_RAYTRACING		= 	raytracing.c
SRC_GARBAGE			= 	garbage.c free.c malloc.c
SRC_UTIL			= 	utils.c get_data.c ft_itoa.c ft_mem.c ft_split.c ft_str.c ft_putstr.c mlx_put_rec.c mlx_utils.c

SRC_PARSERS			= $(addprefix $(PATH_PARSER),$(SRC_PARSER))
SRC_ROUTINES		= $(addprefix $(PATH_ROUTINE),$(SRC_ROUTINE))
SRC_RAYTRACINGS		= $(addprefix $(PATH_RAYTRACING),$(SRC_RAYTRACING))
SRC_GARBAGES		= $(addprefix $(PATH_GARBAGE),$(SRC_GARBAGE))
SRC_UTILS			= $(addprefix $(PATH_UTIL),$(SRC_UTIL))

SRCS 				= $(SRC_PARSERS) $(SRC_ROUTINES) $(SRC_RAYTRACINGS) $(SRC_GARBAGES) $(SRC_UTILS)

OBJ					= $(SRCS:.c=.o)
OBJS				= $(addprefix $(PATH_OBJ),$(OBJ))
HEADERS				= $(addprefix $(PATH_HEADER),$(HEADER))

DEBUG				= 0
DEBUGING			= -g3 -fsanitize=address
CFLAGS				= -O3 -Wall -Wextra -Werror


OPTIONS				= -I$(PATH_HEADER)
LIBS				= -lm
CC					= gcc
RM					= rm -rf

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS			+= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	OPTIONS			+= -Imlx_linux
	PATH_MLX		= mlx_linux
	MLX				= mlx_linux
endif

ifeq ($(UNAME), Darwin)
	LIBS 			+= -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
	OPTIONS 		+= -Imlx_macos
	PATH_MLX 		= mlx_macos
	MLX				= mlx_macos
endif

ifeq ($(DEBUG), 1)
	CFLAGS += $(DEBUGING)
endif

all			: $(NAME)

$(PATH_OBJ)$(PATH_PARSER)%.o	: $(PATH_PARSER)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_PARSER)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_CYAN)DEBUG => [%s] $(COLOR_BOLD)PARSER\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_ROUTINE)%.o	: $(PATH_ROUTINE)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_ROUTINE)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_BLUE)DEBUG => [%s] $(COLOR_BOLD)ROUTINE\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_RAYTRACING)%.o: $(PATH_RAYTRACING)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_RAYTRACING)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_MAGENTA)DEBUG => [%s] $(COLOR_BOLD)RAYTRACING\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_GARBAGE)%.o	: $(PATH_GARBAGE)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_GARBAGE)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_YELLOW)DEBUG => [%s] $(COLOR_BOLD)GARBAGE\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_UTIL)%.o		: $(PATH_UTIL)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_UTIL)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_MAGENTA)DEBUG => [%s] $(COLOR_BOLD)UTIL\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(MLX):
	@make -C $(PATH_MLX)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_CYAN)MLX$(COLOR_RESET)\n"

$(NAME)		: $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) $(OBJS) $(LIBS)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] LINKAGE $(COLOR_BOLD)ALL OBJS FILE =>\n\t $(COLOR_WHITE)$(^:.o=.o\n\t)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION FINISH !$(COLOR_WHITE)$(COLOR_RESET_BOLD)"

clean		:
	@$(RM) $(OBJS)
	@$(RM) $(PATH_OBJ)
	@make -C $(PATH_MLX) clean
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] DELETE $(COLOR_BOLD)ALL OBJS FILE =>\n\t $(COLOR_WHITE)$(OBJS:.o=.o\n\t)"
	@make -C $(PATH_MLX) clean
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] CLEAN MLX !$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] CLEAN FINISH !$(COLOR_RESET)"

fclean		: clean
	@$(RM) $(NAME)
	@$(RM) $(PATH_MLX)/libmlx.a
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] DELETE $(COLOR_BOLD)PROGRAMME =>\n\t $(COLOR_WHITE)$(NAME)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] FCLEAN FINISH !$(COLOR_RESET)"

re			: fclean all

.PHONY: all fclean clean re $(MLX)