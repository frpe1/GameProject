#pragma once

#ifndef GAME_TIME_H
#define GAME_TIME_H

#include <string>
#include <sstream>
#include <time.h>
#include <chrono>

namespace Game {

	/// <summary>
	/// Time class with static functions. 
	/// Works with c++11 standard
	/// </summary>
	class Time
	{
		public:

			Time() {

			}

			/// <summary>
			/// The completion time in seconds since the last frame (Read Only)
			/// </summary>
			/// <returns></returns>
			static long deltaTime() {
				
				previousTime = currentTime;
				currentTime = std::chrono::high_resolution_clock::now(); // std::chrono::steady_clock::now();

				return std::chrono::duration_cast<std::chrono::microseconds>(currentTime - previousTime).count();
			}

		private:
			static std::chrono::steady_clock::time_point previousTime;
			static std::chrono::steady_clock::time_point currentTime;
	};


}


#endif GAME_TIME_H // GAME_TIME_H

