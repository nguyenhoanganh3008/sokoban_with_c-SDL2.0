
#include "stdafx.h"
#include "CommonFunc.h"

int SDLCommonFunc::CheckCollisonPos(const SDL_Rect& object1,const SDL_Rect& object2){
  int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;
 
  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;

  if(left_a==right_b){
	 if((top_a > top_b && top_a < bottom_b)){
		  return 1;
	  }
	  if(top_a==top_b && bottom_a == bottom_b){
		  return 1;
	  }
	  if((bottom_a > top_b && bottom_a < bottom_b)){
		  return 1;
	  }
  }
  if(left_b==right_a){
	  if((top_a > top_b && top_a < bottom_b)){
		  return 2;
	  }
	  if(top_a==top_b && bottom_a == bottom_b){
		  return 2;
	  }
	  if((bottom_a > top_b && bottom_a < bottom_b)){
		  return 2;
	  }
  }
   if(bottom_a==top_b){
	   if((left_a > left_b && left_a < right_b)){
		  return 3;
	  }
	  if(left_a==left_b && right_a == right_b){
		  return 3;
	  }
	  if((right_a > left_b && right_a < right_b)){
		  return 3;
	  }
  }
   if(top_a==bottom_b){
	 if((left_a > left_b && left_a < right_b)){
		  return 4;
	  }
	  if(left_a==left_b && right_a == right_b){
		  return 4;
	  }
	  if((right_a > left_b && right_a < right_b)){
		  return 4;
	  }
  }
 

}

bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1,const SDL_Rect& object2){
  int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;
 
  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;
 if(left_a==right_b){
	 if((top_a > top_b && top_a < bottom_b)){
		 return true;
	  }
	  if(top_a==top_b && bottom_a == bottom_b){
		  return true;
	  }
	  if((bottom_a > top_b && bottom_a < bottom_b)){
		  return true;
	  }
  }
  if(left_b==right_a){
	  if((top_a > top_b && top_a < bottom_b)){
		  return true;
	  }
	  if(top_a==top_b && bottom_a == bottom_b){
		  return true;
	  }
	  if((bottom_a > top_b && bottom_a < bottom_b)){
		  return true;
	  }
  }
   if(bottom_a==top_b){
	   if((left_a > left_b && left_a < right_b)){
		   return true;
	  }
	  if(left_a==left_b && right_a == right_b){
		  return true;
	  }
	  if((right_a > left_b && right_a < right_b)){
		  return true;
	  }
  }
   if(top_a==bottom_b){
	 if((left_a > left_b && left_a < right_b)){
		 return true;
	  }
	  if(left_a==left_b && right_a == right_b){
		  return true;
	  }
	  if((right_a > left_b && right_a < right_b)){
		  return true;
	  }
  }
  
  return false;
}

bool SDLCommonFunc::Crate_Point(const SDL_Rect& object1,const SDL_Rect& object2){
  int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;
 
  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;

  if(left_a == left_b && right_a == right_b){
	  if(bottom_a > top_b+50 && bottom_a < bottom_b){
		  return true;
	  }
	  if(top_a > top_b && top_a < bottom_b-50){
		  return true;
	  }
  }
  if(top_a == top_b && bottom_a == bottom_b){
	  if(left_a > left_b && left_a < right_b-50){
		  return true;
	  }
	  if(right_a < right_b && right_a > left_b+50){
		  return true;
	  }
  }
  return false;
}