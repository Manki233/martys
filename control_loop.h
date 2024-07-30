#ifndef CONTROL_LOOP
#define CONTROL_LOOP

#include "configs.h"
#include "main_loops.h"
#include "render.h"

using namespace std;

void (*loop_functions [ARRAY_MAX]) (); 
int top = 0;

void add_loop (void (*functions) ()) {
	loop_functions [++ top] = functions;
}

void update () {
	for (int i = 1 ; i <= top ; i ++) {
		loop_functions [i] ();
	}
}

#endif