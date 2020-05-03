#include "stdafx.h"
#include "PointObject.h"

PointObject::PointObject(){
	pointX_pos_ = 0;
	pointY_pos_ = 0;
	point_height_ = 0;
	point_width_ = 0;
	point_status_ = 0;
	frame_ = 0;
}

PointObject::~PointObject(){

}

SDL_Rect PointObject::getRectFrame(){
	SDL_Rect rect;
	rect.x = pointX_pos_;
	rect.y = pointY_pos_;
	rect.w = point_width_;
	rect.h = point_height_;

	return rect;
}

bool PointObject::loadImage(std::string path,SDL_Renderer* screen){
	bool ret = BaseObject::loadImage(path,screen);
	if(ret==true){
		point_width_ = rect_.w;
		point_height_ = rect_.h;
	}

	return ret;
}

void PointObject::set_clips(){
	if(point_width_>0 && point_height_>0){
		//frame 0
		frame_clip_[0].x = 0;
		frame_clip_[0].y = 0;
		frame_clip_[0].w = point_width_;
		frame_clip_[0].h = point_height_;

	}
}

void PointObject::Show(SDL_Renderer* des){
	loadImage("map/19.png",des);

	rect_.x = pointX_pos_;
	rect_.y = pointY_pos_;

	SDL_Rect* current_clip = &frame_clip_[0];
	SDL_Rect renderQuad = {rect_.x,rect_.y,point_width_,point_height_};

	SDL_RenderCopy(des,p_object_,current_clip,&renderQuad);
}
