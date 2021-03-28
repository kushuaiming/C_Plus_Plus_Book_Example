#include <iostream>
using namespace std;

typedef struct point3d {
    float x;
    float y;
    float z;
} Point3d;

void Point3d_print(const Point3d* pd) {
    printf("( %g, %g, %g )", pd->x, pd->y, pd->z);
}

int main(int argc, char* argv[]) {
    Point3d pt;
    pt.x = 0.0;
    return 0;
}

