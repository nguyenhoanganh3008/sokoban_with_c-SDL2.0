#ifndef CRATE_OBJECT_H_
#define CRATE_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class CrateObject : public BaseObject
{
public:
	CrateObject();
	~CrateObject();

	bool loadImage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void set_x_val(const float& xVal){crateX_val_ = xVal;}
	void set_y_val(const float& yVal){crateY_val_ = yVal;}

	void set_x_pos(const float& xPos){crateX_pos_ = xPos;}
	void set_y_pos(const float& yPos){crateY_pos_ = yPos;}
	float get_x_pos() const {return crateX_pos_;}
	float get_y_pos() const {return crateY_pos_;}

	SDL_Rect getRectFrame();
	int get_width_frame() const {return crate_width_;}
	int get_height_frame() const {return crate_height_;}
	void set_clips();
	void Move(Map& Cmap);
	void CheckToMap(Map& Cmap);
	int getCrateStatus() const {return crate_status_;}
	void setCrateStatus(const int& crateSta) {crate_status_ = crateSta;}


private:
	float crateX_val_;
	float crateY_val_;

	float crateX_pos_;
	float crateY_pos_;

	int crate_width_;
	int crate_height_;

	int crate_status_;
	SDL_Rect frame_clip_[1];
	int frame_;
};



#endif