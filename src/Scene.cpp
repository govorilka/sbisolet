#include <iostream>
#include "precomp.h"
#include "Scene.h"


Scene* Scene::instance = nullptr;

Scene::Scene(RenderWindow &window)
   :camera(window),
    ui(window),
    score(0),
    record(0)
{
    instance = this;
}

void Scene::update(float deltaTime) {
    plane.update(deltaTime);
    enemies.update(deltaTime);
    terrain.update(deltaTime);
    camera.update(deltaTime);
    ui.update(deltaTime);
}

void Scene::render(sf::RenderWindow &window) {
    window.clear(Color(0, 0, 255));
    terrain.render(window);
    camera.render(window);
    enemies.render(window);
    plane.render(window);
    ui.render(window);
}


void Scene::initScene() {
    plane.initScene();
    camera.initScene();
    enemies.initScene();
}

bool Scene::isGameOver() {
    return !plane.isAlive();
}

int Scene::get_hp() {
    return plane.getHP();
}

float Scene::get_time() {

    return 321;//seconds
}

int Scene::get_score() {
    return score;
}

int Scene::get_record() {
    return record;
}

void Scene::set_record(int value) {
    std::max(record, value);
}

void Scene::addScore(int value) {
    score += value;
}
