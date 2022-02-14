#include "../../include/camera.h"

camera::camera(const vector3& _position, const vector3& _directionVue, float _d, unsigned int resolEcran[2], float bornes[4]) :
	position(_position),
	directionVue(_directionVue),
	d(_d)
{
	nb_pixel_x = resolEcran[0], nb_pixel_y = resolEcran[1];
	xmin = bornes[0], xmax = bornes[1], ymin = bornes[2], ymax = bornes[3];
	(w = -_directionVue).normalize();
	x = _directionVue.x, y = _directionVue.y, z = _directionVue.z;
	(u = vector3(-w.z, 0, w.x)).normalize();
	v = cross(w, u);
	if (v.y < 0)
	{
		u = -u;
		v = -v;
	}
}

vector3 camera::point(unsigned int i, unsigned int j)
{
	x = xmin + i * (xmax - xmin) / nb_pixel_x;
	y = ymin + j * (ymax - ymin) / nb_pixel_y;
	z = -d;
	vector3 P = position + x * u + y * v + z * w;
	return P;
}