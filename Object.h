#include "Vec.h"
#include <vector>
#include <math.h>
#include<Player.h>


class Object{
	public:
	
    float red, green, blue, dx,dy;
	std::vector<Vec> edges;
    virtual bool contains(Player&) = 0;
    
    virtual void draw() = 0;
    
};
