#include "precomp.h"
#include "CollisionUtils.h"
#include "Circle.h"
#include "Segment.h"


bool isIntersects(const Circle& circle, const Segment& segment){
    Vector2f vl = segment.second - segment.first;
    Vector2f w = circle.center - segment.first;
    float dis = cross(vl,w)/dot(segment.second, segment.first);
    return dis < circle.radius;
}

float cross(const Vector2f& v1, const Vector2f& v2){
    return v1.x*v2.y - v1.y*v2.x;
}

float dot(const Vector2f& v1, const Vector2f& v2){
    return v1.x*v2.x - v1.y*v2.y;
}