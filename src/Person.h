#pragma once
#include "ofApp.h"

class Person
{

public:

	Person(int w, int h, float x, float y, vector<ofImage> i)
	{
		m_width = w;
		m_height = h;
		m_xPos = x;
		m_yPos = y;
		m_animation = i;

		//i contains a certain number of the options below in a specific order

		//rand() % head
		//rand() % hair
		//rand() % jacket
		//rand() % legs

		//push m_animation([legs])
	}

private:

	vector<ofImage> m_animation;

	int m_width;
	int m_height;

	float m_xPos;
	float m_yPos;

	void setImages(vector<ofImage> i) { m_animation = i; }

	void setWidth(int w) { m_width = w; }
	void setHeight(int h) { m_height = h; }
	void setX(float x) { m_xPos = x; }
	void setY(float y) { m_yPos = y; }
	void changeX(float c) { m_xPos += c; }
	void changeY(float c) { m_yPos += c; }

};