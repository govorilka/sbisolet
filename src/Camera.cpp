#include "precomp.h"
#include "Camera.h"
#include "Plane.h"
#include "Config.h"

void Camera::update(float deltaTime) {

}

void Camera::render(RenderWindow &window) {
    Vector2u windowSize = window.getSize();
    float aspectRatio = (float)windowSize.x / windowSize.y;
    Vector2f planePosition = Plane::instance->getPosition();
    Vector2f cameraPosition(planePosition.x - CAMERA_FOLLOW_DISTANCE, VIEW_SIZE_Y);
    Vector2f size(VIEW_SIZE_Y * aspectRatio, VIEW_SIZE_Y);
    FloatRect rect(cameraPosition, size);
    View view(rect);
    window.setView(view);
}
