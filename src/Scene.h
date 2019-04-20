#pragma once

#include <Enemies/Enemies.h>
#include "Plane.h"
#include "UI.h"
#include "terrain.h"
#include "Camera.h"
#include "Bonuses.h"

#include "Enemies/Kamikaze.h"
#include "Enemies/Balloon.h"

class Scene {
    UI ui;
    Plane plane;
    Camera camera;
    Terrain terrain;

    Enemies enemies;
    Bonuses bonuses;

    Texture effectsTexture;

    int birds;
    int record;
    int rocketKits=0;

    Clock time;
    float finalTime;
    float lastBirdAddTime;


    bool isStarted;


    float lastRocketKitAddTime;

public:
    static Scene* instance;

    explicit Scene(RenderWindow& window);
    
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void onTerrainSegmentCreated(const Segment& segment);

    bool isGameOver();


    void start();

    void setPlaneAngle(float angle, bool force = false);
    void setArduinoMode();
    void setKeyboardMode();


    float getlastBirdTime();
    float getlastRocketKitTime();
    void addBirds(int value);

    int getBirds();

    int get_score();

    Texture& getEffectsTexture();

    void give_Rocket();
    int getFinalScore();
    int get_hp();
    float get_time();
    int get_record();
    void set_record(int value);
    bool isRocket();
    float get_gas();
    void del_Rocket();
    int getRocketKits();
    void addRocketKit(int value);
};
