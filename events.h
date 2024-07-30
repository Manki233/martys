#ifndef EVENTS
#define EVENTS

// Keybroad events

#include "configs.h"
#include "time.h"
#include "main_loops.h"
#include "object.h"

#include <graphics.h>

bool key_sta [255];

#define getkey(x) (GetAsyncKeyState(x)&0x8000)

void update_key () {
	if (int (tick (). tick) % 3 <= 1)
		return ;
		
	memset (key_sta, 0, sizeof key_sta);
		
	for (int i = 0 ; i < 255 ; i ++) {
		key_sta [i] = getkey (i);
	}
}

void add_update_key () {
	add_loop (update_key);
}

// Mouse events

bool mouse_isdown_left;
bool mouse_isdown_right;
int mouse_x, mouse_y;

CObject *mouse = new CObject (0, 0, "mouse", CSprite (newimage (5, 5)));

void update_mouse () {
	mousepos (&mouse_x, &mouse_y);
	
	mouse_isdown_left = keystate (key_mouse_l);
	mouse_isdown_right = keystate (key_mouse_r);
	
	CObject *pMouse = get_object ("mouse");
	pMouse -> x = mouse_x;
	pMouse -> y = mouse_y;
	putpixel (1, 1, WHITE, pMouse -> sprites. image [0]);
}

void add_update_mouse () {
	add_loop (update_mouse);
	add_object (mouse);
}
#endif