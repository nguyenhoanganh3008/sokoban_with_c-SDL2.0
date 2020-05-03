#include "stdafx.h"
#include "game_map.h"

void GameMap::LoadMap(){
	FILE* fp = NULL;
	char* name;
	name = "map/map01.dat";
	fopen_s(&fp,name,"rb");
	if(fp==NULL){
		return;
	}

	for(int i=0;i<MAX_MAP_Y;i++){
		for(int j=0;j<MAX_MAP_X;j++){
			fscanf_s(fp,"%d",&game_map_.tile[i][j]);
		}
	}
	game_map_.start_x_ = 0;
	game_map_.start_y_ = 0;

	game_map_.file_name_ = name;
	fclose(fp);
}

void GameMap::LoadTiles(SDL_Renderer* screen){
	char file_img[30];
	FILE* fp=NULL;

	for(int i=0;i<TILE_SIZE;i++){
		sprintf_s(file_img,"map/%d.png",i);
		
		fopen_s(&fp,file_img,"rb");
		if(fp==NULL){
			continue;
		}

		fclose(fp);

		tile_mat[i].loadImage(file_img,screen);
	}
}

void GameMap::DrawMap(SDL_Renderer* screen){
	int x1=0;
	int x2=SCREEN_WIDTH;

	int y1=0;
	int y2=SCREEN_HEIGHT;

	for(int i=y1;i<y2;i+=TILE_SIZE){
		for(int j=x1;j<x2;j+=TILE_SIZE){
			int val = game_map_.tile[i/TILE_SIZE][j/TILE_SIZE];
			if(val>0){
				tile_mat[val].setRect(j,i);
				tile_mat[val].Render(screen);
			}
		}
	}

	
}

std::vector<SDL_Rect> GameMap::getPoints(){
	std::vector<SDL_Rect> listPoints;
	SDL_Rect rect;
	int x1=0;
	int x2=SCREEN_WIDTH;

	int y1=0;
	int y2=SCREEN_HEIGHT;
	for(int i=y1;i<y2;i+=TILE_SIZE){
		for(int j=x1;j<x2;j+=TILE_SIZE){
			int val = game_map_.tile[i/TILE_SIZE][j/TILE_SIZE];
			if(val==2){
				rect.x = j;
				rect.y = i;
				rect.w = j+TILE_SIZE;
				rect.h = j+TILE_SIZE;
				listPoints.push_back(rect);
			}
		}
	}
	return listPoints;
}