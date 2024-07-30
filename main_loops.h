#ifndef MAINLOOP
#define MAINLOOP

#include "configs.h"
#include "control_loop.h"
#include <iostream>

#include "render.h"

using namespace std;

void update ();

int ww, wh;
PIMAGE coltmp1, coltmp2;

class CLoop {
	bool whiling;
	
    public:
        CLoop (int width, int heidth, string name = "Martys Program") {
            whiling = false;
            
            pRender -> Create (width, heidth, name);
            
            ww = width;
            wh = heidth;
            coltmp1 = newimage (ww, wh);
            coltmp2 = newimage (ww, wh);
        }
        
        void start () {
        	whiling = true;
        	
        	while (whiling) {
        		cleardevice ();
        		
        		call_update ();
        		
        		delay_fps (60);
			}
		}
		
		void stop_loop () {
			whiling = false;
		}
		
		void continue_loop () {
			whiling = true;
		}
		
		void call_update () {
			update ();
		}
};

#endif