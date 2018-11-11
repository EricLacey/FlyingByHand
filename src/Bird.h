#pragma once

#include "ofMain.h"


class Bird 
{
public:

	void drawBird(float x, float y, float scale)
	{

		ofPushMatrix();
			
			m_image.draw(m_xPos, m_yPos);
		ofPopMatrix();
	
	}


private:

	float m_xPos;
	float m_yPos;
	ofImage m_image;
};