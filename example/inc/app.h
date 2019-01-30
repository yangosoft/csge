#ifndef APP_HPP
#define APP_HPP

#include <vector>
#include "core/window.h"

class App {
public:
	CSGE::Window& window;
	App(CSGE::Window& w): window(w) {}
	~App() = default;
	void run();
};

#endif
