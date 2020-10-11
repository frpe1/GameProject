#include "Transform.h"

Transform::Transform() { parent = NULL; position = Vector3(); rotation = Vector3(); _up = Vector3::up; _forward = Vector3::forward; _right = Vector3::right; }
Transform::~Transform() {
	parent = NULL;
}

Vector3 Transform::Forward() {
	return _forward;
}

Vector3 Transform::Up() {
	return _up;
}

Vector3 Transform::Right() {
	return _right;
}

void Transform::Update(float dt) {
	// Calculate the local forward, up and right vector again
}