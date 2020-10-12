#include "Vector3.h"
#include "Mathf.h"
#include "Transform.h"
#include "Quaternion.h"
#include "Time.h"

using namespace Game;

int main(int argc, char** argv) {
	
	Vector3f v1 = Vector3f::forward;
	Vector3f v2 = v1.forward;
	Vector3f v3 = Vector3f::up;
	Vector3f v4 = Vector3f(4, 5, 2);


	/*
	Vector3f v3 = v1 + v2;

	std::cout << v1.ToString();
	std::cout << v2.ToString();
	std::cout << v3.ToString();

	Vector3f v4(1.0f, 0.0f, 1.0f);

	std::cout << v4.normalized().ToString();

	v1 = v4.normalized();
	std::cout << v1.ToString();

	std::cout << Mathf::Clamp(5, 1, 4);

	Vector3f r = Vector3f::Normalize(v3);
	std::cout << r.ToString();

	Transform *transform = new Transform();

	std::cout << transform->Up().ToString();
	*/

	/*
	Vector3f v4 = v1 + v2 * 5 + Vector3f(1,0,1) + Vector3f::up;

	std::cout << v4.normalized().ToString();

	Vector3f s = Vector3f(0, -1, 1);
	Vector3f t = Vector3f::Abs(s);
	std::cout << t.ToString();

	float q = Vector3f::Distance(s, t);
	std::cout << q << std::endl;

	Vector3f u = v1.inverse();
	std::cout << u.ToString();

	Vector3f v = Vector3f::Inverse(v1);
	std::cout << v4.normalized().ToString();

	Vector3f Z(5.0f);

	std::cout << Z.ToString();

	Quaternion q1 = Quaternion();

	std::cout << q1.ToString();
	
	Vector3f v1(0.1f, 1.0f, 2.4f);
	
	Vector3f u = Vector3f::one;
	std::cout << (-v1 + u).ToString();
	*/

	Vector3f r = Vector3f::Scale(v4, v2);

	std::cout << r.ToString();

	Transform* transform = new Transform();

	std::cout << transform->Up().ToString();

	Vector3f s = Vector3f::Lerp(Vector3f(0, 0, 0), Vector3f(2, 5, 5), 0.35f);

	std::cout << s.ToString();
	
	std::cout << Time::deltaTime() << std::endl;
	std::cout << Time::deltaTime() << std::endl;

	int j = 0;
	for (int i = 0; i < 1000000000; i++) {
		j = j + 1;
	}
	std::cout << Time::deltaTime() << std::endl;
	return 0;
}