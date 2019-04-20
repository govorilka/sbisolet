#pragma once
//CAMERA
static const float VIEW_SIZE_Y = 100;

static const float CAMERA_FOLLOW_DISTANCE = 10;

//PLANE
static const float PLANE_H_SPEED = 30;
static const float PLANE_V_SPEED = 20;

static const int INIT_PLANE_HP = 3;

static const float MAX_PLANE_HEIGHT = 75;
static const float MIN_PLANE_HEIGHT = 25;

static const float PLANE_SIZE = 10;

static const float MAX_FUEL = 100;

static const float ONE_HP_MUL = 2;
static const float FUEL_DEC_UP = 5;
static const float FUEL_DEC = 2;

//KAMIKAZE
static const float KAMIKAZE_SIZE = 10;

static const float KAMIKAZE_H_SPEED = 12.5;
static const float KAMIKAZE_V_SPEED = 10;

static const int KAMIKAZE_DAMAGE = 2;

static const float KAMIKAZE_RELOAD_TIME = 5;

//BALLOON
static const float BALLOON_H_SIZE = 10;
static const float BALLOON_V_SIZE = 20;

static const float BALLOON_H_SPEED = 0;
static const float BALLOON_V_SPEED = 5;

static const int BALLOON_DAMAGE = 1;

static const float BALLOON_RELOAD_TIME = 4;

//TERRAIN
static const float SEGMENT_WIDTH = 0.1;
static const float SEGMENT_MAX_SHIFT = 0.05;
static const float SEGMENT_MAX_HEIGHT = 0.4;

static const float SEGMENT_MIN_HEIGHT = 0.2;

#define TERRAIN_COLOR Color::Green

//BONUS
static const float BONUS_SIZE = 15;

//UI
static const float UI_BAR_HEIGHT=7;//low=high))))
static const float UI_GAS_WIDTH=400;
static const float UI_GAS_HEIGHT=50;

static const float UI_BIRD_MAX_TIME=0.25;
static const float UI_BIRD_MAX_SCALE=1.25;
static const float UI_KIT_SIZE=100;

static const float UI_BIRD_SIZE = 100;
#define UI_BAR_COLOR Color(0,0,0,80)

//FINAL SCORE
static const int BIRD_COST = 100;
static const int SECOND_COST = 10;

//OTHER
static const float DELTA_TIME = 0.5;
