#include "Vec.h"

class Object{
	public:
	
    float red, green, blue, dx,dy;
    
    virtual bool contains(Vec& v) = 0;
    
    virtual void draw() = 0;
    
};
