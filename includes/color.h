#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	float		red;
	float		green;
	float		blue;
}				t_color;

t_color			ft_color(float r, float g, float b);
t_color			ft_color_sum(t_color a, t_color b);
t_color			ft_color_mult(t_color a, t_color b);
t_color			ft_color_kmult(float k, t_color a);
#endif
