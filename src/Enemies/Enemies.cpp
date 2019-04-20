#include "precomp.h"
#include <Scene.h>
#include "Enemies.h"
#include "Balloon.h"
#include "Kamikaze.h"

Enemies::Enemies() = default;

void Enemies::initScene() {
}

void Enemies::update(float deltaTime) {
    lastKamikazeTime -= deltaTime;
    lastBalloonTime -= deltaTime;
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
        enemies.push_back(new Kamikaze(segment.second.x, 30 + rand() % 60));
        lastKamikazeTime = KAMIKAZE_RELOAD_TIME + (float)(rand() % 1000) / 100;
    }
    if (lastBalloonTime < 0) {
        enemies.push_back(new Balloon(segment.second.x, 30 + rand() % 20));
        lastBalloonTime = BALLOON_RELOAD_TIME + (float)(rand() % 1000) / 100;
    }
}
