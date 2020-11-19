#ifndef CAMERA_H
# define CAMERA_H

# define FOV 60.0
# include "vector.h"

typedef	struct	s_camera
{
	t_vector	pos;
	t_vector	rot;
	t_vector	trans;
	t_vector	dir;
	t_vector	u;
	t_vector	v;
	t_vector	horiz;
	t_vector	vert;
	t_vector	low_left;
	float		ratio;
	float		fov;
	float		h;
	float		w;
}				t_camera;

#endif
