#include "../includes/rtv1.h"

t_vector	ft_rotate_x(t_vector r, float angle)
{
	t_vector res;

	res = (t_vector){0.0, 0.0, 0.0};
	res.x = r.x;
	res.y = r.y * cos(angle) - sin(angle) * r.z;
	res.z = r.y * sin(angle) + cos(angle) * r.z;
	return (res);
}

t_vector	ft_rotate_y(t_vector r, float angle)
{
	t_vector	res;

	res = (t_vector){0.0, 0.0, 0.0};
	res.x = r.x * cos(angle) + sin(angle) * r.z;
	res.y = r.y;
	res.z = -r.x * sin(angle) + cos(angle) * r.z;
	return (res);
}

t_vector	ft_rotate_z(t_vector r, float angle)
{
	t_vector	res;

	res = (t_vector){0.0, 0.0, 0.0};
	res.x = r.x * cos(angle) - sin(angle) * r.y;
	res.y = r.x * sin(angle) + cos(angle) * r.y;
	res.z = r.z;
	return (res);
}

t_vector	ft_rotate_vec3(t_vector r, t_vector v, int invert)
{
	if (invert)
	{
		r = ft_rotate_z(r, DEG_TO_RAD(-v.z));
		r = ft_rotate_y(r, DEG_TO_RAD(-v.y));
		r = ft_rotate_x(r, DEG_TO_RAD(-v.x));
	}
	else
	{
		r = ft_rotate_x(r, DEG_TO_RAD(v.x));
		r = ft_rotate_y(r, DEG_TO_RAD(v.y));
		r = ft_rotate_z(r, DEG_TO_RAD(v.z));
	}
	return (r);
}
