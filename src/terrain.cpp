#include "precomp.h"
#include "terrain.h"
#include "Camera.h"
#include "Scene.h"
#include "Enemies/Enemies.h"
#include "Utils.h"

Terrain* Terrain::instance = nullptr;

Terrain::Terrain() {
    instance = this;
}

void Terrain::initScene() {
    vertexes.clear();
    seg_list.clear();
    vertexes.setPrimitiveType(Quads);
    FloatRect rect = Camera::instance->getRect();
    x_size =  rect.width*TERRAIN_SEGMENT_WIDTH;
    shift = -rect.height*TERRAIN_SEGMENT_MAX_SHIFT;

    do{
        add_new_segment();
    }while(seg_list.back().second.x < rect.width);
    new_vertex_array();
}

void Terrain::new_vertex_array() {
    vertexes.resize(seg_list.size()*4);
    auto it = seg_list.begin();
    for(int i = 0; i<seg_list.size()*4;i+=4,it++)
    {
        vertexes[i] =   Vertex(Vector2f(it->first.x,0),TERRAIN_COLOR);
        vertexes[i+1] = Vertex(it->first,TERRAIN_COLOR);
        vertexes[i+2] = Vertex(it->second,TERRAIN_COLOR);
        vertexes[i+3] = Vertex (Vector2f(it->second.x,0),TERRAIN_COLOR);
    }
}

void Terrain::add_new_segment() {
    FloatRect rect = Camera::instance->getRect();
    float new_y = -rect.height*TERRAIN_SEGMENT_MIN_HEIGHT;
    float new_x = rect.left;
    Segment segment;
    if(seg_list.empty()){
        segment = Segment(Vector2f(new_x,new_y),Vector2f(new_x + x_size,new_y));
    }else{
        Vector2f last_point = seg_list.back().second;
        new_y = last_point.y;
        if((Utils::getRandomNumber(0, 1) && new_y < -rect.height*TERRAIN_SEGMENT_MAX_HEIGHT) || ( new_y < -rect.height*TERRAIN_SEGMENT_MIN_HEIGHT))
        {
            new_y += (float)(Utils::getRandomNumber(0, 10000)) / 10000 *shift;
        }else
        {
            new_y -= (float)(Utils::getRandomNumber(0, 10000)) / 10000 *shift;
        }
        segment = Segment(last_point, Vector2f(last_point.x + x_size,new_y));
    }
    seg_list.emplace_back(segment);
    Scene::instance->onTerrainSegmentCreated(segment);


}

void Terrain::update(float deltaTime)
{
    while(seg_list.front().second.x< Camera::instance->getRect().left){
        seg_list.pop_front();
        add_new_segment();
    }
    new_vertex_array();
}



void Terrain::render(sf::RenderWindow &window) {
    window.draw(vertexes);
}

bool Terrain::isIntersects(const Circle& circle){
    for ( const auto& segment: seg_list){
        if (::isIntersects(segment, circle)){
            return true;
        }
    }
    return false;
}
