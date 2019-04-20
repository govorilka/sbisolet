#pragma once

class Circle;
class Segment;


bool isIntersects( const Circle& circle1, const Circle& circle2 );
bool isIntersects( const Segment& segment, const Circle& circle );

float length( const Vector2f& v );
float distance( const Vector2f& v1, const Vector2f& v2 );
float distance( const Segment& s, const Vector2f& v );
float cross( const Vector2f& v1, const Vector2f& v2 );
float dot( const Vector2f& v1, const Vector2f& v2 );