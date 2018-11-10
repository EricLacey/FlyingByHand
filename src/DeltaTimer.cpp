#include "DeltaTimer.h"

#include <Windows.h>

DeltaTimer::DeltaTimer(bool FPS)
	: StartTime(0)
	, CycleDifference(0)
	, CyclesPerSecond(0)
	, FrameRateTimer(true)
{
}

void DeltaTimer::Init()
{
	I64 Frequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&Frequency);
	CyclesPerSecond = (U32)Frequency;
	QueryPerformanceCounter((LARGE_INTEGER*)&StartTime);
}

void DeltaTimer::Update()
{
	I64 CurrentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&CurrentTime);
	CycleDifference = (U32)(CurrentTime - StartTime);
	StartTime = CurrentTime;
}

F32 DeltaTimer::GetDeltaTime()
{
	return !FrameRateTimer ? CyclesToSeconds(CycleDifference) : (CyclesToSeconds(CycleDifference) > (5.0f / 60.0f) ? (1.0f / 60.0f) : CyclesToSeconds(CycleDifference));
}

U32 DeltaTimer::GetCycleDifference()
{
	return !FrameRateTimer ? CycleDifference : (CyclesToSeconds(CycleDifference) > (5.0f / 60.0f) ? SecondsToCycles(1.0f / 60.0f) : CycleDifference);
}

F32 DeltaTimer::CyclesToSeconds(U32 Cycles)
{
	return (F32)Cycles / (F32)CyclesPerSecond;
}

U64 DeltaTimer::SecondsToCycles(F32 Seconds)
{
	return (U64)(Seconds * CyclesPerSecond);
}