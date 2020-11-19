#include "../includes/rtv1.h"

float	ft_clamp(float min, float max, float val)
{
	return (fmax(min, fmin(max, val)));
}

float	ft_rand48(void)
{
	static int	initialized = 0;

	if (!initialized)
	{
		initialized = 1;
		srand(time(NULL));
	}
	return ((float)rand() / (float)RAND_MAX);
}

int		ft_tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
