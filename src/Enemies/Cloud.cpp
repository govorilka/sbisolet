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
    isPushed=false;
    damaged = false;
    last_shot_time = FLT_MAX;
    isAlive = true;


}

void Cloud::initScene() {

}

void Cloud::startLightning(){
    SkyEffect effect = Scene::instance->getSkyEffect();
    if(effect.activeTime > effect.effectDuration)
        Scene::instance->getSkyEffect().startEffect(EFFECT_LIGHTNING_COLOR,EFFECT_LIGHTNING_DURATION);
    last_shot_time = Scene::instance->get_time();
    Sounds::instance->play_thunder();
    damaged = false;
}

bool Cloud::isLightningActive() {
    return (Scene::instance->get_time() < last_shot_time + ENEMIES_LIGHTNING_DURATION) && (Scene::instance->get_time() > last_shot_time);
}

bool Cloud::isReadyToShoot(){
    return (last_shot_time==FLT_MAX)||(Scene::instance->get_time() > last_shot_time + ENEMIES_LIGHTNING_PERIOD);
}


void Cloud::update(float deltaTime) {

    if (cloud.getGlobalBounds().intersects(Plane::instance->getGlobalBounds()) && Plane::instance->lostControlTime<=0 && !isPushed) {

        Plane::instance->lostControlTime = EFFECT_LOST_CONTROL_DURATION;
        isPushed=true;
        
    }

    if(isReadyToShoot()){
        startLightning();
    }

    if(isLightningActive() && !damaged && lightning.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())){
        damaged = true;
        Plane::instance->addHP(-ENEMIES_LIGHTNING_DAMAGE);
    }

    if (cloud.getPosition().x < Camera::instance->getRect().left-50) {
        isAlive = false;
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


