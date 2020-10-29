#include "Math.h"

Vector2::Vector2(float a, float b)
{
    this->x = a;
    this->y = b;
}

float Vector2::length()
{
    return sqrt(this->x * this->x + this->y * this->y);
}
float Vector2::sqrLength()
{
    return this->x * this->x + this->y * this->y;
}

Vector2 Vector2::operator*(float s)
{
    return Vector2(this->x * s, this->y * s);
}

void Vector2::normalize()
{
    float inv_len = 1 / length();
    this->x *= inv_len;
    this->y *= inv_len;
}

float Vector2::dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

// Two crossed vectors
float Vector2::cross(Vector2 a, Vector2 b)
{
    return a.x * b.y - a.y * b.x;
}
//A vector crossed with a scalar
Vector2 Vector2::cross(Vector2 a, float s)
{
    return Vector2(s * a.y, -s * a.x);
}
Vector2 Vector2::cross(float s, Vector2 a)
{
    return Vector2(-s * a.y, s * a.x);
}

Matrix2::Matrix2(float a, float b, float c, float d)
{
    this->m00 = a;
    this->m01 = b;
    this->m10 = c;
    this->m11 = d;
}

//Create from angle in radians
void Matrix2::set(float radians)
{
    float c = cos(radians);
    float s = sin(radians);

    this->m00 = c;
    this->m01 = -s;
    this->m10 = s;
    this->m11 = c;
}

Matrix2 Matrix2::transpose()
{
    return Matrix2(this->m00, this->m10,
                   this->m01, this->m11);
}

Vector2 Matrix2::operator*(Vector2 rhs)
{
    return Vector2(this->m00 * rhs.x + this->m01 * rhs.y, this->m10 * rhs.x + this->m11 * rhs.y);
}

Matrix2 Matrix2::operator*(Matrix2 rhs)
{
    return Matrix2(
        this->m00 * rhs.m00 + this->m01 * rhs.m10, this->m00 * rhs.m01 + this->m01 * rhs.m11,
        this->m10 * rhs.m00 + this->m11 * rhs.m10, this->m10 * rhs.m01 + this->m11 * rhs.m11);
}
