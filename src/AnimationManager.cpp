#include "AnimationManager.h"

void AnimationManager::render(float x, float y, bool f)
{
	m_currentAnimation->render( x, y, f);
}

void AnimationManager::Init(vector<ofImage> textures)
{

	//	for (int i = 0; i < 8; i++)
	//	{
	//		m_textures.Add(*textures.Get(i));
	//	}

	//	run.Init(12, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//	animationState = 1;
	//	m_currentAnimation = &run;

	//	m_textures.Empty();

	//	for (int i = 8; i < 18; i++)
	//	{
	//		m_textures.Add(*textures.Get(i));
	//	}
	//	idle.Init(10, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);

	//	m_textures.Empty();

	//	for (int i = 18; i < 24; i++)
	//	{
	//		m_textures.Add(*textures.Get(i));
	//	}
	//	jump.Init(6, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//	m_textures.Empty();
	//	for (int i = 24; i < 32; i++)
	//	{
	//		m_textures.Add(*textures.Get(i));
	//	}
	//	shootrun.Init(8, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//	m_textures.Empty();

	//	if (isChar == 2)//if main character
	//	{
	//		for (int i = 32; i < 37; i++)
	//		{
	//			m_textures.Add(*textures.Get(i));
	//		}
	//		hide.Init(5, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//		m_textures.Empty();
	//	
	//		for (int i = 37; i < 41; i++)
	//		{
	//			m_textures.Add(*textures.Get(i));
	//		}
	//		hideIdle.Init(4, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//		m_textures.Empty();

	//		for (int i = 41; i < 47; i++)
	//		{
	//			m_textures.Add(*textures.Get(i));
	//		}
	//		death.Init(6, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//		m_textures.Empty();
	//	}
	//	if (isChar == 3)//death animations
	//	{
	//		for (int i = 32; i < 38; i++)
	//		{
	//			m_textures.Add(*textures.Get(i));
	//		}
	//		death.Init(6, m_textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//		m_textures.Empty();
	//	}
	//}
	//else
	//{
	//	default.Init(12, textures, device, deviceContext, screenWidth, screenHeight, imageWidth, imageHeight, handle);
	//	m_currentAnimation = &default;
	//}

}

void AnimationManager::Update(float DeltaTime)
{
	m_currentAnimation->updateAnimation(DeltaTime);
}

//void AnimationManager::ShutDown(TextureShaderClass* shader)
//{
//	//m_currentAnimation.ShutDown();
//	run.ShutDown();
//	walk.ShutDown();
//	idle.ShutDown();
//	jump.ShutDown();
//	fall.ShutDown();
//	shootrun.ShutDown();
//	shootstop.ShutDown();
//	default.ShutDown();
//
//	shader->Shutdown();
//}

void AnimationManager::changeAnimation(int animstate)
{

	/*if (!(animationState == animstate))
	{
		animationState = animstate;

		switch (animationState)
		{
		case 1:
			m_currentAnimation = &run;

			break;
		case 2:
			m_currentAnimation = &walk;

			break;
		case 3:
			m_currentAnimation = &idle;

			break;
		case 4:
			m_currentAnimation = &jump;

			break;
		case 5:
			m_currentAnimation = &fall;

			break;
		case 6:
			m_currentAnimation = &shootrun;

			break;
		case 7:
			m_currentAnimation = &shootstop;

			break;
		case 8:
			m_currentAnimation = &hide;

			break;
		case 9:
			m_currentAnimation = &hideIdle;

			break;
		case 10:
			m_currentAnimation = &death;

			break;
		default:
			break;
		}
	}*/
	
}