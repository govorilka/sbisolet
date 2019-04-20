#pragma once
#include <list>
#include "Segment.h"
#include "Circle.h"

class Terrain{
private:
    VertexArray vertexes;
    std::list <Segment> seg_list;
    float x_size;
    float shift;
public:
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void new_vertex_array();
    void add_new_segment();
    bool isIntersects(const Circle& circle, const Segment& segment);

    Terrain();
};


