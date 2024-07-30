#ifndef SPRITE
#define SPRITE

#include "configs.h"
#include "render.h"

#include "main_loops.h"

#define IMAGE_MAX 255

class CSprite {
	public:
		CSprite () {
			image [0] = newimage ();
			width [0] = getwidth (image [0]);
			height [0] = getheight (image [0]);
			index = 0;
		}
		
		CSprite (PIMAGE p) {
			image [0] = p;
			width [0] = getwidth (image [0]);
			height [0] = getheight (image [0]);
			index = 0;
		}
		
		CSprite (string path) {
			image [0] = newimage ();
			get_image (path);
			
			width [0] = getwidth (image [0]);
			height [0] = getheight (image [0]);
			index = 0;
		}
		
		PIMAGE image [IMAGE_MAX];
		double width [IMAGE_MAX], height [IMAGE_MAX];
		int index;
		
		void next () {
			index ++;
		}
		
		void switch_index (int x) {
			index = x;
		}
		
		void get_image (string path, int index = 0) {
			getimage (image [index], path. data ());
		}
		
		void put_image (double x, double y, double angle, double zoom, PIMAGE target = NULL) {
			pRender -> Sprite (image [index], x, y, width [index], height [index], zoom, angle, target);
		}
};

#endif