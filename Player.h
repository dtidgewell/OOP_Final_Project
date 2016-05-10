#include <vector>
#include "Object.h"
#include "Vec.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Object{
public:
    
    float left, right, top, bottom;
    std::vector<Vec*> edges;
    
	//bottom Left, left top,  right top,  right bottom

    Player()
    {
        left = -0.5;
        right = -0.7;
        top = -0.5;
        bottom = -0.7;
        
        for(int i = 0; i < 4; i++){edges.push_back(new Vec(0,0));}
		edges[0] = new Vec(left, bottom);
		edges[1] = new Vec (left, top);
		edges[2] = new Vec (right, top);
		edges[3] = new Vec (right, bottom);
        
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        dx = 0.0;
        dy = 0.0;
    }
    
    Player(float l, float r, float t, float b, float rd, float gn, float bl, float d)
    {
        left = l;
        right = r;
        top = t;
        bottom = b;
        red = rd;
        green = gn;
        blue = bl;
        dx = d;

		edges[0] = new Vec(left, bottom);
		edges[1] = new Vec(left, top);
		edges[2] = new Vec(right, top);
		edges[3] = new Vec(right, bottom);

    }
    
    bool contains(Object& p)
    {
        std::cout << "ERROR:Calling contains() from Player" << std::endl;
        return false;
    }
    
    void draw()
    {
        left += dx;
        right += dx;
        //top += dx;
        //bottom += dx;
        
        glColor3f(1.0, 0.0, 0.0);
        
        glBegin(GL_POLYGON);
        glVertex2d(left, bottom);
        glVertex2d(left, top);
        glVertex2d(right, top);
        glVertex2d(right, bottom);
        glEnd();
    }
    
};

#endif