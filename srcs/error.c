#include "../includes/rtv1.h"

void	ft_print_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	ft_sdl_error(void)
{
	ft_putendl(SDL_GetError());
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
