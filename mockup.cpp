#include "Viewer.hpp"
#include "World.hpp"
#include "Field.hpp"
#include "Ball.hpp"
#include "Robot.hpp"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	World w;
	Viewer v(w);
	
	auto& f = w.addThing(std::make_unique<Field>());
	auto& b = w.addThing(std::make_unique<Ball>());
	auto& r = w.addThing(std::make_unique<Robot>());

	while (!v.done()) {
		auto t = std::chrono::steady_clock::now();
		w.step();
		v.frame();
		std::this_thread::sleep_until(t + std::chrono::milliseconds(40));
	}
}
