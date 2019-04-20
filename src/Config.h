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

static const float LOST_CONTROL_DURATION=3;


//Terrain
static const float TERRAIN_SEGMENT_WIDTH = 0.1;
static const float TERRAIN_SEGMENT_MAX_SHIFT = 0.05;
static const float TERRAIN_SEGMENT_MAX_HEIGHT = 0.4;
static const float TERRAIN_SEGMENT_MIN_HEIGHT = 0.2;


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
static const float UI_TOP_BAR_SIZE=180;
static const float UI_HEART_SIZE=100;
static const float UI_BIRD_SIZE = 150;
static const float UI_ROCKETKIT_WIDTH=93;//from 0 to 100(15+ required)
static const float UI_HEART_DIST=30;
static const float UI_HEART_WIDTH=100;


#define UI_BAR_COLOR Color(0,0,0,80)

//FINAL SCORE
static const int BIRD_COST = 100;
static const int SECOND_COST = 10;

//OTHER
static const float DELTA_TIME = 0.5;
static const float ANGLE_DELTA = 3;

//Enemies
static const float ENEMIES_KAMIKAZE_SIZE = 20;

static const float ENEMIES_KAMIKAZE_H_SPEED = 12.5;
static const float ENEMIES_KAMIKAZE_V_SPEED = 10;

static const int ENEMIES_KAMIKAZE_RELOAD_TIME = 20;

static const int ENEMIES_KAMIKAZE_DAMAGE = 2;
static const int ENEMIES_KAMIKAZE_MIN_HEIGHT=30;

static const float ENEMIES_BALLOON_H_SIZE = 20;
static const float ENEMIES_BALLOON_V_SIZE = 20;

static const float ENEMIES_BALLOON_H_SPEED = 0;
static const float ENEMIES_BALLOON_V_SPEED = 5;

static const int ENEMIES_BALLOON_RELOAD_TIME = 20;

static const int ENEMIES_BALLOON_DAMAGE = 1;
static const int ENEMIES_BALLOON_MIN_HEIGHT = 30;

static const float ENEMIES_CLOUD_H_SIZE = 30;
static const float ENEMIES_CLOUD_V_SIZE = 20;

static const float ENEMIES_LIGHTNING_H_SIZE = 7;
static const float ENEMIES_LIGHTNING_V_SIZE = 70;

static const int ENEMIES_CLOUD_RELOAD_TIME=7;

static const int ENEMIES_CLOUD_MIN_HEIGHT = 75;
static const float ENEMIES_LIGHTNING_DURATION = 0.3;
static const float ENEMIES_LIGHTNING_PERIOD = 1;
static const int ENEMIES_CLOUD_DAMAGE = 1;
static const int ENEMIES_LIGHTNING_DAMAGE = 1;

