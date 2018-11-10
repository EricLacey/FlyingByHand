#pragma once
#include "Animation.h"
#include "Person.h"
#include "Item.h"
#include "Background.h"
#include "Collision.h"

class Game
{

public:
	Game()
	{
		InitGame();
	}

private:
	Background* m_b1 = new Background();
	Background* m_b2 = new Background();
	Background* m_b3 = new Background();

	Item* m_burger = new Item();
	Item* m_poutine = new Item();
	Item* m_hotdog = new Item();
	Item* m_coin = new Item();

	//Background m_b1;
	//Background m_b2;
	//Background m_b3;

	//Item burger;
	//Item hotdog;
	//Item poutine;
	//Item coin;

	void InitGame() {};
	void Update() {};
	void Draw() {};

};

