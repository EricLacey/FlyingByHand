#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	//start conditions
	m_charScale = 1.0;
	m_grabAnim = false;
	m_pinchAnim = false;


	//setup of leap motion
	m_device.connectEventHandler(&ofApp::onLeapFrame, this);

	//setup of framerate for game
	ofSetFrameRate(ProjectConstants::PROJ_DESIRED_FRAMERATE);



	//ofSetFrameRate(ProjectConstants::PROJ_DESIRED_FRAMERATE);

	bird.load("Bird.png");
	bird.resize(bird.getWidth() / 2, bird.getHeight() / 2);

	newGame.InitGame();
	gameTime.Update();

}

void ofApp::onLeapFrame(Leap::Frame frame)
{
	//update frame
	m_frame = frame;
}

//--------------------------------------------------------------
void ofApp::update(){

	//update leap motion
	m_device.update();

	//creating list of hand objects from frame
	const Leap::HandList& hands = m_frame.hands();

	//collecting info from 1st hand in list (other hands unneeded)
	for (int i = 0; i < hands.count(); ++i)
	{
		//pulling first hand from hands list
		const Leap::Hand& hand = hands[i];


		//pulling palmPos from hand and converting to vec3 for use
		const Leap::Vector palmPos = hand.palmPosition();
		const ofVec3f ofPalmPos = ofxLeapC::toVec3(hand.palmPosition());

		//scaling palm position 
		m_palmPos.x = ofPalmPos.x * 7.0f;
		m_palmPos.z = ofPalmPos.z * 5.0f;
		m_palmPos.x = ofClamp(m_palmPos.x, -(float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f, (float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f);
		m_palmPos.z = ofClamp(m_palmPos.z, -(float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f, (float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f);
		m_palmPos += ofVec3f((float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f, 0.0f, (float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f);


		//pulling grab and pinch gestures from hand
		m_grabStrength = hand.grabStrength();
		m_pinchStrength = hand.pinchStrength();


		//creating vec3 from hand direction
		m_palmRot = ofVec3f(
			ofRadToDeg(hand.direction().pitch()),
			ofRadToDeg(hand.direction().yaw()),
			ofRadToDeg(hand.direction().roll())
		);
		break;
	}

	//set grab animation if grabbing
	if (m_grabStrength >= 0.8) 
	{
		m_grabAnim = true;
	}
	else 
	{
		m_grabAnim = false;
	}

	if (m_grabAnim && m_charScale >= 0.7)
	{
		//m_charScale -= 0.01;
		m_charScale /= 1.15;
	}
	else if (!m_grabAnim && m_charScale < 1.0)
	{
		//m_charScale += 0.01;
		m_charScale *= 1.15;
	}

	if (m_pinchStrength >= 0.8)
	{
		m_pinchAnim = true;
	}
	else
	{
		m_pinchAnim = false;
	}

	//update game
	newGame.Update(gameTime.GetDeltaTime(), m_palmPos.x, m_palmPos.z, m_grabAnim, m_pinchAnim, bird.getWidth(), bird.getHeight());
	//newGame.Update(gameTime.GetDeltaTime());
	gameTime.Update();

}

//--------------------------------------------------------------
void ofApp::draw()
{
	//ofPushMatrix();
	newGame.Draw();

	ofPushMatrix();
		ofTranslate(m_palmPos.x, m_palmPos.z);
		ofRotateZ(m_palmRot.y);
		ofScale(m_charScale);
		bird.draw(0, 0);
	ofPopMatrix();

	//ofPopMatrix();
}