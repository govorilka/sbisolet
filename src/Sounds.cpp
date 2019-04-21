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
    if(!buffer_bird.loadFromFile("bird_snd.wav")){
        throw std::runtime_error("Failed to load bird_snd.wav");
    }
    if(!buffer_jjj.loadFromFile("jjj.wav")){
        throw std::runtime_error("Failed to load jjj.wav");
    }
    if(!buffer_hp_fuel.loadFromFile("hp_fuel.wav")){
        throw std::runtime_error("Failed to load hp_fuel.wav");
    }

    thunder.setBuffer(buffer_thunder);
    thunder.setVolume(80.f);
    thunder.setPlayingOffset(seconds(4.f));

    uhh.setBuffer(buffer_uhh);
    uhh.setVolume(10000.f);

    new_record.setBuffer(buffer_new_record);
    new_record.setVolume(80.f);

    boom.setBuffer(buffer_big_boom);
    boom.setVolume(35.f);

    armor.setBuffer(buffer_armor);
    armor.setVolume(60.f);
    accelerate.setBuffer(buffer_accelerate);

    bird.setBuffer(buffer_bird);
    bird.setVolume(60.f);

    jjj.setBuffer(buffer_jjj);
    jjj.setVolume(65.f);
    jjj.setLoop(true);

    hp_fuel.setBuffer(buffer_hp_fuel);
    hp_fuel.setVolume(60.f);
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
void Sounds::play_bird() {
    bird.play();
}
void Sounds::play_jjj(){
    jjj.play();
}
void Sounds::stop_jjj(){
    jjj.stop();
}
void Sounds::set_jjj_volume(int value) {
    jjj.setVolume(value*1.f);
}
void Sounds::play_hp_fuel() {
    hp_fuel.play();
}