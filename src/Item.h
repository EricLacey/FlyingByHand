#pragma once
#include "ofMain.h"

class Item
{

public:

	Item()
	{
		m_width = 0;
		m_height = 0;
		m_xPos = 0;
		m_yPos = 0;
	}
	void setImage(ofImage i) { m_ItemImage = i; }

	void setWidth(int w) { m_width = w; }
	void setHeight(int h) { m_height = h; }
	void setX(float x) { m_xPos = x; }
	void setY(float y) { m_yPos = y; }
	void changeX(float c) { m_xPos += c; }
	void changeY(float c) { m_yPos += c; }

private:

	ofImage m_ItemImage;

	int m_width;
	int m_height;

	float m_xPos;
	float m_yPos;

};