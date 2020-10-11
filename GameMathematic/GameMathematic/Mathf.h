#pragma once

#include <cmath>

#ifndef MATHF_H
#define MATHF_H

class Mathf
{
	public:
		static float const EPSILON;

		static float Sqrt(float f);
		static float Abs(float f);
		static float Sign(float f);

		static float Ceil(float f);
		static float Floor(float f);

		static float Min(float a, float b);
		static float Max(float a, float b);

		static float Clamp(float value, float min, float max);
		static float Clamp01(float value);
		static float Lerp(float a, float b, float t);
		static float InverseLerp(float a, float b, float value);
		static float MoveTowards(float current, float target, float maxDelta);
        static float SmoothDamp(float current, float target, float currentVelocity, float smoothTime, float maxSpeed, float deltaTime);

};

#endif MATHF_H // MATHF_H

