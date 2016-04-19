class Vec{
    
public:
    float x, y;
    
    Vec(){
        x = 0;
        y = 0;
    }
    
    Vec(float  n, float m){
        x = n;
        y = m;
    }
    
    void add(Vec v){
        x += v.x;
        y += v.y;
    }
    
    void print(){
        std::cout << "(" << x << ", " << y << ")";
    }
    
};