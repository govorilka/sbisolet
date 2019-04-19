#include <iostream>
#include "precomp.h"
#include "Scene.h"


Scene* Scene::instance = nullptr;

Scene::Scene(RenderWindow &window)
   :camera(window),
    ui(window)
{
    instance = this;
}

void Scene::update(float deltaTime) {
    plane.update(deltaTime);
    kamikaze.update(deltaTime);
    balloon.update(deltaTime);
    terrain.update(deltaTime);
    camera.update(deltaTime);
    ui.update(deltaTime);
}

void Scene::render(sf::RenderWindow &window) {
    window.clear(Color(0, 0, 255));
    camera.render(window);
    terrain.render(window);
    kamikaze.render(window);
    balloon.render(window);
    plane.render(window);
    ui.render(window);
}


void Scene::initScene() {
    plane.initScene();
    camera.initScene();
    kamikaze.initScene();
    balloon.initScene();
}

bool Scene::isGameOver(){
    return !plane.isAlive();
}

int Scene::get_hp(){
    return plane.getHP();
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
