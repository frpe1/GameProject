#pragma once

#ifndef QUATERNION_H
#define QUATERNION_H

#include <string>
#include <sstream>

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

		std::string ToString();
};



#endif QUATERNION_H // QUATERNION_H
