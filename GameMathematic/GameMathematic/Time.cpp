#include "Time.h"

namespace Game {
	std::chrono::steady_clock::time_point Time::previousTime = std::chrono::high_resolution_clock::now();
	std::chrono::steady_clock::time_point Time::currentTime = std::chrono::high_resolution_clock::now();
}