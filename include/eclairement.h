#pragma once

#include "object.h"
#include "scene.h"
#include "vector3.h"

class object;

class eclairement
{
protected:
	object* my_obj;

public:
	eclairement(object*);

	virtual vector3 operator()(const vector3&, const vector3&, const scene&) = 0;

	void change_obj(object*);
};

class diffuse : public eclairement
{
public:
	diffuse(object*);

	virtual vector3 operator()(const vector3&, const vector3&, const scene&);
};

class phong : public eclairement
{
public:
	phong(object*);

	virtual vector3 operator()(const vector3&, const vector3&, const scene&);
};

class ambiant : public eclairement
{
public:
	ambiant(object*);

	virtual vector3 operator()(const vector3&, const vector3&, const scene&);
};