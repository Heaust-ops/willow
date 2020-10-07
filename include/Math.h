#pragma once

#include <iostream>
#include <cmath>
#include <complex>

class Vector2
{

public:
    float x, y;
    Vector2(float a, float b);
    float length();
    float sqrLength();
    Vector2 operator*(float s);
    void normalize();
    float dot(Vector2 a, Vector2 b);
    float cross(Vector2 a, Vector2 b);
    Vector2 cross(Vector2 a, float s);
    Vector2 cross(float s, Vector2 a);
};

class Matrix2
{
    float m00, m01;
    float m10, m11;
    Matrix2(float a, float b, float c, float d);
    void set(float radians);
    Matrix2 transpose();
    Vector2 operator*(Vector2 rhs);
    Matrix2 operator*(Matrix2 rhs);
};
