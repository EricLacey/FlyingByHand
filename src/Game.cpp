#include "Game.h"

void Game::InitGame()
{
	srand(time(NULL));

	font.loadFont("coolvetica.ttf", 30, true, false, true, 0.1);

	money = 0;
	food = 0;

	nightTime = rand() % 2;

	LoadBGImages();
	LoadObjectImages();	

	gameSpeed = 500.0f;
	m_b1.setOrder(1);
	m_b2.setOrder(2);
	m_b3.setOrder(3);
	m_b1.setX(0.0);
	m_b2.setX(0.0);
	m_b3.setX(0.0);

	m_b1.setY(0.0);
	m_b2.setY(0.0 - m_b2.getImage().getHeight() + 245);
	m_b3.setY(0.0 - m_b2.getImage().getHeight() - m_b3.getImage().getHeight() + 490);

	//coins
	for (int i = 0; i < 10; ++i)
	{
		items.push_back(Item(1, ObImages[3]));

	}

	//burgers
	items.push_back(Item(2, ObImages[0]));
	items.push_back(Item(2, ObImages[0]));

	//hotdog
	items.push_back(Item(4, ObImages[1]));
	items.push_back(Item(4, ObImages[1]));

	//pountine
	items.push_back(Item(3, ObImages[2]));
	items.push_back(Item(3, ObImages[2]));

	//spawn coins
	for (int i = 0; i < 10; ++i)
	{
		items[i].setX(rand() % 1100 + 400);
		items[i].setY((rand() % 2080) - 1380);

	}

	//spawn food
	for (int i = 10; i < 16; ++i)
	{
		items[i].setX(rand() % 1100 + 400);
		items[i].setY((rand() % 2080) - 1380);

	}
}

void Game::Update(float deltaTime, float x, float y, bool g, bool p, int w, int h)
{
	m_b1.changeY(gameSpeed * deltaTime);
	m_b2.changeY(gameSpeed * deltaTime);
	m_b3.changeY(gameSpeed * deltaTime);

	for (int i = 0; i < items.size(); ++i)
	{
		items[i].changeY(gameSpeed * deltaTime);
	}

	if (m_b1.getY() >= 1080)
	{
		m_b1.setY(m_b3.getY() - m_b3.getImage().getHeight() + 245);
		m_b1.setImage(BGImages[rand() % 7]);
		m_b1.setOrder(3);
		m_b2.setOrder(1);
		m_b3.setOrder(2);

	}
	else if (m_b2.getY() >= 1080)
	{
		m_b2.setY(m_b1.getY() - m_b1.getImage().getHeight() + 245);
		m_b2.setImage(BGImages[rand() % 7]);
		m_b1.setOrder(2);
		m_b2.setOrder(3);
		m_b3.setOrder(1);

	}
	else if (m_b3.getY() >= 1080)
	{
		m_b3.setY(m_b2.getY() - m_b2.getImage().getHeight() + 245);
		m_b3.setImage(BGImages[rand() % 7]);
		m_b1.setOrder(1);
		m_b2.setOrder(2);
		m_b3.setOrder(3);
	}


	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i].getY() >= 1080)
		{
			items[i].setX(rand() % 1100 + 400);
			items[i].setY((rand() % 1080) - 1080);
		}
	}

	cout << "p: "  << p << endl;
	cout << "g: "  << g << endl;


	//check player collision and event
	for (int i = 0; i < items.size(); ++i)
	{
		if (checkCollision(items[i].getX(), x, items[i].getWidth(), w, items[i].getY(), y, items[i].getHeight(), h))
		{
			if ((items[i].getID() == 1) && p == true)
			{
				//add money
				money += 10;
				//respawn item
				items[i].setX(rand() % 1100 + 400);
				items[i].setY((rand() % 1080) - 1080);
			}
			else if ((items[i].getID() != 1) && g == true)
			{
				//add food stolen
				food += 1;
				//respawn item
				items[i].setX(rand() % 1100 + 400);
				items[i].setY((rand() % 1080) - 1080);
			}
		}

	}

}

