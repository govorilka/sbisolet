#include "precomp.h"
#include <Scene.h>
#include "Enemies.h"
#include "Balloon.h"
#include "Kamikaze.h"
#include "Cloud.h"
#include <cfloat>
#include <Utils.h>
#include "Scene.h"

Enemies* Enemies::instance = nullptr;
Enemies::Enemies() = default;

void Enemies::initScene() {
    enemies.clear();
    lastBalloonTime = ENEMIES_BALLOON_RELOAD_TIME + (float)(Utils::getRandomNumber(0, 500)) / 100;
    lastKamikazeTime = ENEMIES_KAMIKAZE_RELOAD_TIME + (float)(Utils::getRandomNumber(0, 100)) / 100;
    lastCloudTime = ENEMIES_CLOUD_RELOAD_TIME + (float)(Utils::getRandomNumber(0, 200)) / 100;
    lastCloudTime = 5;
    lastBalloonTime = 5;
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
        enemies.push_back(new Kamikaze(segment.first.x, ENEMIES_KAMIKAZE_MIN_HEIGHT +
                                                        Utils::getRandomNumber(0, ENEMIES_KAMIKAZE_MAX_EXTRA_HEIGHT)));
        lastKamikazeTime = ENEMIES_KAMIKAZE_RELOAD_TIME + (float)(Utils::getRandomNumber(0, ENEMIES_KAMIKAZE_MAX_RELOAD_EXTRA_TIME));
    }
    if (lastBalloonTime < 0) {
        enemies.push_back(new Balloon(segment.first.x, ENEMIES_BALLOON_MIN_HEIGHT +
                                                       Utils::getRandomNumber(0, ENEMIES_BALLOON_MAX_EXTRA_HEIGHT)));
        lastBalloonTime = ENEMIES_BALLOON_RELOAD_TIME + (float)(Utils::getRandomNumber(0, ENEMIES_BALLOON_MAX_RELOAD_EXTRA_TIME));
    }
    if (lastCloudTime < 0) {
        enemies.push_back(new Cloud(segment.first.x, ENEMIES_CLOUD_MIN_HEIGHT +
                                                     Utils::getRandomNumber(0, ENEMIES_CLOUD_MAX_EXTRA_HEIGHT)));
        lastCloudTime = ENEMIES_CLOUD_RELOAD_TIME + (float)(Utils::getRandomNumber(0, ENEMIES_CLOUD_MAX_RELOAD_EXTRA_TIME)) ;
    }
    if (std::abs(lastBalloonTime - lastCloudTime) < DELTA_TIME)
        lastCloudTime += 6 * DELTA_TIME;
}
