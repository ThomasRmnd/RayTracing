#pragma once

#include <cmath>

class vector3 {

public:

    float x;

    float y;

    float z;

    // Construtors && Destructor

    vector3();

    vector3(float,float,float);

    vector3(const vector3&,const vector3&);

    vector3(const vector3&) = default;

    static vector3 spherical(float,float,float);

    ~vector3() = default;

    // Assignment operators

    vector3& operator=(const vector3&) = default;

    vector3& operator+=(const vector3&);

    vector3& operator-=(const vector3&);

    vector3& operator*=(float);

    vector3& operator/=(float);

    // Other methods

    float norm() const;

    float norm_2() const;

    float theta() const;

    float phi() const;

    void normalize();

};

// Arithmetic operators 

vector3 operator+(const vector3&,const vector3&);
vector3 operator+(const vector3&);

vector3 operator-(const vector3&,const vector3&);
vector3 operator-(const vector3&);

vector3 operator*(const vector3&,float);
vector3 operator*(float,const vector3&);

vector3 operator/(const vector3&,float);

// Logical operators

bool operator==(const vector3&,const vector3&);

bool operator!=(const vector3&,const vector3&);

// Other functions 

float dot(const vector3&,const vector3&);

vector3 cross(const vector3&,const vector3&);

float angle(const vector3&,const vector3&);

float distance(const vector3&,const vector3&);