#include "precomp.h"
#include "Camera.h"
#include "Plane.h"
#include "Config.h"

Camera* Camera::instance = nullptr;

Camera::Camera(RenderWindow& window)
    :renderWindow(window)
{
    instance = this;

    Vector2u windowSize = renderWindow.getSize();
    float aspectRatio = (float) windowSize.x / windowSize.y;
    Vector2f cameraPosition(-CAMERA_FOLLOW_DISTANCE, VIEW_SIZE_Y);
    Vector2f size(VIEW_SIZE_Y * aspectRatio, -VIEW_SIZE_Y);
    viewRect = FloatRect(cameraPosition, size);
}

void Camera::initScene() {
    followPlane();
}

void Camera::update(float deltaTime) {
    followPlane();
}

void Camera::render(RenderWindow &window) {
    View view(viewRect);
    window.setView(view);
}

const FloatRect &Camera::getRect() {
    return viewRect;
}

void Camera::followPlane() {
    viewRect.left = Plane::instance->getPosition().x - CAMERA_FOLLOW_DISTANCE;
}
