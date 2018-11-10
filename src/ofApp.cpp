#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	m_device.connectEventHandler(&ofApp::onLeapFrame, this);

	ofSetFrameRate(ProjectConstants::PROJ_DESIRED_FRAMERATE);

	newGame.InitGame();
}

void ofApp::onLeapFrame(Leap::Frame frame)
{
	m_frame = frame;
}

//--------------------------------------------------------------
void ofApp::update(){

	newGame.Update(gameTime.GetDeltaTime());
	m_device.update();

	const Leap::HandList& hands = m_frame.hands();

	for (int i = 0; i < hands.count(); ++i)
	{
		const Leap::Hand& hand = hands[i];
		const Leap::Vector palmPos = hand.palmPosition();
		const ofVec3f ofPalmPos = ofxLeapC::toVec3(hand.palmPosition());
		
		m_grabStrength = hand.grabStrength();
		m_pinchStrength = hand.pinchStrength();

		m_palmRot = ofVec3f(
			ofRadToDeg(hand.direction().pitch()),
			ofRadToDeg(hand.direction().yaw()),
			ofRadToDeg(hand.direction().roll())
		);

		m_palmPos.x = ofPalmPos.x * 7.0f;
		m_palmPos.z = ofPalmPos.z * 5.0f;

		m_palmPos.x = ofClamp(m_palmPos.x, -(float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f, (float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f);
		m_palmPos.z = ofClamp(m_palmPos.z, -(float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f, (float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f);

		m_palmPos += ofVec3f((float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f, 0.0f, (float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f);

		break;
	}

	gameTime.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
	ofTranslate(m_palmPos.x, m_palmPos.z);
	ofRotateZ(m_palmRot.y);
	ofScale(m_pinchStrength + 0.5f, m_pinchStrength + 0.5f, m_pinchStrength + 0.5f);
	ofDrawTriangle(0, -20, 10, 10, -10, 10);

	newGame.Draw();

	ofPopMatrix();
}

