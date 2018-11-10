#pragma once

#include "ofMain.h"
#include "ofxLeapC.h"
#include "Game.h"
#include "DeltaTimer.h"

#include "ProjectConstants.h"

class ofApp : public ofBaseApp {

public:
    void setup();
	void onLeapFrame(Leap::Frame frame);
    void update();
    void draw();

	DeltaTimer gameTime;

	Game newGame;

	ofxLeapC::Device		m_device;
	Leap::Frame				m_frame;

	ofVec3f					m_palmPos;
	ofVec3f					m_palmRot;
	float					m_pinchStrength;
	float					m_grabStrength;
};
