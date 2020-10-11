#pragma once

#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"

class Quaternion {
	public:
		float x; // imaginary part
		float y;
		float z;
		float w; // real part

		Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
		Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
		Quaternion(float x, float y, float z) : x(x), y(y), z(z), w(1.0f) { }
		Quaternion(const Vector3& V) : x(V.x), y(V.y), z(V.z), w(1.0f) { }

		Quaternion& operator=(const Quaternion& V);
		Quaternion  operator+(const Quaternion& V) const;
		Quaternion  operator-(const Quaternion& V) const;
		Quaternion  operator*(const Quaternion& V) const;
		Quaternion& operator*=(const Quaternion & V);
};

inline Quaternion& Quaternion::operator=(const Quaternion& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	w = V.w;
	return *this;
}

inline Quaternion& Quaternion::operator*=(const Quaternion& V)
{
	return (*this = V * (*this));
}

inline Quaternion Quaternion::operator*(const Quaternion& V) const
{
	Quaternion r;

	r.w = (V.w * w) - (V.x * x) - (V.y * y) - (V.z * z);
	r.x = (V.w * x) + (V.x * w) + (V.y * z) - (V.z * y);
	r.y = (V.w * y) + (V.y * w) + (V.z * x) - (V.x * z);
	r.z = (V.w * z) + (V.z * w) + (V.x * y) - (V.y * x);

	return r;
}


inline Quaternion Quaternion::operator+(const Quaternion& V) const
{
	return Quaternion(x + V.x, y + V.y, z + V.z, w + V.w);
}

inline Quaternion Quaternion::operator-(const Quaternion& V) const
{
	return Quaternion(x - V.x, y - V.y, z - V.z, w - V.w);
}


#endif QUATERNION_H // QUATERNION_H
