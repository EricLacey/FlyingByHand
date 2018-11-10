#pragma once
#include "ofApp.h"

class Animation
{

private:

	int frameRate;
	int currentFrame;
	int currentAnimationState;

	float currentTime;

	vector<ofImage> mImages;

public:
	Animation() { currentAnimationState = 0; }

	void Init(int fps, vector<ofImage> images);

	void updateAnimation(float deltaTime);

	void render(int x, int y, bool flipped);

	//change to be called from animation manager class so the correct amount of animations will be used for each specific entity
	//void changeAnimation(int animState);//takes in integer to put through switch statement. then decides which animation state to switch to

	int getCurrentAnimation() { return currentAnimationState; }

	//int GetIndexCount();
	void resetIndex() { currentFrame = 0; currentTime = 0.0f; }

	//void ShutDown();

	////add animation frame
	//void addFrame(WCHAR* filename) { animationFileNames.Add(filename); }
	////update animation
	//WCHAR* updateAnimation();

	////set frame
	//void setFrameNumber(int frameNum) { currentFrame = frameNum; }

	////end animation
	////get current bitmap
	//int getFrameNumber() { return currentFrame; }

};