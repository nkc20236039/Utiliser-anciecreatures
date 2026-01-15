#pragma once

#include <cmath>

namespace Library {
struct float3 {
public:
	float x, y, z;

	// 全ての要素が0のfloat3を返す
	static float3 Zero() { return float3(0.0f, 0.0f, 0.0f); }
	// 全ての要素が1のfloat3を返す
	static float3 One() { return float3(1.0f, 1.0f, 1.0f); }

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

	// 演算子オーバーロード
	float3 operator+(const float3& other) const {
		return float3(x + other.x, y + other.y, z + other.z);
	}
	float3& operator+=(const float3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	float3 operator-(const float3& other) const {
		return float3(x - other.x, y - other.y, z - other.z);
	}
	float3& operator-=(const float3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	float3 operator*(float scalar) const {
		return float3(x * scalar, y * scalar, z * scalar);
	}
	float3& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
	float3 operator*(float3 other) const {
		return float3(x * other.x, y * other.y, z * other.z);
	}
	float3& operator*=(float3 other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}
	float3 operator/(float scalar) const {
		return float3(x / scalar, y / scalar, z / scalar);
	}
	float3& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}
	float3 operator/(float3 other) const {
		return float3(x / other.x, y / other.y, z / other.z);
	}
	float3& operator/=(float3 other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	/// <summary>
	/// ベクトルの長さを取得する
	/// </summary>
	float Length() const {
		return std::sqrtf(x * x + y * y + z * z);
	}
	/// <summary>
	/// ベクトルを正規化したものを取得する
	/// </summary>
	float3 Normalized() const {
		float length = Length();
		if (length == 0.0f) {
			return float3::Zero();
		}
		return float3(x / length, y / length, z / length);
	}
};

struct float2 {
public:
	float x, y;

	// 全ての要素が0のfloat2を返す
	static float2 Zero() { return float2(0.0f, 0.0f); }
	// 全ての要素が1のfloat2を返す
	static float2 One() { return float2(1.0f, 1.0f); }

	/// <summary>
	/// 初期値(0)で初期化する
	/// </summary>
	float2() : x(0.0f), y(0.0f) {}
	/// <summary>
	/// 全ての値を第一引数の値で初期化する
	/// </summary>
	float2(float value) : x(value), y(value) {}
	/// <summary>
	/// 各軸の数値を指定して初期化する
	/// </summary>
	float2(float x, float y) : x(x), y(y) {}

	// 演算子オーバーロード
	float2 operator+(const float2& other) const {
		return float2(x + other.x, y + other.y);
	}
	float2& operator+=(const float2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	float2 operator-(const float2& other) const {
		return float2(x - other.x, y - other.y);
	}
	float2& operator-=(const float2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	float2 operator*(float scalar) const {
		return float2(x * scalar, y * scalar);
	}
	float2& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}
	float2 operator*(float2 other) const {
		return float2(x * other.x, y * other.y);
	}
	float2& operator*=(float2 other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}
	float2 operator/(float scalar) const {
		return float2(x / scalar, y / scalar);
	}
	float2& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}
	float2 operator/(float2 other) const {
		return float2(x / other.x, y / other.y);
	}
	float2& operator/=(float2 other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	/// <summary>
	/// ベクトルの長さを取得する
	/// </summary>
	float Length() const {
		return std::sqrtf(x * x + y * y);
	}
	/// <summary>
	/// ベクトルを正規化したものを取得する
	/// </summary>
	float2 Normalized() const {
		float length = Length();
		if (length == 0.0f) {
			return float2::Zero();
		}
		return float2(x / length, y / length);
	}
};
}