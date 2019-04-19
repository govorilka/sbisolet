#include "precomp.h"
#include "Scene.h"

void Scene::update(float deltaTime) {
    terrain.update(deltaTime);
    plane.update(deltaTime);
    ui.update(deltaTime);
}

void Scene::render(sf::RenderWindow &window) {
    window.clear(Color(0, 0, 255));
    terrain.render(window);
    plane.render(window);
    ui.render(window);
}
