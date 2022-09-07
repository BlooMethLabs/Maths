#include <iostream>
#include <cmath>

class Vector3D
{
public:
    float x, y, z;

    Vector3D() = default;

    Vector3D(float a, float b, float c) : x(a), y(b), z(c)
    {
    }

    float &operator[](int i)
    {
        return ((&x)[i]);
    }

    const float &operator[](int i) const
    {
        return ((&x)[i]);
    }

    Vector3D &operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D &operator /=(float s)
    {
        s = 1.0F /s;
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D &operator +=(const Vector3D &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3D &operator -=(const Vector3D &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }
};

std::ostream &operator<<(std::ostream &os, const Vector3D v3d)
{
    os << "[" << v3d.x << ", " << v3d.y << ", " << v3d.z << "]";
    return os;
}

inline Vector3D operator*(const Vector3D &v, float s)
{
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator/(const Vector3D &v, float s)
{
    s = 1.0F / s;
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator-(const Vector3D &v)
{
    return Vector3D(-v.x, -v.y, -v.z);
}

inline float Magnitude(const Vector3D &v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalise(const Vector3D &v)
{
    return v / Magnitude(v);
}

inline Vector3D operator+(const Vector3D &v1, const Vector3D &v2)
{
    return(Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

inline Vector3D operator-(const Vector3D &v1, const Vector3D &v2)
{
    return(Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}
