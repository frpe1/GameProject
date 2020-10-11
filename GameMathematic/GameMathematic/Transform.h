#pragma once


#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector3.h"

class Transform
{
	public:
		Transform *parent; // Reference to parent Transform
		Vector3 position;
		Vector3 rotation; // TODO: Make it to Quaternion

		// Accessors
		Vector3 Forward();
		Vector3 Up();
		Vector3 Right();

		Transform();
		~Transform();

		void Update(float dt);
	protected:
		Vector3 _forward;
		Vector3 _up;
		Vector3 _right;
};


#endif TRANSFORM_H // TRANSFORM_H
