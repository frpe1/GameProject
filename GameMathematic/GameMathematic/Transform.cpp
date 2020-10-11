#include "Transform.h"

Transform::Transform() { parent = NULL; position = Vector3<float>(); rotation = Vector3<float>(); _up = Vector3<float>::up; _forward = Vector3<float>::forward; _right = Vector3<float>::right; }
Transform::~Transform() {
	parent = NULL;
}

Vector3<float> Transform::Forward() {
	return _forward;
}

Vector3<float> Transform::Up() {
	return _up;
}

Vector3<float> Transform::Right() {
	return _right;
}

void Transform::Update(float dt) {
	// Calculate the local forward, up and right vector again
}
