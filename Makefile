# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrotov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 15:31:28 by akrotov           #+#    #+#              #
#    Updated: 2017/10/28 23:57:35 by akrotov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;36m"
PURPLE:="\033[1;35m"
WHITE:="\033[1;37m"
#===================

NAME = wolf3d

SOURCE = action.c \
		arr_2d.c \
		read_map.c \
		free_map.c \
		get_map_size.c \
		msg_lock.c \
		combo_sort.c \
		main_init.c \
		free_main.c \
		main.c \
		main_loop.c \
		get_drop.c \
		error.c \
		draw_bar.c \
		fps.c \
		read_file.c \
		init_sdl_insomnia.c \
		z_buff.c \
		torch.c \
		init_all_scene.c \
		ft_sdl_event_hook.c \
		ft_sdl_set_rect.c \
		ft_sdl_init_sound.c \
		ft_sdl_texture.c \
		ft_sdl_init.c \
		ft_sdl_close.c \
		ft_sdl_update_window_size.c \
		ft_sdl_create_wnd_renderer.c \
		ft_sdl_ttf.c \
		ft_ray_cast.c \
		ft_ray_cast_sprite.c \
		draw_line_wall.c \
		change_light_texture.c \
		draw_sprite_stripe.c \
		set_rc_param.c \
		sort_sprite.c \
		set_ds_param.c \
		dda.c \
		destruct_garden_scene.c \
		event_hook_garden.c \
		design_garden.c \
		first_init_garden.c \
		garden.c \
		scream_event_garden.c \
		load_assets_garden.c \
		init_garden.c \
		destruct_start_scene.c \
		init_start_scene.c \
		start.c \
		design_start_scene.c \


SRCPATH = src
HDRPATH = includes
OBJPATH = obj
LIBPATH = libft

CC = gcc -g

FLAGS = -Wall -Wextra -Werror -I $(HDRPATH)

SDL_FLAGS = -F ./SDL -O3

SDL_FRAMEWORK = -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer

LIB = -L $(LIBPATH) -lft -lm

OBJ = $(addprefix $(OBJPATH)/,$(SOURCE:.c=.o))

INC = -I $(HDRPATH) -I $(LIBPATH)

all: load lib $(NAME)

lib:
	@make -C $(LIBPATH)

load:
	@echo $(CYAN) "     LOADING"

$(NAME): $(OBJ)
	@echo $(END)
	@$(CC) $(FLAGS) $(SDL_FLAGS) $(SDL_FRAMEWORK) -o $(NAME) $(LIB) $^
	@echo $(GREEN)"   $(NAME) installed"$(END)

$(OBJPATH)/%.o: $(SRCPATH)/%.c $(SRCPATH)/%.c
	@echo ".\c"
	@mkdir $(OBJPATH) 2> /dev/null || true
	@clang $(FLAGS) $(SDL_FLAGS) $(INC) -o $@ -c $<

clean:
	@make clean -C $(LIBPATH)
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBPATH)
	@echo '\033[0;31m'"$(NAME) uninstalled"'\033[0m'

re: fclean all

norm:
	@norminette SRC/$(SRC)
	@norminette $(HDRPATH)/*.h

sdl2:
	cp -r libraries/SDL/SDL2_image.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2_ttf.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2_mixer.framework ~/Library/Frameworks/

.PHONY: all lib clean fclean re norm
