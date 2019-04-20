#pragma once
//CAMERA
static const float VIEW_SIZE_Y = 100;

static const float CAMERA_FOLLOW_DISTANCE = 10;

//PLANE
static const float PLANE_H_SPEED = 30;
static const float PLANE_V_SPEED = 20;

static const int PLANE_INIT_HP = 3;


static const float PLANE_MAX_HEIGHT = 75;

static const float PLANE_MIN_HEIGHT = 0;

static const float PLANE_SIZE = 10;

static const float PLANE_LOST_CONTROL_DURATION = 3;

static const float PLANE_FUEL_CONSUMPTION_TWO_HP_MUL = 1.5;
static const float PLANE_FUEL_CONSUMPTION_ONE_HP_MUL = 2;

static const float PLANE_MAX_FUEL = 100;

static const float PLANE_FUEL_DEC_UP = 5;
static const float PLANE_FUEL_DEC = 2;

static const float PLANE_FUEL_SIZE = 2;
static const float PLANE_FUEL_H_SPEED = 20;
static const float PLANE_FUEL_V_SPEED = 25;

static const float PLANE_FUEL_COOLDOWN = 0.2;



//Terrain
static const float TERRAIN_SEGMENT_WIDTH = 0.1;
static const float TERRAIN_SEGMENT_MAX_SHIFT = 0.05;
static const float TERRAIN_SEGMENT_MAX_HEIGHT = 0.4;
static const float TERRAIN_SEGMENT_MIN_HEIGHT = 0.2;


#define TERRAIN_COLOR Color::Green


//BONUS
static const float BONUS_SIZE = 15;
static const float BONUS_BIRD_SIZE = 17;
static const float BONUS_LIFE_SIZE = 10;
static const float BONUS_ROCKET_SIZE = 10;
static const float BONUS_CLOUD_SIZE = 15;
static const float BONUS_FUEL_SIZE = 10;

static const int BONUS_HEALING = 1;
static const int BONUS_TAKE_BIRD = 1;
static const int BONUS_FUEL_ADD = 100;
static const int BONUS_GODMODETIME = 50;

static const float GODMODE_SIZE = 20;


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
static const float UI_FUEL_OUTLINE_THICKNESS=1;
//UI COLORS
#define UI_BAR_COLOR Color(0,0,0,80)
#define UI_FUEL_COLOR Color(255,137,47)
#define UI_FUEL_BG_COLOR Color(0, 0, 255,0)
#define UI_FUEL_TEXT_COLOR Color(0,0,0)

//FINAL SCORE
static const int BIRD_COST = 100;
static const int SECOND_COST = 10;

//OTHER
static const float DELTA_TIME = 0.5;
static const float ANGLE_DELTA = 3;

//Enemies
static const float ENEMIES_KAMIKAZE_SIZE = 20;

static const float ENEMIES_KAMIKAZE_H_SPEED = 12.5;
static const float ENEMIES_KAMIKAZE_V_SPEED = 0;

static const int ENEMIES_KAMIKAZE_RELOAD_TIME = 7;
static const int ENEMIES_KAMIKAZE_MAX_RELOAD_EXTRA_TIME = 10;

static const int ENEMIES_KAMIKAZE_DAMAGE = 2;
static const int ENEMIES_KAMIKAZE_MIN_HEIGHT=30;
static const int ENEMIES_KAMIKAZE_MAX_EXTRA_HEIGHT = 60;

static const float ENEMIES_BALLOON_H_SIZE = 20;
static const float ENEMIES_BALLOON_V_SIZE = 20;

static const float ENEMIES_BALLOON_H_SPEED = 0;
static const float ENEMIES_BALLOON_V_SPEED = 5;

static const int ENEMIES_BALLOON_RELOAD_TIME = 7;
static const int ENEMIES_BALLOON_MAX_RELOAD_EXTRA_TIME = 10;

static const int ENEMIES_BALLOON_DAMAGE = 1;
static const int ENEMIES_BALLOON_MIN_HEIGHT = 30;
static const int ENEMIES_BALLOON_MAX_EXTRA_HEIGHT = 30;

static const float ENEMIES_CLOUD_H_SIZE = 30;
static const float ENEMIES_CLOUD_V_SIZE = 20;

static const float ENEMIES_LIGHTNING_H_SIZE = 7;
static const float ENEMIES_LIGHTNING_V_SIZE = 70;

static const int ENEMIES_CLOUD_RELOAD_TIME=5;
static const int ENEMIES_CLOUD_MAX_RELOAD_EXTRA_TIME = 3;

static const int ENEMIES_CLOUD_MIN_HEIGHT = 75;
static const int ENEMIES_CLOUD_MAX_EXTRA_HEIGHT = 20;

static const float ENEMIES_LIGHTNING_DURATION = 0.3;
static const float ENEMIES_LIGHTNING_PERIOD = 2.3;
static const int ENEMIES_CLOUD_DAMAGE = 1;
static const int ENEMIES_LIGHTNING_DAMAGE = 1;

//Effects
#define EFFECT_DAMAGE_COLOR Color(255,0,0,190)
#define EFFECT_LIGHTNING_COLOR Color(255,255,255,190)
static const float EFFECT_LIGHTNING_DURATION = 0.15;
static const float EFFECT_DAMAGE_DURATION = 0.3;

static const float EFFECT_LOST_CONTROL_DURATION=1;
static const int EFFECT_ROTATION_SPEED = 210;

