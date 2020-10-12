#include "Quaternion.h"

namespace Game {

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

	std::string Quaternion::ToString() {
		std::stringstream ss;
		ss << "(x: " << std::to_string(x) << " , y: " << std::to_string(y) + " , z: " << std::to_string(z) << " , w: " << std::to_string(w) << ")\n";
		return ss.str();
	}
}