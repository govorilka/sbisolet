#include "precomp.h"
#include "Scene.h"

void Scene::update(float deltaTime) {
    camera.update(deltaTime);
    terrain.update(deltaTime);
    plane.update(deltaTime);
    ui.update(deltaTime);
}

void Scene::render(sf::RenderWindow &window) {
    window.clear(Color(0, 0, 255));
    camera.render(window);
    terrain.render(window);
    plane.render(window);
    ui.render(window);
}
