#pragma once
#include "ofMain.h"

class Background
{

public:

	void setImage(ofImage i) { bImage = i; }
	void setX(float x) { xPos = x; }
	void setY(float y) { yPos = y; }
	void changeX(float c) { xPos += c; }
	void changeY(float c) { yPos += c; }
	void setOrder(int o) { m_order = 0; }
	float getY() { return yPos; }
	int getOrder() { return m_order; }
	ofImage getImage() { return bImage; }

private:

	ofImage bImage;
	
	int m_order;

	float xPos;
	float yPos;

	std::vector<ofVec2f> keyPositions;

};
