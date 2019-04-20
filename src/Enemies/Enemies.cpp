#include "precomp.h"
#include "Enemies.h"
#include "Balloon.h"
#include "Kamikaze.h"

Enemies::Enemies() = default;

void Enemies::initScene() {
    enemies.push_back(new Balloon());
    enemies.push_back(new Kamikaze());
    for(auto it: enemies) {
        it->initScene();
    }
}

void Enemies::update(float deltaTime) {
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
