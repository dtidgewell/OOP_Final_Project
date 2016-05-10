#ifndef OBJECT_H
#define OBJECT_H

#include "Vec.h"
#include <vector>

//enum collision {NONE_COLLISION, FATAL_COLLISION, LAND_COLLISION};
//						0				1				2
class Object{
	public:
	
    float red, green, blue, dx,dy;

    std::vector<Vec*> edges;
    
    virtual int contains(Object& p) = 0;
    
    virtual void draw() = 0;

	virtual bool pass() = 0;

    
};

#endif