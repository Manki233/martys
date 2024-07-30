#ifndef TIME
#define TIME

#include <ctime>

#define FPS 60

struct Tick {
	Tick (double _tk) {
		tick = _tk;
	}
	
	double tick;
	
	void set_ms (double ms) {
		tick = ms / 1000 * FPS;
	}
	
	double to_ms (double ms) {
		return tick / FPS * 1000;
	}
};

double start;
void init_clock () {
	start = clock ();
}

Tick tick () {
	Tick t = {0};
	t. set_ms ((clock () - start));
	
	return t; 
}

#endif