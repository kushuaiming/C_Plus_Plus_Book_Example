#include <iostream>
using namespace std;

class Point3d {
public:
    Point3d normalize() const;
    float magnitude() const;
private:
    float _x;
    float _y;
    float _z;
};

Point3d Point3d::normalize() const {
    register float mag = magnitude();
    Point3d normal;

    normal._x = _x / mag;
    normal._y = _y / mag;
    normal._z = _z / mag;

    return normal;
}

float Point3d::magnitude() const {
    return sqrt(_x * _x + _y * _y + _z * _z);
}

int main(int argc, char* argv[]) {
    Point3d obj;
    Point3d* ptr = &obj;
    obj.normalize();
    ptr->normalize();
    return 0;
}