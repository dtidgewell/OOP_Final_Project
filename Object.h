#ifndef OBJECT_H
#define OBJECT_H

#include "Vec.h"
#include <vector>

class Object{
	public:
	
    float red, green, blue, dx,dy;
    
    std::vector<Vec*> edges;
    
    virtual bool contains(Object& p) = 0;
    
    virtual void draw() = 0;
    
};

#endif