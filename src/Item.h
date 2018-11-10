#pragma once
#include "ofApp.h"

class Item
{

public:

	Item(int w, int h, float x, float y, ofImage i)
	{
		m_width = w;
		m_height = h;
		m_xPos = x;
		m_yPos = y;
		m_ItemImage = i;
	}

private:

	ofImage m_ItemImage;

	int m_width;
	int m_height;

	float m_xPos;
	float m_yPos;

	void setImage(ofImage i) { m_ItemImage = i; }

	void setWidth(int w) { m_width = w; }
	void setHeight(int h) { m_height = h; }
	void setX(float x) { m_xPos = x; }
	void setY(float y) { m_yPos = y; }
	void changeX(float c) { m_xPos += c; }
	void changeY(float c) { m_yPos += c; }

};