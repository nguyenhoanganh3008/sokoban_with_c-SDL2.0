
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<windows.h>
#include<string>
#include<vector>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// screen

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

const int RENDER_DRAW_COLOR = 0Xff;

// fps game
const int FRAME_PER_SECOND = 25;

#define BLANK_TILE 0
#define POINT_TILE 10
#define BRICK_TILE 2
#define SPEED_PLAYER 4

#define TILE_SIZE  64

#define MAX_MAP_X  10
#define MAX_MAP_Y  10

typedef struct Input{
	int left_;
	int right_;
	int up_;
	int down_;
};

typedef struct Map
{
	int start_x_;
	int start_y_;

	int tile[MAX_MAP_Y][MAX_MAP_X];
	char* file_name_;
};

namespace SDLCommonFunc{
	bool CheckCollision(const SDL_Rect& object1,const SDL_Rect& object2);
	int CheckCollisonPos(const SDL_Rect& object1,const SDL_Rect& object2);
	bool Crate_Point(const SDL_Rect& object1,const SDL_Rect& object2);
}
#endif