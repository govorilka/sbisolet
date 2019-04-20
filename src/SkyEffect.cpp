#include "precomp.h"
#include "SkyEffect.h"
#include "Scene.h"
#include "Camera.h"
SkyEffect::SkyEffect() {
    effectDuration = 0;
    activeTime=0;
    FloatRect rect = Camera::instance->getRect();
    effect.setSize(Vector2f(rect.width,rect.height));

}


void SkyEffect::startEffect(Color color,float duration) {
    activeTime=0;
    effect.setFillColor(color);
    effectDuration=duration;
}

void SkyEffect::update(float deltaTime) {
    activeTime+=deltaTime;
    FloatRect rect = Camera::instance->getRect();
    effect.setPosition(Vector2f(rect.left,rect.top));

}

void SkyEffect::render(RenderWindow &window) {
    if(activeTime < effectDuration) {
        window.draw(effect);
    }
}