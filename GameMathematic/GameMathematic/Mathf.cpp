#include "Mathf.h"


float const Mathf::EPSILON = 1.401298f;

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