#pragma once

#include "DataTypes.h"

/**
* The DeltaTimer class starts measuring time immediately and is intended for either profiling or measuring real-world time
*/
class DeltaTimer
{
public:
	explicit DeltaTimer(bool FPS = true);

	void Init();
	void Update();

	F32 GetDeltaTime();
	U32 GetCycleDifference();

	F32 CyclesToSeconds(U32 Cycles);
	U64 SecondsToCycles(F32 Seconds);

private:
	I64 StartTime;
	U32 CycleDifference;
	U32 CyclesPerSecond;
	bool FrameRateTimer;
};