#ifndef POINT_OBJECT_H_
#define POINT_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class PointObject : public BaseObject{
public: 
	PointObject();
	~PointObject();
	bool loadImage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	SDL_Rect getRectFrame();
	void set_x_pos(const float& xPos){pointX_pos_ = xPos;}
	void set_y_pos(const float& yPos){pointY_pos_ = yPos;}
	float get_x_pos() const {return pointX_pos_;}
	float get_y_pos() const {return pointY_pos_;}
	void set_clips();

private:

	float pointX_pos_;
	float pointY_pos_;

	int point_width_;
	int point_height_;

	int point_status_;
	SDL_Rect frame_clip_[1];
	int frame_;
};


#endif