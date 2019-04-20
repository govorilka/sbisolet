#include "precomp.h"
#include <Scene.h>
#include "Enemies.h"
#include "Balloon.h"
#include "Kamikaze.h"
#include "Cloud.h"
#include <cfloat>
#include "Scene.h"

Enemies* Enemies::instance = nullptr;
Enemies::Enemies() = default;

void Enemies::initScene() {

}

void Enemies::update(float deltaTime) {
    lastKamikazeTime -= deltaTime;
    lastBalloonTime -= deltaTime;
    lastCloudTime -=deltaTime;
    for(auto it = enemies.begin(); it != enemies.end(); it++) {
        (*it)->update(deltaTime);
        if ((*it)->isToBeRemoved()) {
            auto remove = it;
            it--;
            delete (*remove);
            enemies.erase(remove);
        }
    }
}

void Enemies::render(RenderWindow &window) {
    for(auto it: enemies) {
        it->render(window);
    }
}

void Enemies::onTerrainSegmentCreated(const Segment &segment) {
    if (lastKamikazeTime < 0) {
        enemies.push_back(new Kamikaze(segment.second.x, ENEMIES_KAMIKAZE_MIN_HEIGHT + rand() % 60));
        lastKamikazeTime = ENEMIES_KAMIKAZE_RELOAD_TIME + (float)(rand() % 1000) / 100;
    }
    if (lastBalloonTime < 0) {
        enemies.push_back(new Balloon(segment.second.x, ENEMIES_BALLOON_MIN_HEIGHT + rand() % 20));
        lastBalloonTime = ENEMIES_BALLOON_RELOAD_TIME + (float)(rand() % 1000) / 100;
    }
    if (lastCloudTime < 0) {
        enemies.push_back(new Cloud(segment.second.x, ENEMIES_CLOUD_MIN_HEIGHT + rand() % 20));
        lastCloudTime = ENEMIES_CLOUD_RELOAD_TIME + (float)(rand() % 1000) / 100;
    }
}
