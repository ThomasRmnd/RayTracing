#include "../include/object.h"

vector3 object::diffuse(const vector3& A, const scene& my_scene)
{
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		vector3 v(A, current_lumiere->org);
		vector3 u = this->vector_normal(A);
		I += std::max(0.0f, angle(u, v)) * current_lumiere->I;
	}
	return I;
}