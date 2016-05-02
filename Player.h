class Player: public Object{
public:
    
    float left, right, top, bottom;
    Player()
    {
        left = -0.5;
        right = -0.7;
        top = -0.5;
        bottom = -0.7;
        
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        dx = 0.0;
        dy = 0.0
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
    }
    
    bool contains(Vec& v)
    {
        return false;
    }
    
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