#include "Vec.h"

class Obstacle{
	public:
	
    float red, green, blue, dx;
    
    virtual bool contains(Vec& v) = 0;
    
    virtual void draw() = 0;
    
};
