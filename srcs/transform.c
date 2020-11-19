#include "../includes/rtv1.h"

t_vector	ft_scale_vec3(t_vector r, t_vector v, int invert)
{
	if (invert)
	{
		r.x /= v.x;
		r.y /= v.y;
		r.z /= v.z;
	}
	else
	{
		r.x *= v.x;
		r.y *= v.y;
		r.z *= v.z;
	}
	return (r);
}

t_vector	ft_translate_vec3(t_vector r, t_vector v, int invert)
{
	if (invert)
	{
		r.x -= v.x;
		r.y -= v.y;
		r.z -= v.z;
	}
	else
	{
		r.x += v.x;
		r.y += v.y;
		r.z += v.z;
	}
	return (r);
}
