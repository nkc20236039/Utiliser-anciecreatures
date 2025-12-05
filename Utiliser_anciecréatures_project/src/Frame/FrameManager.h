#pragma once
#include "Time.h"

class FrameManager {
public:
	FrameManager();
	~FrameManager() = default;

	/// <summary>
	/// フレームの計測を開始する
	/// </summary>
	Time MeasurementStart();
	/// <summary>
	/// フレームの計測を終了する
	/// </summary>
	Time MeasurementEnd();
#if _DEBUG
	/// <summary>
	/// フレームレートを画面に表示する
	/// </summary>
	void ShowFPS(int span);
#endif
private:
	int m_bootTime;
	int m_count;
	int m_frame;
	float m_deltaTime;
#if _DEBUG
	int d_lastTime = 0;
	int d_lastFPS = 0;
#endif
};