#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

class StopWatch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	StopWatch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~StopWatch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};