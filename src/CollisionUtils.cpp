#include "precomp.h"
#include "CollisionUtils.h"
#include "Circle.h"
#include "Segment.h"
#include <iostream>

bool isIntersects( const Circle& circle1, const Circle& circle2 )
{
    return distance( circle1.center, circle2.center ) <= (circle1.radius + circle2.radius);
}

bool isIntersects( const Segment& segment, const Circle& circle )
{
    return distance( segment, circle.center ) <= circle.radius;
}

float length( const Vector2f& v )
{
    return sqrt( v.x*v.x + v.y*v.y );
}

float distance( const Vector2f& v1, const Vector2f& v2 )
{
    return length( v2 - v1 );
}

float dot( const Vector2f& v1, const Vector2f& v2 )
{
    return v1.x*v2.x + v1.y*v2.y;
}

float cross( const Vector2f& v1, const Vector2f& v2 )
{
    return v1.x*v2.y - v1.y*v2.x;
}

float distance( const Segment& s, const Vector2f& pos )
{
    Vector2f r = pos - s.first;
    Vector2f dir = s.second - s.first;
    float dirModule = length(dir);
    float dotProductNormalized = dot(dir, r) / dirModule;
    if ( dotProductNormalized >= 0 && dotProductNormalized <= dirModule )
    {
        float c = std::abs( cross( dir, r ) );
        return c / dirModule;
    }
    else
    {
        return std::numeric_limits<float>::max();
    }
}
