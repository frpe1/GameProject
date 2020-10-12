#include "Mathf.h"


namespace Game {
	
	float const Mathf::EPSILON = 1.401298f;

	float const Mathf::M_PI = 3.14159265359f;

	float const Mathf::M_PI_2 = 1.57079632679f;

	float Mathf::Sqrt(float f) { return sqrtf(f); }

	float Mathf::Abs(float f) { return fabsf(f); }

	float Mathf::Sign(float f) { return f >= 0.0f ? 1.0f : -1.0f; }

	float  Mathf::Ceil(float f) { return ceil(f); }

	float  Mathf::Floor(float f) { return floor(f); }

	float Mathf::Min(float a, float b) { return a < b ? a : b; }

	float Mathf::Max(float a, float b) { return a > b ? a : b; }

	float Mathf::Clamp(float value, float min, float max) {
		if (value < min)
			value = min;
		else if (value > max)
			value = max;
		return value;
	}

	float Mathf::Clamp01(float value)
	{
		if (value < 0.0f)
			return 0.0f;
		else if (value > 1.0f)
			return 1.0f;
		else
			return value;
	}

	float Mathf::Lerp(float a, float b, float t)
	{
		return a + (b - a) * Mathf::Clamp01(t);
	}

	float  Mathf::InverseLerp(float a, float b, float value)
	{
		if (a != b)
			return  Mathf::Clamp01((value - a) / (b - a));
		else
			return 0.0f;
	}

	float Mathf::MoveTowards(float current, float target, float maxDelta)
	{
		if (Mathf::Abs(target - current) <= maxDelta)
			return target;
		return current + Mathf::Sign(target - current) * maxDelta;
	}

	float Mathf::SmoothDamp(float current, float target, float currentVelocity, float smoothTime, float maxSpeed, float deltaTime) {

		smoothTime = Mathf::Max(0.0001f, smoothTime);
		float omega = 2.0f / smoothTime;

		float x = omega * deltaTime;
		float exp = 1.0f / (1.0f + x + 0.48f * x * x + 0.235f * x * x * x);
		float change = current - target;
		float originalTo = target;

		float maxChange = maxSpeed * smoothTime;
		change = Mathf::Clamp(change, -maxChange, maxChange);
		target = current - change;

		float temp = (currentVelocity + omega * change) * deltaTime;
		currentVelocity = (currentVelocity - omega * temp) * exp;
		float output = target + (change + temp) * exp;

		if (originalTo - current > 0.0f == output > originalTo)
		{
			output = originalTo;
			currentVelocity = (output - originalTo) / deltaTime;
		}

		return output;
	}

	// =========================================================================================== //

	namespace Ease {


		// Modeled after the line y = x
		float LinearInterpolation(float p)
		{
			return p;
		}

		// Modeled after the parabola y = x^2
		float QuadraticEaseIn(float p)
		{
			return p * p;
		}

		// Modeled after the parabola y = -x^2 + 2x
		float QuadraticEaseOut(float p)
		{
			return -(p * (p - 2.0f));
		}

