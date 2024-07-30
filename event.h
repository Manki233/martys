#ifndef EVENT
#define EVENT

#include "configs.h"

class Event {
	public:
		bool (*trigger_function) (vector <int> args);
		void (*call_back) ();
		
		vector <int> args;
		
		void update () {
			if (trigger_function (args)) {
				call_back ();
				on_trigger ();
			}
		}
		
		virtual void on_trigger ();
};

#endif