#include <stdlib.h>
#include <string>
#include <iostream>
#include "Matrix3D.h"
#include "Vector3D.h"

using namespace std;

int main()
{
    Matrix3D m3D = Matrix3D(0.0, 0.1, 0.2,
                            1.0, 1.1, 1.2,
                            2.0, 2.1, 2.2);

    cout << m3D << endl;
    cout << m3D(2, 0) << endl;
    cout << m3D[0] << endl;
    cout << m3D[1] << endl;
    cout << m3D[2] << endl;

    Vector3D v3d = Vector3D(0.3, 0.3, 0.5);
    cout << v3d << endl;
    v3d *= 2.0;
    cout << v3d << endl;
    v3d /= 2.0;
    cout << v3d << endl;

    cout << Vector3D(1, 1, 1) * 2;
    cout << Vector3D(1, 1, 1) / 2;
    cout << -Vector3D(1, 1, 1) << endl;
    cout << Magnitude(Vector3D(1, 1, 1)) << endl;
    cout << Normalise(Vector3D(1, 1, 1)) << endl;

    cout << "[1, 1, 1] + [0.5, -0.5, 0] = ";
    cout << Vector3D(1, 1, 1) + Vector3D(0.5, -0.5, 0) << endl;
    cout << "[1, 1, 1] - [0.5, -0.5, 0] = ";
    cout << Vector3D(1, 1, 1) - Vector3D(0.5, -0.5, 0) << endl;
    cout << "[1, 1, 1] + [0.5, -0.5, 0] = ";
    cout << (Vector3D(1, 1, 1) += Vector3D(0.5, -0.5, 0)) << endl;
    cout << "[1, 1, 1] - [0.5, -0.5, 0] = ";
    cout << (Vector3D(1, 1, 1) -= Vector3D(0.5, -0.5, 0)) << endl;

    Matrix3D m3D2 = Matrix3D(0.0, 0.1, 0.2,
                             1.0, 1.1, 1.2,
                             2.0, 2.1, 2.2);

    Matrix3D m3D3 = Matrix3D(0.0, -0.1, -0.2,
                             -1.0, -1.1, -1.2,
                             -2.0, -2.1, -2.2);

    cout << (m3D2 * m3D3) << endl;

    cout << m3D2 * Vector3D(0.3, 0.6, 1) << endl;

    cout << "Dot of same direction" << endl;
    cout << Dot(Vector3D(1, 0, 0), Vector3D(1, 0, 0)) << endl;
    cout << "Dot of opposite direction" << endl;
    cout << Dot(Vector3D(1, 0, 0), Vector3D(3, 0, 0)) << endl;
    cout << "Dot of perpindicular" << endl;
    cout << Dot(Vector3D(1, 0, 0), Vector3D(0, 3, 0)) << endl;
    cout << "Dot of unit vectors with 15 degrees between." << endl;
    cout << Dot(Vector3D(1, 0, 0), Vector3D(0.965925, 0.258819, 0)) << endl;
    cout << "Dot of unit vectors with 165 degrees between." << endl;
    cout << Dot(Vector3D(1, 0, 0), Vector3D(-0.965925, 0.258819, 0)) << endl;
    cout << "Cross of opposite" << endl;
    cout << Cross(Vector3D(10, 0, 0), Vector3D(-10, 0, 0)) << endl;
    cout << "Cross of perpindicular x and y" << endl;
    cout << Cross(Vector3D(1, 0, 0), Vector3D(0, 1, 0)) << endl;
}
