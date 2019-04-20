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
    if(!effectsTexture.loadFromFile("effects.png")){
        throw std::runtime_error("Failed to load effects.png");
    }
    instance = this;

}

Texture& Scene::getEffectsTexture() {
    return effectsTexture;
}

SkyEffect& Scene::getSkyEffect(){
    return skyEffect;
}

void Scene::update(float deltaTime) {
    if (isStarted) {
        plane.update(deltaTime);
        camera.update(deltaTime);
        terrain.update(deltaTime);
        enemies.update(deltaTime);
        bonuses.update(deltaTime);
        skyEffect.update(deltaTime);
        ui.update(deltaTime);
        finalTime = get_time();
    } else {
        plane.update(deltaTime);
        camera.update(deltaTime);
        terrain.update(deltaTime);
        skyEffect.update(deltaTime);
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
        skyEffect.render(window);
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
    bonuses.onTerrainSegmentCreated(segment);
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

void Scene::addRocketKit(int value){
    rocketKits+=value;
    lastRocketKitAddTime=get_time();
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
    return (getRocketKits()>0);
}

float Scene::get_gas(){
    return plane.getFuel() / PLANE_MAX_FUEL;
}

int Scene::getRocketKits() {
    return rocketKits;
}

float Scene::getlastRocketKitTime() {
    return lastRocketKitAddTime;
}

void Scene::start() {
    isStarted = true;
    initScene();
}

void Scene::setPlaneAngle(float angle, bool force) {
    auto normalizeAngle = std::min(angle, 45.f);
    normalizeAngle = std::max(normalizeAngle, -45.f);
    std::cout << angle << " -> " << normalizeAngle<< std::endl;
    plane.setAngle(normalizeAngle, force);
}

void Scene::setArduinoMode() {
    plane.setControlMode(false);
}

void Scene::setKeyboardMode() {
    plane.setControlMode(true);
}

void Scene::del_Rocket(){
    rocketKits=0;
}
