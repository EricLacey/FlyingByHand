#pragma once
//#include "Animation.h"
//#include "Person.h"
#include "Item.h"
#include "Background.h"
#include <time.h>

class Game
{

public:
	void InitGame();
	void Update(float dT, float x, float y, bool g, bool p, int w, int h);
	void Draw();
	void LoadBGImages();
	void LoadObjectImages();
	bool checkCollision(int mX, int X, int mW, int W, int mY, int Y, int mH, int H);

private:

	ofTrueTypeFont font;

	int money;
	int food;

	bool nightTime;

	vector<ofImage> BGImages;
	vector<ofImage> ObImages;

	vector<Item> items;
	   	  
	float gameSpeed;

	Background m_b1;
	Background m_b2;
	Background m_b3;


	

};

