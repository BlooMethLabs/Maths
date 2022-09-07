#pragma once
#include <iostream>
#include "Vector3D.h"
#include <iomanip>

class Matrix3D
{
private:
    float n[3][3];

public:
    Matrix3D();
    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22)
    {
        n[0][0] = n00;
        n[0][1] = n10;
        n[0][2] = n20;
        n[1][0] = n01;
        n[1][1] = n11;
        n[1][2] = n21;
        n[2][0] = n02;
        n[2][1] = n12;
        n[2][2] = n22;
    }
    Matrix3D(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3)
    {
        n[0][0] = v1.x; n[0][1] = v1.y; n[0][2] = v1.z;
        n[1][0] = v1.x; n[1][1] = v1.y; n[1][2] = v1.z;
        n[2][0] = v1.x; n[2][1] = v1.y; n[2][2] = v1.z;
    }
    const float &operator()(int i, int j) const
    {
        return (n[j][i]);
    }

    Vector3D& operator[](int j)
    {
        return (*reinterpret_cast<Vector3D *>(n[j]));
    }

    const Vector3D& operator[](int j) const
    {
        return (*reinterpret_cast<const Vector3D *>(n[j]));
    }

};

std::ostream &operator<<(std::ostream &os, const Matrix3D m3d)
{
    for (int i = 0; i < 3; ++i)
    {
        os << "| ";
        for (int j = 0; j < 3; ++j)
        {
            os << std::fixed << std::setw(11) << std::setprecision(6)
               << std::setfill(' ') << m3d(j, i) << " |";
        }
        os << std::endl;
    }
    return os;
}

Matrix3D operator *(const Matrix3D &A, const Matrix3D &B)
{
    return (Matrix3D(A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
                     A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
                     A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
                     A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
                     A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
                     A(1, 0) * B(0, 2) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 2),
                     A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
                     A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
                     A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)));
}

Matrix3D operator *(const Matrix3D &M, const Vector3D &v)
{
    return (Matrix3D(M(0, 0) * v.x, M(0, 1) * v.y, M(1, 1) * v.z,
                     M(1, 0) * v.x, M(1, 1) * v.y, M(1, 1) * v.z,
                     M(2, 0) * v.x, M(2, 1) * v.y, M(2, 1) * v.z));
}
