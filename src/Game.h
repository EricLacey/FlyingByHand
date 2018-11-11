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
	void Update(float dT);
	void Draw();
	void LoadBGImages();
	void LoadObjectImages();
	bool checkCollision(int mX, int X, int mW, int W, int mY, int Y, int mH, int H);

private:

	vector<ofImage> BGImages;
	vector<ofImage> ObImages;

	vector<Item> items;
	   	  
	float gameSpeed;

	Background m_b1;
	Background m_b2;
	Background m_b3;

//	Item* m_burger = new Item();
	//Item* m_poutine = new Item();
	//Item* m_hotdog = new Item();
	//Item* m_coin = new Item();

	//Background m_b1;
	//Background m_b2;
	//Background m_b3;

	//Item burger;
	//Item hotdog;
	//Item poutine;
	//Item coin;

	

};

