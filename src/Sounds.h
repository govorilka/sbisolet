#pragma once

#include <Enemies/Enemies.h>
#include "Plane.h"
#include "UI.h"
#include "terrain.h"
#include "Camera.h"
#include "Bonuses.h"

#include "Enemies/Kamikaze.h"
#include "Enemies/Balloon.h"

class Sounds {
    SoundBuffer buffer_uhh;
    SoundBuffer buffer_thunder;
    SoundBuffer buffer_new_record;
    SoundBuffer buffer_big_boom;
    SoundBuffer buffer_armor;
    SoundBuffer buffer_accelerate;
    Sound uhh;
    Sound thunder;
    Sound new_record;
    Sound boom;
    Sound armor;
    Sound accelerate;
public:
    static Sounds* instance;
    explicit Sounds();
    void update(float deltaTime);
    void render();
    void play_uhh();
    void play_thunder();
    void play_new_record();
    void play_big_boom();
    void play_armor();
    void play_accelerate();
};



