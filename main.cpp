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

    Vector3D v3d = Vector3D(0.3, 0.3, 0.5);
    cout << v3d << endl;
}