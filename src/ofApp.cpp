#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	//start conditions
	m_charScale = 1.0;
	m_grabAnim = false;
	m_pinchAnim = false;

<<<<<<< HEAD
	//setup of leap motion
	m_device.connectEventHandler(&ofApp::onLeapFrame, this);

	//setup of framerate for game
	ofSetFrameRate(ProjectConstants::PROJ_DESIRED_FRAMERATE);


=======
	//ofSetFrameRate(ProjectConstants::PROJ_DESIRED_FRAMERATE);

	newGame.InitGame();
	gameTime.Update();

>>>>>>> Game/AI-branch
}

void ofApp::onLeapFrame(Leap::Frame frame)
{
	//update frame
	m_frame = frame;
}

//--------------------------------------------------------------
void ofApp::update(){
<<<<<<< HEAD
	//update leap motion
=======

	newGame.Update(gameTime.GetDeltaTime());
>>>>>>> Game/AI-branch
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
<<<<<<< HEAD

		//scaling palm position 
		m_palmPos.x = ofPalmPos.x * 7.0f;
		m_palmPos.z = ofPalmPos.z * 5.0f;


		m_palmPos.x = ofClamp(m_palmPos.x, -(float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f, (float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f);
		m_palmPos.z = ofClamp(m_palmPos.z, -(float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f, (float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f);

		m_palmPos += ofVec3f((float)ProjectConstants::PROJ_WINDOW_RES_X / 2.0f, 0.0f, (float)ProjectConstants::PROJ_WINDOW_RES_Y / 2.0f);


		//pulling grab and pinch gestures from hand
=======
		
>>>>>>> Game/AI-branch
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

<<<<<<< HEAD
	//set grab animation if grabbing
	if (m_grabStrength >= 0.8) {
		m_grabAnim = true;
	}
	else {
		m_grabAnim = false;
	}
	if (m_grabAnim && m_charScale >= 0.5) {
		m_charScale -= 0.01;
	}
	else if (!m_grabAnim && m_charScale < 1.0) {
		m_charScale += 0.01;
	}
=======
	gameTime.Update();
>>>>>>> Game/AI-branch
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
		ofDrawTriangle(0, -20, 10, 10, -10, 10); // placeholder to show position and direction
	ofPopMatrix();

	//ofPopMatrix();
}