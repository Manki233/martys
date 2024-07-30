#ifndef OBJECT
#define OBJECT

#include "configs.h"
#include <iostream>
#include "sprite.h"
#include <cmath>
#include "main_loops.h"

class CObject;
CObject *get_object (string str);

class CObject {
	public:
		CObject (double _x, double _y, string _name, CSprite spr, double _angle = 90, double _zoom = 100, bool _show = true) {
			x = _x;
			y = _y;
			angle = _angle;
			name = _name;
			show = _show;
			sprites = spr;
			zoom = _zoom;
		}
		double x, y, angle, zoom;
		string name;
		bool show;
		double width, height;
		
		CSprite sprites;
		
		void update () {
			if (show) {
				draw ();
			}
			
			width = sprites. width [sprites. index];
			height = sprites. height [sprites. index];
		}
		
		void draw (PIMAGE target = NULL) {
			sprites. put_image (x, y, angle, zoom, target);
		}
		
		void move (int step) {
			angle += 90;
			x += step * sin (angle * PI / 180);
			y += step * cos (angle * PI / 180);
			angle -= 90;
		}
		
		bool Collide (CObject *b) {
			for (int i = 0 ; i < ww ; i ++) {
				for (int j = 0 ; j < wh ; j ++) {
					putpixel (i, j, BLACK, coltmp1);
					putpixel (i, j, BLACK, coltmp2);
				}
			}
			
			draw (coltmp1);
			b -> draw (coltmp2);
			
			for (int i = 0 ; i < ww ; i ++) {
				for (int j = 0 ; j < wh ; j ++) {
					if (getpixel (i, j, coltmp1) != BLACK &&
						getpixel (i, j, coltmp2) != BLACK) {
							return true;
					}
				}
			}
			
			return false;
		}
		
		bool mouseclick () {
			return Collide (get_object ("mouse"));
		}
};

#endif