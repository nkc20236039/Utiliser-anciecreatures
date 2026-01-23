#pragma once

#include <cmath>
#include <array>

struct float3 {
public:
	float x, y, z;

	// 全ての要素が0のfloat3を返す
	static float3 Zero() { return float3(0.0f, 0.0f, 0.0f); }
	// 全ての要素が1のfloat3を返す
	static float3 One() { return float3(1.0f, 1.0f, 1.0f); }
	// 上方向の単位ベクトルを返す
	static float3 Up() { return float3(0.0f, 1.0, 0.0f); }
	// 前方向の単位ベクトルを返す
	static float3 Forward() { return float3(0.0f, 0.0, 1.0f); }
	// 右方向の単位ベクトルを返す
	static float3 Right() { return float3(1.0f, 0.0, 0.0f); }

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
	float Length() const;
	/// <summary>
	/// ベクトルを正規化したものを取得する
	/// </summary>
	float3 Normalized() const;
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
	float Length() const;
	/// <summary>
	/// ベクトルを正規化したものを取得する
	/// </summary>
	float2 Normalized() const;
};

struct Quaternion
{
public:
	Quaternion() : x(0), y(0), z(0), w(1) {}
	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	/// <summary>
	/// 単位回転を取得する
	/// </summary>
	static Quaternion Identity() {
		return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
	}

	/// <summary>
	/// 回転の長さを取得する
	/// </summary>
	float Length() const {
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	/// <summary>
	/// 回転を正規化した結果を取得する
	/// </summary>
	Quaternion Normalized() const;

	/// <summary>
	/// 回転の共役を取得する
	/// </summary>
	/// <returns></returns>
	Quaternion Conjugate() const;

	/// <summary>
	/// 回転の逆を取得する
	/// </summary>
	/// <returns></returns>
	Quaternion Inverse() const;

	/// <summary>
	/// 指定したベクトルの方向へ回転した結果を取得する
	/// </summary>
	/// <param name="vector"></param>
	/// <returns></returns>
	float3 Rotate(const float3& vector) const;

	/// <summary>
	/// 回転をオイラー角表現で取得する
	/// </summary>
	/// <returns></returns>
	float3 Euler() const;

	/// <summary>
	/// 回転を合成する
	/// </summary>
	Quaternion operator*(const Quaternion& q) const {
		return Quaternion(
			w * q.x + x * q.w + y * q.z - z * q.y,
			w * q.y - x * q.z + y * q.w + z * q.x,
			w * q.z + x * q.y - y * q.x + z * q.w,
			w * q.w - x * q.x - y * q.y - z * q.z);
	}

	/// <summary>
	/// 軸を元に回転した結果を取得する
	/// </summary>
	static Quaternion FromAxisAngle(const float3& axis, float rad) {
		float3 n = axis.Normalized();
		float half = rad * 0.5f;
		float s = std::sin(half);

		return Quaternion(
			n.x * s,
			n.y * s,
			n.z * s,
			std::cos(half));
	}

	/// <summary>
	/// オイラー角表現を使用してクォータニオンを取得する
	/// </summary>
	static Quaternion FromEuler(float pitch, float yaw, float roll) {
		float hx = pitch * 0.5f;
		float hy = yaw * 0.5f;
		float hz = roll * 0.5f;

		float cx = std::cos(hx), sx = std::sin(hx);
		float cy = std::cos(hy), sy = std::sin(hy);
		float cz = std::cos(hz), sz = std::sin(hz);

		return Quaternion(
			sx * cy * cz - cx * sy * sz,
			cx * sy * cz + sx * cy * sz,
			cx * cy * sz - sx * sy * cz,
			cx * cy * cz + sx * sy * sz);
	}

	/// <summary>
	/// 二つの回転から内積を求める
	/// </summary>
	static float Dot(const Quaternion& a, const Quaternion& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	/// <summary>
	/// 二つの回転を補完した回転を取得する
	/// </summary>
	static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t) {
		Quaternion q1 = a.Normalized();
		Quaternion q2 = b.Normalized();

		float dot = Dot(q1, q2);

		if (dot < 0.0f)
		{
			q2 = Quaternion(-q2.x, -q2.y, -q2.z, -q2.w);
			dot = -dot;
		}

		if (dot > 0.9995f)
		{
			// 線形補間
			Quaternion r(
				q1.x + t * (q2.x - q1.x),
				q1.y + t * (q2.y - q1.y),
				q1.z + t * (q2.z - q1.z),
				q1.w + t * (q2.w - q1.w));

			return r.Normalized();
		}

		float theta = std::acos(dot);
		float sinT = std::sin(theta);

		float w1 = std::sin((1 - t) * theta) / sinT;
		float w2 = std::sin(t * theta) / sinT;

		return Quaternion(
			q1.x * w1 + q2.x * w2,
			q1.y * w1 + q2.y * w2,
			q1.z * w1 + q2.z * w2,
			q1.w * w1 + q2.w * w2);
	}

	static Matrix4x4 MakeRotationMatrix(const Quaternion& quaternion) {
		Quaternion n = quaternion.Normalized();

		float xx = n.x * n.x;
		float yy = n.y * n.y;
		float zz = n.z * n.z;
		float xy = n.x * n.y;
		float xz = n.x * n.z;
		float yz = n.y * n.z;
		float wx = n.w * n.x;
		float wy = n.w * n.y;
		float wz = n.w * n.z;

		Matrix4x4 matrix = Matrix4x4::Identity();

		matrix.Matrix[0][0] = 1 - 2 * (yy + zz);
		matrix.Matrix[0][1] = 2 * (xy + wz);
		matrix.Matrix[0][2] = 2 * (xz - wy);
		
		matrix.Matrix[1][0] = 2 * (xy - wz);
		matrix.Matrix[1][1] = 1 - 2 * (xx + zz);
		matrix.Matrix[1][2] = 2 * (yz + wx);
		
		matrix.Matrix[2][0] = 2 * (xz + wy);
		matrix.Matrix[2][1] = 2 * (yz - wx);
		matrix.Matrix[2][2] = 1 - 2 * (xx + yy);

		return matrix;
	}

private:
	float x, y, z, w;
};

struct Matrix4x4 {
public:
	float Matrix[4][4];

	static Matrix4x4 Identity() {
		Matrix4x4 r{};
		r.Matrix[0][0] = 1;
		r.Matrix[1][1] = 1;
		r.Matrix[2][2] = 1;
		r.Matrix[3][3] = 1;

		return r;
	}
};