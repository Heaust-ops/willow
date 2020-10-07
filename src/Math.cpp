#include <iostream>
#include <cmath>
#include <complex>

class Vector2
{
public:
    float x, y;

    Vector2(float a, float b)
    {
        x = a;
        y = b;
    }

    float length()
    {
        return sqrt(x * x + y * y);
    }
    float sqrLength()
    {
        return x * x + y * y;
    }

    Vector2 operator*(float s)
    {
        return Vector2(this->x * s, this->y * s);
    }

    void normalize()
    {
        float inv_len = 1 / length();
        x *= inv_len;
        y *= inv_len;
    }

    float dot(Vector2 a, Vector2 b)
    {
        return a.x * b.x + a.y * b.y;
    }

    // Two crossed vectors
    float cross(Vector2 a, Vector2 b)
    {
        return a.x * b.y - a.y * b.x;
    }
    //A vector crossed with a scalar
    Vector2 cross(Vector2 a, float s)
    {
        return Vector2(s * a.y, -s * a.x);
    }
    Vector2 cross(float s, Vector2 a)
    {
        return Vector2(-s * a.y, s * a.x);
    }
};

class Matrix2
{
    float m00, m01;
    float m10, m11;

    Matrix2(float a, float b, float c, float d)
    {
        m00 = a;
        m01 = b;
        m10 = c;
        m11 = d;
    }

    //Create from angle in radians
    void set(float radians)
    {
        float c = cos(radians);
        float s = sin(radians);

        m00 = c;
        m01 = -s;
        m10 = s;
        m11 = c;
    }

    Matrix2 transpose()
    {
        return Matrix2(this->m00, this->m10,
                       this->m01, this->m11);
    }

    Vector2 operator*(Vector2 rhs)
    {
        return Vector2(this->m00 * rhs.x + this->m01 * rhs.y, this->m10 * rhs.x + this->m11 * rhs.y);
    }

    Matrix2 operator*(Matrix2 rhs)
    {
        return Matrix2(
            m00 * rhs.m00 + m01 * rhs.m10, m00 * rhs.m01 + m01 * rhs.m11,
            m10 * rhs.m00 + m11 * rhs.m10, m10 * rhs.m01 + m11 * rhs.m11);
    }
};
