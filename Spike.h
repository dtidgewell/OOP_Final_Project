#include "Object.h"
#include "Vec.h"
#include <vector>
#include <cmath>

class Spike: public Object{
    public:
    float left, right, top, bottom, middle;
    std::vector<Vec*> edges;
	//std::vector<Vec> edges; //bottom Left,  Bottom Right,  Top Middle
	

    Spike(){
        left = 1.0;
        right = 1.15;
        top = -0.5;
        middle = 1.1;
        bottom = -0.7;

        for(int i = 0; i < 4; i++){edges.push_back(new Vec(0,0));}
		edges[0] = new Vec(left, bottom);
		edges[1] = new Vec(left, top);
		edges[2] = new Vec(right, top);
		edges[3] = new Vec(right, bottom);

        red = 0.0;
        green = 0.0;
        blue = 1.0;
        dx = -0.01;
    }
    
    Spike(float l, float r, float t,float m, float b, float rd, float g, float bl, float d){
        left = l;
        right = r;
        top = t;
        middle = m;
        bottom = b;

        for(int i = 0; i < 4; i++){edges.push_back(new Vec(0,0));}
		edges[0] = new Vec(left, bottom);
		edges[1] = new Vec(left, top);
		edges[2] = new Vec(right, top);
		edges[3] = new Vec(right, bottom);

        red = rd;
        green = g;
        blue = bl;
        dx = d;
    }
    
    int contains(Object& p){


			if(right > p.edges[0]->x && left < p.edges[0]->x && bottom < p.edges[0]->y && top > p.edges[0]->y
			|| right > p.edges[1]->x && left < p.edges[1]->x && bottom < p.edges[1]->y && top > p.edges[1]->y
			|| right > p.edges[2]->x && left < p.edges[2]->x && bottom < p.edges[2]->y && top > p.edges[2]->y
			|| right > p.edges[3]->x && left < p.edges[3]->x && bottom < p.edges[3]->y && top > p.edges[3]->y)
		{
			return 1;
		}
		

		/*for (int i = 0; i < edges.size(); i++) {
			for (int j = 0; j < p.edges.size(); j++) {
				float distance = sqrt((pow((edges[i]->x - p.edges[j]->x),2) + pow((edges[i]->y - p.edges[j]->y),2)));
				if (distance < .15) { return 1; }
			}
		}*/
		return 0;
    }

	bool pass() { 
		if (right < -.71) {
			return true;
		}
		else {
			return false;
		}
	}

    
	void draw() {

		edges[0] = new Vec(left, bottom);
		edges[1] = new Vec(left, top);
		edges[2] = new Vec(right, top);
		edges[3] = new Vec(right, bottom);

		left += dx;
		middle += dx;
		right += dx;
		glColor3f(this->red, this->green, this->blue);
		glBegin(GL_POLYGON);
		glVertex2d(left, bottom);
		glVertex2d(left, top);
		glVertex2d(right, top);
		glVertex2d(right, bottom);
		glEnd();
		float y = bottom;
	}
};
