class Point2d {
 public:
  Point2d(float x = 0.0, float y = 0.0) : _x(x), _y(y){};

  float x() const { return _x; }
  float y() const { return _y; }

  void x(float newX) { _x = newX; }
  void y(float newY) { _y = newY; }

  void operator+=(const Point2d& rhs) {
    _x += rhs.x();
    _y += rhs.y();
  }
  // ... more members

 protected:
  float _x, _y;
};

class Point3d : public Point2d {
 public:
  Point3d(float x = 0.0, float y = 0.0, float z = 0.0) : Point2d(x, y), _z(z){};
  float z() const { return _z; }
  void z(float newZ) { _z = newZ; }

  void operator+=(const Point3d& rhs) {
    Point2d::operator+=(rhs);
    _z += rhs.z();
  }
  // ... more members

 protected:
  float _z;
};
