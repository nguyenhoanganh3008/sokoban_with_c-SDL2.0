#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class MainObject : public BaseObject{
public:
	MainObject();
	~MainObject();

	enum WalkType{
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
		WALK_UP = 2,
		WALK_DOWN =3
	};

	bool loadImage(std::string path,SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandelInputAction(SDL_Event events,SDL_Renderer* screen);
	void Set_clip();
	SDL_Rect getRectFrame();
	void DoPlayer(Map& map_data);
	void CheckToMap(Map& map_data);	
	int getX_val() const {return x_val_;}
	int getY_val() const {return y_val_;}
	void setPos(const float& a,const float& b){
		x_pos_=a;
		y_pos_=b;
	}
	bool player_move_left();
	bool player_move_right();
	bool player_move_up();
	bool player_move_down();
private:
	float x_val_;
	float y_val_;

	float x_pos_;
	float y_pos_;

	int width_frame_;
	int height_frame_;

	SDL_Rect frame_clip_[6];

	Input input_type_;
	int frame_;
	int status_;
};


#endif