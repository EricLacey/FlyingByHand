#pragma once
#include "Animation.h"

class AnimationManager
{

private:

	vector<ofImage> mTextures;

	int animationState;

	//currentanimation
	Animation* m_currentAnimation;

	Animation peopleStand;
	Animation peopleSkate;
	Animation idle;
	Animation jump;
	Animation fall;
	Animation shootrun;
	Animation shootstop;
	Animation hide;
	Animation hideIdle;
	Animation death;
	Animation default;
	
public:

	AnimationManager() {}

	void render(float x, float y, bool f);

	void Init(vector<ofImage> textures);

	void Update(float DeltaTime);

	//void ShutDown(TextureShaderClass*);

	void changeAnimation(int a);

	int getCurrentAnimation() {	return animationState;	};//could change to int with animstate num assigned

	void resetAnimation() { m_currentAnimation->resetIndex(); }

	void addAnimation(int animstate, Animation animation) 
	{
		/*switch (animstate)
		{
		case 1:
			run = animation;
			break;
		case 2:
			walk = animation;
			break;
		case 3:
			idle = animation;
			break;
		case 4:
			jump = animation;
			break;
		case 5:
			fall = animation;
			break;
		case 6:
			shootrun = animation;
			break;
		case 7:
			shootstop = animation;
			break;
		default:
			break;
		}*/
	}

};
