#include <iostream>

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
};

std::ostream &operator<<(std::ostream &os, const Vector3D v3d)
{
    os << "[" << v3d.x << ", " << v3d.y << ", " << v3d.z << "]";
    return os;
}