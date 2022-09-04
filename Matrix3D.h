#include <iostream>

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
    const float &operator()(int i, int j) const
    {
        return (n[j][i]);
    }
};

std::ostream &operator<<(std::ostream &os, const Matrix3D m3d)
{
    for (int i = 0; i < 3; ++i)
    {
        os << "[ ";
        for (int j = 0; j < 3; ++j)
        {
            os << m3d(i, j) << " ";
        }
        os << "]" << std::endl;
    }
    return os;
}