#pragma once

struct Time {
public:
	Time(int frame, float deltaTime, float elapsedTime)
		: m_frame(frame),
		m_deltaTime(deltaTime),
		m_elapsedTime(elapsedTime) {}
	~Time() = default;

	/// <summary>
	/// 現在のフレーム番号を取得する
	/// </summary>
	int GetFrame() const { return m_frame; }
	/// <summary>
	/// 前回のフレームからの経過時間を取得する
	/// </summary>
	float GetDeltaTime() const { return m_deltaTime; }
	/// <summary>
	/// ゲーム開始からの経過時間を取得する
	/// </summary>
	float GetElapsedTime() const { return m_elapsedTime; }

private:
	int m_frame;
	float m_deltaTime;
	float m_elapsedTime;
};