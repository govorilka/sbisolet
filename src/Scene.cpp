#include "precomp.h"
#include "Scene.h"


Scene* Scene::instance = nullptr;

Scene::Scene(RenderWindow &window)
: camera(window),
ui(window)
{
    instance=this;
}

void Scene::update(float deltaTime) {
    camera.update(deltaTime);
    terrain.update(deltaTime);
    plane.update(deltaTime);
    ui.update(deltaTime);
}

void Scene::render(sf::RenderWindow &window) {
    window.clear(Color(0, 0, 255));
    camera.render(window);
    terrain.render(window);
    plane.render(window);
    ui.render(window);
}


void Scene::initScene() {
    plane.initScene();
    camera.initScene();
}

bool Scene::isGameOver(){
    return false;
}

int Scene::get_hp(){
    return 4;
}

float Scene::get_time(){

    return 321;//seconds
}

int Scene::get_score() {
    return 323123;
}

int Scene::get_record(){
    return 0;
}

void Scene::set_record(int value) {


}
