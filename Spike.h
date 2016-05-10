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
        right = 1.2;
        top = -0.5;
        middle = 1.1;
        bottom = -0.7;

        for(int i = 0; i < 3; i++){edges.push_back(new Vec(0,0));}
		edges[0] = (new Vec (left, bottom));
		edges[1] = (new Vec (right, bottom));
		edges[2] = (new Vec (top, middle));

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

        for(int i = 0; i < 3; i++){edges.push_back(new Vec(0,0));}
		edges[0] = (new Vec (left, bottom));
		edges[1] = (new Vec (right, bottom));
		edges[2] = (new Vec (top, middle));

        red = rd;
        green = g;
        blue = bl;
        dx = d;
    }
    
    int contains(Object& p){
		float max = 0;
		for (int i = 0; i < edges.size(); i++) {
			for (int j = 0; j < p.edges.size(); j++) {
				float distance = sqrt((pow((edges[i]->x - p.edges[j]->x),2) + pow((edges[i]->y - p.edges[j]->y),2)));
				//std::cout << distance << " ";
				if (distance > max) { max = distance; }
			}
			//std::cout << max << " ";
			if (max < .3) { return 1; }
			max = 0;
		}
		return 0;
    }
    
	void draw() {

		edges[0] = (new Vec(left, bottom));
		edges[1] = (new Vec(right, bottom));
		edges[2] = (new Vec(top, middle));

		left += dx;
		middle += dx;
		right += dx;
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2d(left, bottom);
		glVertex2d(right, bottom);
		glVertex2d(middle, top);
		glEnd();
		float y = bottom;
	}
};
