#pragma once
#include "ofApp.h"
#include "Animation.h"

void Animation::Init(int fps, vector<ofImage> images)
{
	frameRate = fps;
	for (int i = 0; i < images.size(); ++i)
	{
		m_images.push_back(images[i]);
	}
}

void Animation::updateAnimation(float deltaTime)
{

	currentTime += deltaTime;

	while (currentTime >= (1.0f / (float)frameRate))//<----- S M A R T
	{
		currentTime -= 1.0f / (float)frameRate;
		++currentFrame;
	}

	while (currentFrame >= m_images.size())
	{
		currentFrame -= m_images.size();
	}

}

void Animation::render(int x, int y, bool flipped)
{

	m_images[currentFrame].draw(0, 0);
	
}

//int Animation::GetIndexCount()
//{
//	return images.Get(currentFrame)->GetIndexCount();
//}

//void Animation::ShutDown()
//{
//	for (int i = 0; i < images.size(); ++i)
//	{
//		images.Get(i)->Shutdown();
//	}
//	images.Empty();
//}
