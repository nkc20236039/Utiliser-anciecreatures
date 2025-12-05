#include "FrameManager.h"

#include "DxLib.h"

#include "System/OutputLog.h"

FrameManager::FrameManager()
	: m_bootTime(GetNowCount()),
	m_count(0),
	m_frame(0),
	m_deltaTime(0.0f) {}

Time FrameManager::MeasurementStart() {
	// 現在の時間を取得
	int nowCount = GetNowCount();
	// 開始時間を保存
	m_count = nowCount;

	// フレーム数をインクリメント
	++m_frame;

	// アプリ起動からの経過時間を計算
	float elapsedTime = (nowCount - m_bootTime) / 1000.0f;	// 1000.0 => 1000ミリ秒を1秒に変換するため

	// Time構造体を返す
	return Time(m_frame, m_deltaTime, elapsedTime);
}

Time FrameManager::MeasurementEnd() {
	// 現在の時間を取得
	int nowCount = GetNowCount();
	// フレーム開始からの経過時間を計算
	m_deltaTime = (nowCount - m_count) / 1000.0f;

	// アプリ起動からの経過時間を計算
	float elapsedTime = (nowCount - m_bootTime) / 1000.0f;

	// Time構造体を返す
	return Time(m_frame, m_deltaTime, elapsedTime);
}

#if _DEBUG
void FrameManager::ShowFPS(int span) {
	// spanごとにFPSを計算して表示
	int currentTime = GetNowCount();

	// spanの時間経過したらFPSを計算して表示
	if (span <= (currentTime - d_lastTime) && m_deltaTime != 0.0f) {
		// deltaTimeからFPSを計算する
		d_lastFPS = static_cast<int>(1.0f / m_deltaTime);
		d_lastTime = currentTime;
	}

	// 画面にFPSを表示
	OUTPUT_LOG::DrawDisplayLog(GetColor(255, 0, 255), "FPS: %d", d_lastFPS);
}
#endif