#include "Game.h"

void Game::InitGame()
{
	srand(time(NULL));
	LoadBGImages();
	LoadObjectImages();

	gameSpeed = 200.0f;
//	m_b1.setOrder(1);
	//m_b2.setOrder(2);
	//m_b3.setOrder(3);
	m_b1.setX(0.0);
	m_b2.setX(0.0);
	m_b3.setX(0.0);

	m_b1.setY(0.0);
	m_b2.setY(0.0 - m_b2.getImage().getHeight());
	m_b3.setY(-m_b2.getImage().getHeight() - m_b3.getImage().getHeight());

}

void Game::Update(float deltaTime)
{
	m_b1.changeY(gameSpeed * deltaTime);
	m_b2.changeY(gameSpeed * deltaTime);
	m_b3.changeY(gameSpeed * deltaTime);

	if (m_b1.getY() >= 1080)
	{
		m_b1.setY(0.0 - m_b3.getImage().getHeight());
	}
	else if (m_b2.getY() >= 1080)
	{
		m_b2.setY(0.0 - m_b2.getImage().getHeight());
	}
	else if (m_b3.getY() >= 1080)
	{
		m_b3.setY(0.0 - m_b1.getImage().getHeight());
	}
}

void Game::Draw()
{

}

void Game::LoadBGImages()
{
	ofImage Canal1A;
	ofImage Canal1B;
	ofImage Canal2A;
	ofImage Canal2B;
	ofImage Canal3A;
	ofImage Canal3B;
	ofImage Canal3C;
	ofImage Canal5A;
	Canal1A.loadImage("C1A.png");
	Canal1B.loadImage("C1B.png");
	Canal2A.loadImage("C2A.png");
	Canal2B.loadImage("C2B.png");
	Canal3A.loadImage("C3A.png");
	Canal3B.loadImage("C3B.png");
	Canal3C.loadImage("C3C.png");
	Canal5A.loadImage("C5A.png");
	BGImages.push_back(Canal1A);
	BGImages.push_back(Canal1B);
	BGImages.push_back(Canal2A);
	BGImages.push_back(Canal2B);
	BGImages.push_back(Canal3A);
	BGImages.push_back(Canal3B);
	BGImages.push_back(Canal3C);
	BGImages.push_back(Canal5A);
}

void Game::LoadObjectImages()
{
	ofImage burger;
	ofImage hotdog;
	ofImage poutine;
	ofImage coin;

	burger.loadImage("Burger.png");
	hotdog.loadImage("Hotdog.png");
	poutine.loadImage("Poutine.png");
	coin.loadImage("Coin.png");

	ObImages.push_back(burger);
	ObImages.push_back(hotdog);
	ObImages.push_back(poutine);
	ObImages.push_back(coin);

}