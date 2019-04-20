#include "precomp.h"
#include "Cloud.h"
#include "Plane.h"
#include "Scene.h"
#include <cfloat>

Cloud::Cloud(float xPos,float yPos) {

    cloud.setPosition(xPos,yPos);
    cloud.setTexture(Scene::instance->getEffectsTexture());
    cloud.setTextureRect(IntRect(256*2,256*2,256,256));
    cloud.setOrigin(128, 128);
    cloud.setScale(ENEMIES_CLOUD_H_SIZE / 256, -ENEMIES_CLOUD_V_SIZE / 256);

    lightning.setPosition(xPos,yPos - cloud.getGlobalBounds().height*1.7);
    lightning.setTexture(Scene::instance->getEffectsTexture());
    lightning.setTextureRect(IntRect(0,256*3,256,256));
    lightning.setOrigin(128, 128);
    lightning.setScale(ENEMIES_LIGHTNING_H_SIZE / 256, -ENEMIES_LIGHTNING_V_SIZE / 256);

    damaged = 0;
    last_shot_time = FLT_MAX;
    isAlive = true;
}

void Cloud::initScene() {

}

void Cloud::startLightning(){
    last_shot_time = Scene::instance->get_time();
    damaged = 0;
}

bool Cloud::isLightningActive() {
    return (Scene::instance->get_time() < last_shot_time + ENEMIES_LIGHTNING_DURATION) && (Scene::instance->get_time() > last_shot_time);
}

bool Cloud::isReadyToShoot(){
    return (last_shot_time==FLT_MAX)||(Scene::instance->get_time() > last_shot_time + ENEMIES_LIGHTNING_PERIOD);
}


void Cloud::update(float deltaTime) {

    cloud.setPosition(cloud.getPosition() + velocity * deltaTime);
    lightning.setPosition(lightning.getPosition() + velocity * deltaTime);
    if (cloud.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())) {
        Plane::instance->lostControlTime = LOST_CONTROL_DURATION;
    }

    if(isReadyToShoot()){
        startLightning();
    }

    if(isLightningActive() && !damaged && lightning.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())){
        damaged = 1;
        Plane::instance->addHP(-ENEMIES_LIGHTNING_DAMAGE);

    }

}

void Cloud::render(RenderWindow &window) {
    window.draw(cloud);
    if(isLightningActive()){
        window.draw(lightning);
    }
}

bool Cloud::isToBeRemoved() {
    return !isAlive;
}


