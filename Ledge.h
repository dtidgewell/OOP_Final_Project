//#include "Player.h"
#include "Object.h"

class Ledge : public Object{
	public:
		float left, right, top, bottom;
		Ledge()
		{
			left = 2.0;
			right = 2.3;
			top = -0.5;
			bottom = -0.7;

			red = 0.0;
			green = 1.0;
			blue = 0.0;
			dx = -0.01;
		}

		Ledge(float l, float r, float t, float b, float rd, float gn, float bl, float d)
		{
			left = l;
			right = r;
			top = t;
			bottom = b;

			red = rd;
			green = gn;
			blue = bl;
			dx = d;
		}
		
		int contains(Object& p) {
			/*
			Player temp = (Player*)p;
			if(left < p.x && top > p.y){return FATAL_COLLISION;}
			if (left < p.x && right > p.x && top > p.y) { return LAND_COLLISION; }
			*/
				return 0;
		} 
	
		bool pass() { return false; }
		
		void draw()
		{
			left += dx;
			right += dx;
			//top += dx;
			//bottom += dx;

			glColor3f(0.0, 1.0, 0.0);
	
			glBegin(GL_POLYGON);
				glVertex2d(left, bottom);
				glVertex2d(left, top);
				glVertex2d(right, top);
				glVertex2d(right, bottom);
			glEnd();
		}
};