		// Modeled after the piecewise quadratic
		// y = (1/2)((2x)^2)             ; [0, 0.5)
		// y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
		float QuadraticEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 2.0f * p * p;
			}
			else
			{
				return (-2.0f * p * p) + (4.0f * p) - 1.0f;
			}
		}

		// Modeled after the cubic y = x^3
		float CubicEaseIn(float p)
		{
			return p * p * p;
		}

		// Modeled after the cubic y = (x - 1)^3 + 1
		float CubicEaseOut(float p)
		{
			float f = (p - 1.0f);
			return f * f * f + 1.0f;
		}

		// Modeled after the piecewise cubic
		// y = (1/2)((2x)^3)       ; [0, 0.5)
		// y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
		float CubicEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 4.0f * p * p * p;
			}
			else
			{
				float f = ((2.0f * p) - 2.0f);
				return 0.5f * f * f * f + 1.0f;
			}
		}

		// Modeled after the quartic x^4
		float QuarticEaseIn(float p)
		{
			return p * p * p * p;
		}

		// Modeled after the quartic y = 1 - (x - 1)^4
		float QuarticEaseOut(float p)
		{
			float f = (p - 1.0f);
			return f * f * f * (1.0f - p) + 1.0f;
		}

		// Modeled after the piecewise quartic
		// y = (1/2)((2x)^4)        ; [0, 0.5)
		// y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
		float QuarticEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 8.0f * p * p * p * p;
			}
			else
			{
				float f = (p - 1.0f);
				return -8.0f * f * f * f * f + 1.0f;
			}
		}

		// Modeled after the quintic y = x^5
		float QuinticEaseIn(float p)
		{
			return p * p * p * p * p;
		}

		// Modeled after the quintic y = (x - 1)^5 + 1
		float QuinticEaseOut(float p)
		{
			float f = (p - 1.0f);
			return f * f * f * f * f + 1.0f;
		}

		// Modeled after the piecewise quintic
		// y = (1/2)((2x)^5)       ; [0, 0.5)
		// y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
		float QuinticEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 16.0f * p * p * p * p * p;
			}
			else
			{
				float f = ((2.0f * p) - 2.0f);
				return  0.5f * f * f * f * f * f + 1.0f;
			}
		}

		// Modeled after quarter-cycle of sine wave
		float SineEaseIn(float p)
		{
			return sin((p - 1.0f) * Mathf::M_PI_2) + 1.0f;
		}

		// Modeled after quarter-cycle of sine wave (different phase)
		float SineEaseOut(float p)
		{
			return sin(p * Mathf::M_PI_2);
		}

		// Modeled after half sine wave
		float SineEaseInOut(float p)
		{
			return 0.5f * (1.0f - cos(p * Mathf::M_PI));
		}

		// Modeled after shifted quadrant IV of unit circle
		float CircularEaseIn(float p)
		{
			return 1.0f - sqrt(1.0f - (p * p));
		}

		// Modeled after shifted quadrant II of unit circle
		float CircularEaseOut(float p)
		{
			return sqrt((2.0f - p) * p);
		}

		// Modeled after the piecewise circular function
		// y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5)
		// y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1]
		float CircularEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 0.5f * (1.0f - sqrt(1.0f - 4.0f * (p * p)));
			}
			else
			{
				return 0.5f * (sqrt(-((2.0f * p) - 3.0f) * ((2.0f * p) - 1.0f)) + 1.0f);
			}
		}

		// Modeled after the exponential function y = 2^(10(x - 1))
		float ExponentialEaseIn(float p)
		{
			return (p == 0.0f) ? p : powf(2.0f, 10.0f * (p - 1.0f));
		}

		// Modeled after the exponential function y = -2^(-10x) + 1
		float ExponentialEaseOut(float p)
		{
			return (p == 1.0f) ? p : 1.0f - powf(2.0f, -10.0f * p);
		}

		// Modeled after the piecewise exponential
		// y = (1/2)2^(10(2x - 1))         ; [0,0.5)
		// y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1]
		float ExponentialEaseInOut(float p)
		{
			if (p == 0.0f || p == 1.0f) return p;

			if (p < 0.5f)
			{
				return 0.5f * powf(2.0f, (20.0f * p) - 10.0f);
			}
			else
			{
				return -0.5f * powf(2.0f, (-20.0f * p) + 10.0f) + 1.0f;
			}
		}

		// Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))
		float ElasticEaseIn(float p)
		{
			return sin(13.0f * Mathf::M_PI_2 * p) * powf(2.0f, 10.0f * (p - 1.0f));
		}

		// Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
		float ElasticEaseOut(float p)
		{
			return sin(-13.0f * Mathf::M_PI_2 * (p + 1.0f)) * powf(2.0f, -10.0f * p) + 1.0f;
		}

		// Modeled after the piecewise exponentially-damped sine wave:
		// y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5)
		// y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1]
		float ElasticEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 0.5f * sin(13.0f * Mathf::M_PI_2 * (2.0f * p)) * powf(2.0f, 10.0f * ((2.0f * p) - 1.0f));
			}
			else
			{
				return 0.5f * (sin(-13.0f * Mathf::M_PI_2 * ((2.0f * p - 1.0f) + 1.0f)) * powf(2.0f, -10.0f * (2.0f * p - 1.0f)) + 2.0f);
			}
		}

		// Modeled after the overshooting cubic y = x^3-x*sin(x*pi)
		float BackEaseIn(float p)
		{
			return p * p * p - p * sin(p * Mathf::M_PI);
		}

		// Modeled after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi))
		float BackEaseOut(float p)
		{
			float f = (1.0f - p);
			return 1 - (f * f * f - f * sin(f * Mathf::M_PI));
		}

		// Modeled after the piecewise overshooting cubic function:
		// y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5)
		// y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1]
		float BackEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				float f = 2.0f * p;
				return 0.5f * (f * f * f - f * sin(f * Mathf::M_PI));
			}
			else
			{
				float f = (1.0f - (2.0f * p - 1.0f));
				return 0.5f * (1.0f - (f * f * f - f * sin(f * Mathf::M_PI))) + 0.f;
			}
		}

		float BounceEaseIn(float p)
		{
			return 1.0f - BounceEaseOut(1.0f - p);
		}

		float BounceEaseOut(float p)
		{
			if (p < 4.0f / 11.0f)
			{
				return (121.0f * p * p) / 16.0f;
			}
			else if (p < 8.0f / 11.0f)
			{
				return (363.0f / 40.0f * p * p) - (99.0f / 10.0f * p) + 17.0f / 5.0f;
			}
			else if (p < 9.0f / 10.0f)
			{
				return (4356.0f / 361.0f * p * p) - (35442.0f / 1805.0f * p) + 16061.0f / 1805.0f;
			}
			else
			{
				return (54.0f / 5.0f * p * p) - (513.0f / 25.0f * p) + 268.0f / 25.0f;
			}
		}

		float BounceEaseInOut(float p)
		{
			if (p < 0.5f)
			{
				return 0.5f * BounceEaseIn(p * 2.0f);
			}
			else
			{
				return 0.5f * BounceEaseOut(p * 2.0f - 1.0f) + 0.5f;
			}
		}
	}

}