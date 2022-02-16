#include "../include/object.h"

data_intersection::data_intersection(object* _ptr, const vector3& _point) :
	point(_point)
{
	ptr = _ptr;
}

object::object(const vector3& _color, float _ka, float _kd, float _ks) :
	color(_color),
	ka(_ka),
	kd(_kd),
	ks(_ks)
{}