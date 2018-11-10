#pragma once

#include "ofMain.h"
#include "ofxLeapC.h"

#include "ProjectConstants.h"


class ofApp : public ofBaseApp {

public:
    void setup();
	void onLeapFrame(Leap::Frame frame);
    void update();
    void draw();

	ofxLeapC::Device		m_device;
	Leap::Frame				m_frame;

	ofVec3f					m_palmPos;
	ofVec3f					m_palmRot;
	float					m_pinchStrength;
	float					m_grabStrength;

	bool					m_grabAnim;
	bool					m_pinchAnim;
	float					m_charScale;
};
