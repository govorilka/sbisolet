#include <iostream>
#include <cfloat>
#include "precomp.h"
#include "Scene.h"

#include "Sounds.h"

Sounds* Sounds::instance = nullptr;

Sounds::Sounds(){
    instance = this;

    if (!buffer_uhh.loadFromFile("uhh.wav")){
        throw std::runtime_error("Failed to load uhh.wav");
    }

    if(!buffer_thunder.loadFromFile("thunder.wav")){
        throw std::runtime_error("Failed to load thunder.wav");
    }
    if(!buffer_new_record.loadFromFile("new_record.wav")){
        throw std::runtime_error("Failed to load new_record.wav");
    }
    if(!buffer_big_boom.loadFromFile("big_bada_boom.wav")){
        throw std::runtime_error("Failed to load big_bada_boom.wav");
    }
    if(!buffer_armor.loadFromFile("armor.wav")){
        throw std::runtime_error("Failed to load armor.wav");
    }
    if(!buffer_accelerate.loadFromFile("accelerate.wav")){
        throw std::runtime_error("Failed to load accelerate.wav");
    }

    thunder.setBuffer(buffer_thunder);
    thunder.setVolume(5000.f);
    thunder.setPlayingOffset(seconds(4.f));

    uhh.setBuffer(buffer_uhh);
    uhh.setVolume(10000.f);

    new_record.setBuffer(buffer_new_record);
    new_record.setVolume(4000.f);

    boom.setBuffer(buffer_big_boom);
    boom.setVolume(10000.f);

    armor.setBuffer(buffer_armor);
    accelerate.setBuffer(buffer_accelerate);
}


void Sounds::update(float deltaTime) {}

void Sounds::render() {}

void Sounds::play_uhh(){
    uhh.play();
}

void Sounds::play_thunder(){
    thunder.play();
}

void Sounds::play_new_record() {
    new_record.play();
}

void Sounds::play_big_boom() {
    boom.play();
}

void Sounds::play_armor() {
    armor.play();
}
void Sounds::play_accelerate() {
    accelerate.play();
}