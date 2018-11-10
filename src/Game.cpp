#include "Game.h"

void Game::InitGame()
{
	srand(time(NULL));
	LoadBGImages();
	LoadObjectImages();

	gameSpeed = 1000.0f;
//	m_b1.setOrder(1);
	//m_b2.setOrder(2);
	//m_b3.setOrder(3);
	m_b1.setX(0.0);
	m_b2.setX(0.0);
	m_b3.setX(0.0);

	m_b1.setY(0.0);
	m_b2.setY(0.0 - m_b2.getImage().getHeight());
	m_b3.setY(0.0 - m_b2.getImage().getHeight() - m_b3.getImage().getHeight());

	//coins
	for (int i = 0; i < 10; ++i)
	{
		items.push_back(Item(1));

	}

	//burgers
	items.push_back(Item(2));
	items.push_back(Item(2));

	//hotdog
	items.push_back(Item(4));
	items.push_back(Item(4));

	//pountine
	items.push_back(Item(3));
	items.push_back(Item(3));

}

void Game::Update(float deltaTime)
{
	//cout << deltaTime << endl;
	m_b1.changeY(gameSpeed * deltaTime);
	//cout << m_b1.getY() << endl;
	m_b2.changeY(gameSpeed * deltaTime);
	//cout << m_b2.getY() << endl;
	m_b3.changeY(gameSpeed * deltaTime);
	//cout << m_b3.getY() << endl;

	if (m_b1.getY() >= 1080)
	{
		m_b1.setY(m_b3.getY() - m_b3.getImage().getHeight());
	//	cout << "moving 1 to top" << endl;
		m_b1.setImage(BGImages[rand() % 7]);

	}
	else if (m_b2.getY() >= 1080)
	{
		m_b2.setY(m_b1.getY() - m_b1.getImage().getHeight());
	//	cout << "moving 2 to top" << endl;
		m_b2.setImage(BGImages[rand() % 7]);

	}
	else if (m_b3.getY() >= 1080)
	{
		m_b3.setY(m_b2.getY() - m_b2.getImage().getHeight());
	//	cout << "moving 3 to top" << endl;
		m_b3.setImage(BGImages[rand() % 7]);

	}

}

void Game::Draw()
{
	//ofPushMatrix();
	ofPushMatrix();
	ofTranslate(m_b1.getX(), m_b1.getY());
	m_b1.getImage().draw(0, 0);
	ofPopMatrix();

	//ofPushMatrix();
//	ofTranslate(0, m_b2.getY());
	ofPushMatrix();
	ofTranslate(m_b2.getX(), m_b2.getY());
	m_b2.getImage().draw(0, 0);
	ofPopMatrix();

	//ofPushMatrix();
	//ofTranslate(0, m_b3.getY());
	ofPushMatrix();
	ofTranslate(m_b3.getX(), m_b3.getY());
	m_b3.getImage().draw(0, 0);
	ofPopMatrix();
	


	//for (int i = 0; i < items.size(); ++i)
	//{
	//	items[i].getImage().draw(0, 0);
	//}
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
	Canal1A.load("C1A.jpg");
	Canal1B.load("C1B.jpg");
	Canal2A.load("C2A.jpg");
	Canal2B.load("C2B.jpg");
	Canal3A.load("C3A.jpg");
	Canal3B.load("C3B.jpg");
	Canal3C.load("C3C.jpg");
	Canal5A.load("C5A.jpg");
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

	ObImages.push_back(burger);
	ObImages.push_back(hotdog);
	ObImages.push_back(poutine);
	ObImages.push_back(coin);

}