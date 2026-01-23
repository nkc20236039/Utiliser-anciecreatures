#include "UMath/Structs.h"

#include "Mathex.h"

/*-------------------------------- float3 --------------------------------*/
float float3::Length() const {
	return std::sqrtf(x * x + y * y + z * z);
}

float3 float3::Normalized() const {
	float length = Length();
	if (length == 0.0f) {
		return float3::Zero();
	}
	return float3(x / length, y / length, z / length);
}

/*-------------------------------- float2 --------------------------------*/
float float2::Length() const {
	return std::sqrtf(x * x + y * y);
}

float2 float2::Normalized() const {
	float length = Length();
	if (length == 0.0f) {
		return float2::Zero();
	}
	return float2(x / length, y / length);
}

/*------------------------------ Quaternion ------------------------------*/
Quaternion Quaternion::Normalized() const {
	float len = Length();
	if (len == 0) { return Quaternion(); }
	return Quaternion(x / len, y / len, z / len, w / len);
}

Quaternion Quaternion::Conjugate() const {
	return Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::Inverse() const {
	float len2 = x * x + y * y + z * z + w * w;
	if (len2 == 0) { return Quaternion(); }
	Quaternion c = Conjugate();
	return Quaternion(c.x / len2, c.y / len2, c.z / len2, c.w / len2);
}

float3 Quaternion::Rotate(const float3& vector) const {
	Quaternion qv(vector.x, vector.y, vector.z, 0);
	Quaternion r = (*this) * qv * Inverse();
	return float3(r.x, r.y, r.z);
}

float3 Quaternion::Euler() const {
	Quaternion q = this->Normalized();

	float3 euler;

	// X
	float sinr_cosp = 2.0f * (q.w * q.x + q.y * q.z);
	float cosr_cosp = 1.0f - 2.0f * (q.x * q.x + q.y * q.y);
	euler.x = std::atan2(sinr_cosp, cosr_cosp);

	// Y
	float sinp = 2.0f * (q.w * q.y - q.z * q.x);
	if (std::abs(sinp) >= 1.0f) {
		euler.y = std::copysign(Mathex::PI / 2.0f, sinp);
	}
	else {
		euler.y = std::asin(sinp);
	}

	// Z
	float siny_cosp = 2.0f * (q.w * q.z + q.x * q.y);
	float cosy_cosp = 1.0f - 2.0f * (q.y * q.y + q.z * q.z);
	euler.z = std::atan2(siny_cosp, cosy_cosp);

	return euler;
}