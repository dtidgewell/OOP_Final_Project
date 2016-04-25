class Spike: public Obstacle{
    public:
    float left, right, top, bottom, middle;
    
    Spike(){
        left = 1.0;
        right = 1.2;
        top = -0.5;
        middle = 1.1;
        bottom = -0.7;
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
        red = rd;
        green = g;
        blue = bl;
        dx = d;
    }
    
    bool contains(Vec& v){
        return false;
    }
    
    
    void draw(){
        left += dx;
        middle += dx;
        right += dx;
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_TRIANGLES);
            glVertex2d (left, bottom );
            glVertex2d ( right, bottom );
            glVertex2d ( middle, top );
        glEnd();
    }
};