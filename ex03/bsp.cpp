#include "Point.hpp"

static float crossProduct(Point const &p1, Point const &p2, Point const &p) {
    return (p2.get_x().toFloat() - p1.get_x().toFloat()) * (p.get_y().toFloat() - p1.get_y().toFloat()) -
           (p2.get_y().toFloat() - p1.get_y().toFloat()) * (p.get_x().toFloat() - p1.get_x().toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float d1 = crossProduct(a, b, point);
    float d2 = crossProduct(b, c, point);
    float d3 = crossProduct(c, a, point);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}
