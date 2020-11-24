#include "Viewer.h"
#include "World.h"
#include "Field.h"
#include "Ball.h"
#include "Robot.h"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	World w;
	Viewer v(w);
	
	w.addThing(std::make_unique<Field>());
	w.addThing(std::make_unique<Robot>());
	w.addBall(std::make_unique<Ball>());

	while (!v.done()) {
		auto t = std::chrono::steady_clock::now();
		w.step();
		v.frame();
		std::this_thread::sleep_until(t + std::chrono::milliseconds(40));
	}
}
