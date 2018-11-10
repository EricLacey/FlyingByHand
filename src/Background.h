#pragma once
#include "ofApp.h"

class Background
{

public:

	Background()
	{

	}

private:

	ofImage bImage;
	ofImage bImagePool;
	
	float xPos;
	float yPos;

	vector<ofVec2f> keyPositions;

};
