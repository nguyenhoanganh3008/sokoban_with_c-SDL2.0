#include "stdafx.h"
#include "CrateObject.h"
#include "CommonFunc.h"

CrateObject::CrateObject(){
	crateX_val_ = 0;
	crateY_val_ = 0;
	crateX_pos_ = 0;
	crateY_pos_ = 0;

	crate_width_ = 0;
	crate_height_ = 0;
	crate_status_ = 0;
	frame_ = 0;
}

CrateObject::~CrateObject(){

}

SDL_Rect CrateObject::getRectFrame(){
	SDL_Rect rect;
	rect.x = rect_.x;
	rect.y = rect_.y;
	rect.w = crate_width_;
	rect.h = crate_height_;

	return rect;
}

bool CrateObject::loadImage(std::string path,SDL_Renderer* screen){
	bool ret = BaseObject::loadImage(path,screen);
	if(ret==true){
		crate_width_ = rect_.w;
		crate_height_ = rect_.h;
	}

	return ret;
}

void CrateObject::set_clips(){
	if(crate_width_>0 && crate_height_>0){
		//frame 0
		frame_clip_[0].x = 0;
		frame_clip_[0].y = 0;
		frame_clip_[0].w = crate_width_;
		frame_clip_[0].h = crate_height_;


	}
}

void CrateObject::Show(SDL_Renderer* des){
	if(crate_status_ == 1){
		loadImage("map/6.png",des);
	}

	rect_.x = crateX_pos_;
	rect_.y = crateY_pos_;

	SDL_Rect* current_clip = &frame_clip_[0];
	SDL_Rect renderQuad = {rect_.x,rect_.y,crate_width_,crate_height_};

	SDL_RenderCopy(des,p_object_,current_clip,&renderQuad);
}

void CrateObject::Move(Map& map_data){
	crateX_val_= 0;
	crateY_val_= 0;


	CheckToMap(map_data);
}


void CrateObject::CheckToMap(Map& map_data){


	int x1=0;
	int x2=0;

	int y1=0;
	int y2=0;

	//Check horizontal
	int height_min = crate_height_ < TILE_SIZE ? crate_height_ : TILE_SIZE;
	x1 = (crateX_pos_ + crateX_val_)/TILE_SIZE;
	x2 = (crateX_pos_ + crateX_val_ + crate_width_ - 1)/TILE_SIZE;

	y1 = (crateY_pos_)/TILE_SIZE;
	y2 = (crateY_pos_ + height_min - 1)/TILE_SIZE;

	if(x1>=0 && x2 < MAX_MAP_X && y1>=0 && y2 < MAX_MAP_Y){
		if(crateX_val_>0){
			if(map_data.tile[y1][x2] != BLANK_TILE || map_data.tile[y2][x2] != BLANK_TILE){
				crateX_pos_ = x2*TILE_SIZE;
				crateX_pos_ -= (crate_width_ + 1);
				crateX_val_= 0;
			}
		}
		else if(crateX_val_<0){
			if(map_data.tile[y1][x1] != BLANK_TILE || map_data.tile[y2][x1] != BLANK_TILE){
				crateX_pos_ = (x1+1)*TILE_SIZE;
				crateX_val_ = 0;
			}
		}
	}

	//Check vertical
	int width_min = crate_width_ < TILE_SIZE ? crate_width_ : TILE_SIZE;
	x1 = (crateX_pos_)/TILE_SIZE;
	x2 = (crateX_pos_+width_min)/TILE_SIZE;

	y1 = (crateY_pos_+crateY_val_)/TILE_SIZE;
	y2 = (crateY_pos_+crateY_val_+crate_height_-1)/TILE_SIZE;

	if(x1>=0 && x2 < MAX_MAP_X && y1>=0 && y2 < MAX_MAP_Y){
		if(crateY_val_>0){
			if(map_data.tile[y2][x1] != BLANK_TILE || map_data.tile[y2][x2] != BLANK_TILE){
				crateY_pos_ = y2*TILE_SIZE;
				crateY_pos_ -= (crate_height_ + 1);
				crateY_val_= 0;
			}
		}
		else if(crateY_val_<0){
			if(map_data.tile[y1][x1] != BLANK_TILE || map_data.tile[y1][x2] != BLANK_TILE){
				crateY_pos_ = (y1+1)*TILE_SIZE;
				crateY_val_ = 0;
			}
		}
	}
	
	crateX_pos_+=crateX_val_;
	crateY_pos_+=crateY_val_;

}
