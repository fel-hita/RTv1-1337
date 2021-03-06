#include "../includes/rtv1.h"

t_vector	ft_random_unit(void)
{
	t_vector	p;

	p = (t_vector){1.0, 1.0, 1.0};
	while (p.x * p.x + p.y * p.y + p.z * p.z >= 1.0)
	{
		p = ft_vector_sub(ft_vector_kmult(2.0,
					ft_vector(ft_rand48(), ft_rand48(), ft_rand48())),
				ft_vector(1.0, 1.0, 1.0));
	}
	return (p);
}

int			ft_lambertian_sc(t_intersect *in, t_color *att)
{
	t_vector	target;

	in->ray.start = in->p;
	target = ft_vector_sum(ft_vector_sum(in->p, in->n), ft_random_unit());
	*att = ft_color_sum(*att, in->current->material.diffuse);
	in->ray.dir = ft_vector_sub(target, in->p);
	return (1);
}

int			ft_metal_sc(t_intersect *in, t_color *att)
{
	t_vector	reflected;

	in->ray.start = in->p;
	reflected = ft_reflect(ft_vector_normalized(in->ray.dir), in->n);
	*att = in->current->material.diffuse;
	in->ray.dir = reflected;
	return (ft_vector_dot(reflected, in->n) > 0);
}

int			ft_dielectric_sc(t_intersect *in, t_color *att, float ref_idx)
{
	t_vector	reflected;
	t_vector	refracted;
	t_vector	out_n;
	float		ni_over_nt;

	*att = (t_color){1.0, 1.0, 1.0};
	in->ray.start = in->p;
	reflected = ft_reflect(in->ray.dir, in->n);
	if ((in->ray.dir.x * in->n.x + in->ray.dir.y * in->n.y +
				in->ray.dir.z * in->n.z) > 0.001)
	{
		out_n = (t_vector){-in->n.x, -in->n.y, -in->n.z};
		ni_over_nt = ref_idx;
	}
	else
	{
		out_n = (t_vector){in->n.x, in->n.y, in->n.z};
		ni_over_nt = 1.0 / ref_idx;
	}
	if (ft_refract(in->ray.dir, out_n, ni_over_nt, &refracted))
		in->ray.dir = refracted;
	else
		in->ray.dir = reflected;
	return (1);
}

t_color		ft_path_trace(t_scene *s, t_intersect *in, int depth)
{
	t_color		c;

	c = (t_color){0.0, 0.0, 0.0};
	in->t = INFINITY;
	if (!ft_scene_intersect(s, in))
		return (ft_background_color(&in->ray));
	if (depth < MAX_DEPTH)
	{
		if (in->current->material.refraction > 0.0)
		{
			if (ft_dielectric_sc(in, &c, in->current->material.refraction))
				return (ft_color_mult(c, ft_path_trace(s, in, depth + 1)));
		}
		else if (in->current->material.reflection > 0.0)
		{
			if (ft_metal_sc(in, &c))
				return (ft_color_mult(c, ft_path_trace(s, in, depth + 1)));
		}
		else if (ft_lambertian_sc(in, &c))
			return (ft_color_mult(c, ft_path_trace(s, in, depth + 1)));
	}
	return (c);
}
