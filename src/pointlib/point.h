#include <cmath>
#include <iostream>
#include <limits>

struct Point {
  double x, y;

  Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  Point(const Point &p) : x(p.x), y(p.y) {}

  double distance(const Point &p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
};

struct Line {
  double a, b, c;

  Line(double _a = 0, double _b = 0, double _c = 0) : a(_a), b(_b), c(_c) {}

  Line(const Point &p1, const Point &p2) {
    if (p1.x == p2.x) {
      a = 1;
      b = 0;
      c = -p1.x;
    } else {
      b = 1;
      a = -(p1.y - p2.y) / (p1.x - p2.x);
      c = -(a * p1.x) - (b * p1.y);
    }
  }

  Point intersection(const Line &other) const {
    double det = a * other.b - other.a * b;
    if (det == 0) {
      return Point(std::numeric_limits<double>::infinity(),
                   std::numeric_limits<double>::infinity());
    } else {
      double x = (other.c * b - c * other.b) / det;
      double y = (c * other.a - other.c * a) / det;
      return Point(x, y);
    }
  }

  Line perpendicular(const Point &p) const {
    return Line(-b, a, b * p.x - a * p.y);
  }
};
