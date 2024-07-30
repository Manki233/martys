#ifndef OBJECT_SYSTEM
#define OBJECT_SYSTEM

#include "configs.h"
#include "object.h"

#include <map>

class CObject;

CObject *pObjs [ARRAY_MAX];
int obj_count = 0;

map <string, CObject *> object_name_mp;

CObject *get_object (string str) {
	return object_name_mp [str];
}

void add_object (CObject *obj) {
	int choice = obj_count + 1;
	
	for (int i = 1 ; i <= obj_count ; i ++) {
		if (!pObjs [i]) {
			choice = i;
		}
	}
	
	if (choice == obj_count + 1)
		obj_count ++;
	
	pObjs [obj_count] = obj;
	object_name_mp [obj -> name] = obj;
}

void update_object () {
	for (int i = 1 ; i <= obj_count ; i ++) {
		if (pObjs [i]) {
			pObjs [i] -> update ();
		}
	}
}

PIMAGE temp1, temp2;

void add_update_object () {
	temp1 = newimage (ww, wh);
	temp2 = newimage (ww, wh);
	add_loop (update_object);
}

#endif