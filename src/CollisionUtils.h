#pragma once

class Circle;
class Segment;

bool isIntersects(const Circle& circle, const Segment& segment);
float cross(const Vector2f& v1, const Vector2f& v2);
float dot(const Vector2f& v1, const Vector2f& v2);