void Game::Draw()
{	
	
	if (m_b1.getOrder() == 3)
	{
		ofPushMatrix();
		ofTranslate(m_b1.getX(), m_b1.getY());
		m_b1.getImage().draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(m_b3.getX(), m_b3.getY());
		m_b3.getImage().draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(m_b2.getX(), m_b2.getY());
		m_b2.getImage().draw(0, 0);
		ofPopMatrix();

	}
	else if (m_b1.getOrder() == 2)
	{
		
		ofPushMatrix();
		ofTranslate(m_b2.getX(), m_b2.getY());
		m_b2.getImage().draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(m_b1.getX(), m_b1.getY());
		m_b1.getImage().draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(m_b3.getX(), m_b3.getY());
		m_b3.getImage().draw(0, 0);
		ofPopMatrix();
	}
	else
	{
		ofPushMatrix();
		ofTranslate(m_b3.getX(), m_b3.getY());
		m_b3.getImage().draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(m_b2.getX(), m_b2.getY());
		m_b2.getImage().draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(m_b1.getX(), m_b1.getY());
		m_b1.getImage().draw(0, 0);
		ofPopMatrix();
	
	}

	for (int i = 0; i < items.size(); ++i)
	{
		ofPushMatrix();
		ofTranslate(items[i].getX(), items[i].getY());
		items[i].getImage().draw(0, 0);
		ofPopMatrix();
	}

	string moneyStr = "Money: " + ofToString(money);
	string foodStr = "Food: " + ofToString(food);


	ofPushMatrix();
	if (nightTime)
	{
		ofSetColor(ofColor::lightGoldenRodYellow);
	}
	else
	{
		ofSetColor(ofColor::darkGray);
	}
	
	font.drawStringAsShapes(moneyStr, 90, 90);
	font.drawStringAsShapes(foodStr, 90, 140);
	ofSetColor(255, 255, 255);
	ofPopMatrix();
	   
}

void Game::LoadBGImages()
{
	if (!nightTime)
	{
		ofImage Canal1A;
		ofImage Canal1B;
		ofImage Canal2A;
		ofImage Canal2B;
		ofImage Canal3A;
		ofImage Canal3B;
		ofImage Canal3C;
		ofImage Canal5A;
		Canal1A.load("C1A.png");
		Canal1B.load("C1B.png");
		Canal2A.load("C2A.png");
		Canal2B.load("C2B.png");
		Canal3A.load("C3A.png");
		Canal3B.load("C3B.png");
		Canal3C.load("C3C.png");
		Canal5A.load("C5A.png");
		BGImages.push_back(Canal1A);
		BGImages.push_back(Canal1B);
		BGImages.push_back(Canal2A);
		BGImages.push_back(Canal2B);
		BGImages.push_back(Canal3A);
		BGImages.push_back(Canal3B);
		BGImages.push_back(Canal3C);
		BGImages.push_back(Canal5A);
		m_b1.setImage(BGImages[0]);
		m_b2.setImage(BGImages[1]);
		m_b3.setImage(BGImages[4]);
	}
	else
	{
		ofImage Canal1A;
		ofImage Canal1B;
		ofImage Canal2A;
		ofImage Canal2B;
		ofImage Canal3A;
		ofImage Canal3B;
		ofImage Canal3C;
		ofImage Canal5A;
		Canal1A.load("C1AN.png");
		Canal1B.load("C1BN.png");
		Canal2A.load("C2AN.png");
		Canal2B.load("C2BN.png");
		Canal3A.load("C3AN.png");
		Canal3B.load("C3BN.png");
		Canal3C.load("C3CN.png");
		Canal5A.load("C5AN.png");
		BGImages.push_back(Canal1A);
		BGImages.push_back(Canal1B);
		BGImages.push_back(Canal2A);
		BGImages.push_back(Canal2B);
		BGImages.push_back(Canal3A);
		BGImages.push_back(Canal3B);
		BGImages.push_back(Canal3C);
		BGImages.push_back(Canal5A);
		m_b1.setImage(BGImages[0]);
		m_b2.setImage(BGImages[1]);
		m_b3.setImage(BGImages[4]);
	}
	
}

void Game::LoadObjectImages()
{
	ofImage burger;
	ofImage hotdog;
	ofImage poutine;
	ofImage coin;

	burger.load("Burger.png");
	hotdog.load("Hotdog.png");
	poutine.load("Poutine.png");
	coin.load("Coin.png");

	burger.resize(burger.getWidth() / 6, burger.getHeight() / 6);
	hotdog.resize(hotdog.getWidth() / 6, hotdog.getHeight() / 6);
	poutine.resize(poutine.getWidth() / 8, poutine.getHeight() / 8);
	coin.resize(coin.getWidth() /3, coin.getHeight() / 3);

	ObImages.push_back(burger);
	ObImages.push_back(hotdog);
	ObImages.push_back(poutine);
	ObImages.push_back(coin);

}

bool Game::checkCollision(int mX, int X, int mW, int W, int mY, int Y, int mH, int H)
{
	if (fabsf(mX - X) * 2 < (mW + W) && fabsf(mY - Y) * 2 < (mH + H))
		return true;
	else
		return false;

}