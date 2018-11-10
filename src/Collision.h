#pragma once
#include "ofMain.h"

class Collision
{

public:

private:
	bool checkCollision(int mX, int X, int mW, int W, int mY, int Y, int mH, int H)
	{
		if (fabsf(mX - X) * 2 < (mW + W) && fabsf(mY - Y) * 2 < (mH + H))
			return true;
		else
			return false;

	}
};

