#pragma once

namespace Library {
struct float3 {
public:
	float x, y, z;

	/// <summary>
	/// 初期値(0)で初期化する
	/// </summary>
	float3() : x(0.0f), y(0.0f), z(0.0f) {}
	/// <summary>
	/// 全ての値を第一引数の値で初期化する
	/// </summary>
	float3(float value) :x(value), y(value), z(value) {}
	/// <summary>
	/// 各軸の数値を指定して初期化する
	/// </summary>
	float3(float x, float y, float z) : x(x), y(y), z(z) {}
};
}