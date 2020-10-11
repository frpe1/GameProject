#include "Vector3.h"
#include "Mathf.h"
#include "Transform.h"


int main(int argc, char** argv) {

	Vector3 v1 = Vector3::forward;
	Vector3 v2 = v1.forward;
	/*
	Vector3 v3 = v1 + v2;

	std::cout << v1.ToString();
	std::cout << v2.ToString();
	std::cout << v3.ToString();

	Vector3 v4(1.0f, 0.0f, 1.0f);

	std::cout << v4.normalized().ToString();

	v1 = v4.normalized();
	std::cout << v1.ToString();

	std::cout << Mathf::Clamp(5, 1, 4);

	Vector3 r = Vector3::Normalize(v3);
	std::cout << r.ToString();

	Transform *transform = new Transform();

	std::cout << transform->Up().ToString();
	*/

	Vector3 v3 = v1 + v2 * 5 + Vector3(1,0,1) + Vector3::up;

	std::cout << v3.normalized().ToString();


	return 0;
}