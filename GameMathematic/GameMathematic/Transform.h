#pragma once


#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector3.h"

namespace Game {
	class Transform
	{

	public:
		Transform* parent; // Reference to parent Transform
		Vector3<float> position;
		Vector3<float> rotation; // TODO: Make it to Quaternion

		// Accessors
		Vector3<float> Forward();
		Vector3<float> Up();
		Vector3<float> Right();

		Transform();
		~Transform();

		void Update(float dt);
	protected:
		Vector3<float> _forward;
		Vector3<float> _up;
		Vector3<float> _right;

	};
}


#endif TRANSFORM_H // TRANSFORM_H
