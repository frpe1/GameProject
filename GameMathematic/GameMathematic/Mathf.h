#pragma once



#ifndef MATHF_H
#define MATHF_H

#include <cmath>

namespace Game {

	/// <summary>
	/// Math class that contain static mathematic functions 
	/// </summary>
	class Mathf
	{
	public:
		static float const EPSILON;
		static float const M_PI_2;
		static float const M_PI;

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

	/// <summary>
	/// Ease functions, to be used for interpolation
	/// </summary>
	namespace Ease {

		// Linear interpolation (no easing)
		float LinearInterpolation(float p);

		// Quadratic easing; p^2
		float QuadraticEaseIn(float p);
		float QuadraticEaseOut(float p);
		float QuadraticEaseInOut(float p);

		// Cubic easing; p^3
		float CubicEaseIn(float p);
		float CubicEaseOut(float p);
		float CubicEaseInOut(float p);

		// Quartic easing; p^4
		float QuarticEaseIn(float p);
		float QuarticEaseOut(float p);
		float QuarticEaseInOut(float p);

		// Quintic easing; p^5
		float QuinticEaseIn(float p);
		float QuinticEaseOut(float p);
		float QuinticEaseInOut(float p);

		// Sine wave easing; sin(p * PI/2)
		float SineEaseIn(float p);
		float SineEaseOut(float p);
		float SineEaseInOut(float p);

		// Circular easing; sqrt(1 - p^2)
		float CircularEaseIn(float p);
		float CircularEaseOut(float p);
		float CircularEaseInOut(float p);

		// Exponential easing, base 2
		float ExponentialEaseIn(float p);
		float ExponentialEaseOut(float p);
		float ExponentialEaseInOut(float p);

		// Exponentially-damped sine wave easing
		float ElasticEaseIn(float p);
		float ElasticEaseOut(float p);
		float ElasticEaseInOut(float p);

		// Overshooting cubic easing; 
		float BackEaseIn(float p);
		float BackEaseOut(float p);
		float BackEaseInOut(float p);

		// Exponentially-decaying bounce easing
		float BounceEaseIn(float p);
		float BounceEaseOut(float p);
		float BounceEaseInOut(float p);
	}

}

#endif MATHF_H // MATHF_H

