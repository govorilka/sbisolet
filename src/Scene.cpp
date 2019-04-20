#include <iostream>
#include <cfloat>
#include "precomp.h"
#include "Scene.h"


Scene* Scene::instance = nullptr;

Scene::Scene(RenderWindow &window)
   :camera(window),
    ui(window),
    birds(0),
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
    time.restart();
    birds = 0;
    lastBirdAddTime = FLT_MAX;
}

bool Scene::isGameOver() {
    return !plane.isAlive();
}

int Scene::get_hp() {
    return plane.getHP();
}

float Scene::get_time() {
    return time.getElapsedTime().asSeconds();//seconds
}

int Scene::get_score() {
    return birds;
}

int Scene::get_record() {
    return record;
}

void Scene::set_record(int value) {
    std::max(record, value);
}

void Scene::addBirds(int value) {
    birds += value;
    lastBirdAddTime = get_time();
}

int Scene::getFinalScore() {
    return birds * 100 + (int)get_time() * 10;
}

float Scene::getlastBirdTime() {
    return lastBirdAddTime;
}

int Scene::getBirds() {
    return birds;
}
