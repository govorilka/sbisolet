#include <iostream>
#include <cfloat>
#include "precomp.h"
#include "Scene.h"


Scene* Scene::instance = nullptr;

Scene::Scene(RenderWindow &window)
   :camera(window),
    ui(window),
    birds(0),
    record(0),
    isStarted(false),
    finalTime(0)
{
    instance = this;
}

void Scene::update(float deltaTime) {
    if (isStarted) {
        plane.update(deltaTime);
        camera.update(deltaTime);
        terrain.update(deltaTime);
        enemies.update(deltaTime);
        bonuses.update(deltaTime);
        ui.update(deltaTime);
        finalTime = get_time();
    } else {
        plane.update(deltaTime);
        camera.update(deltaTime);
        terrain.update(deltaTime);
        ui.update(deltaTime);
    }
    if (isGameOver()) {
        isStarted = false;
    }
}

void Scene::render(sf::RenderWindow &window) {
    window.clear(Color(0, 0, 255));
    if (isStarted) {
        camera.render(window);
        enemies.render(window);
        terrain.render(window);
        bonuses.render(window);
        plane.render(window);
        ui.render(window);
    } else {
        camera.render(window);
        terrain.render(window);
        if (isGameOver()) {
            ui.render(window);
        }
    }
}

void Scene::onTerrainSegmentCreated(const Segment &segment) {
    enemies.onTerrainSegmentCreated(segment);
}

void Scene::initScene() {
    plane.initScene();
    camera.initScene();
    terrain.initScene();
    enemies.initScene();
    bonuses.initScene();
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
    record = std::max(record, value);
}

void Scene::addBirds(int value) {
    birds += value;
    lastBirdAddTime = get_time();
}


int Scene::getFinalScore() {
    return birds * BIRD_COST + (int)(finalTime * SECOND_COST);
}

float Scene::getlastBirdTime() {
    return lastBirdAddTime;
}

int Scene::getBirds() {
    return birds;
}

bool Scene::isRocket(){
    return true;
}

float Scene::get_gas(){
    return plane.getFuel() / MAX_FUEL;
}

int Scene::getFuel() {
    return 5;
}

void Scene::start() {
    isStarted = true;
    initScene();
}

void Scene::setPlaneAngle(float angle) {
    angle = std::min(angle, 45.f);
    angle = std::max(angle, -45.f);
    plane.setAngle(angle);
}

