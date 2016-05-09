#include "Player.h"

class Spike: public Object{
    public:
    float left, right, top, bottom, middle;
	//std::vector<Vec> edges; //bottom Left,  Bottom Right,  Top Middle
	

    Spike(){
        left = 1.0;
        right = 1.2;
        top = -0.5;
        middle = 1.1;
        bottom = -0.7;

		edges[0] = (Vec (left, bottom));
		edges[1] = (Vec (right, bottom));
		edges[2] = (Vec (top, middle));

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

		edges[0] = (Vec (left, bottom));
		edges[1] = (Vec (right, bottom));
		edges[2] = (Vec (top, middle));

        red = rd;
        green = g;
        blue = bl;
        dx = d;
    }
    
    bool contains(Player& p){
		for (int i = 0; i < edges.size(); i++) {
			for (int j = 0; j < p.edges.size(); j++) {
				float distance = sqrt(pow((edges[i].x - p.edges[j].x),2) - pow((edges[i].y - p.edges[j].y),2));
				if (distance < .2) { return true; }
			}
		}
		return false;
    }
    
    
	void draw() {
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
