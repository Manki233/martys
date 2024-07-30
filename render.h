#ifndef RENDER
#define RENDER

#include <graphics.h>		
#include <string>
using namespace std;

class CRender {
	public:
		void Create (int width, int heidth, string name) {
			initgraph (width, heidth);
			setcaption (name. data ());
		}
		
		void Sprite (PIMAGE image, int x, int y, int w, int h, double zoom, double angle, PIMAGE target = NULL) {
			zoom /= 100;
			putimage_rotatezoom (target, image, x, y, 0.5, 0.5, angle / 180 * PI, zoom, 0, -1, 1);
		}
};

CRender *pRender;
#endif