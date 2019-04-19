#pragma once

class Camera {
    FloatRect viewRect;
    RenderWindow& renderWindow;

public:
    static Camera* instance;

    explicit Camera(RenderWindow& window);

    const FloatRect& getRect();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
};