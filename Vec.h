#include <ctime> 


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

class Rect
{
public:

	float Ux = 0;
	float Uy = 0;
	float x = 0;
	float y = 0;
	float xOrgin = 0;
	float yOrgin = 0;
	float URx = 0;
	float URy = 0;
	float width = 0;
	float height = 0;

Rect(float UX, float UY, float X, float Y) {
	Ux = UX;
	Uy = UY;
	x = X;
	y = Y;

	xOrgin = Ux + x / 2;
	yOrgin = Uy - y / 2;
	URx = Ux + x;
	URy = Uy + y;
	width = abs(URx - Ux);
	height = abs(URy - Uy);

}

int h, m, s;

public:
	void get() {
		time_t t = time(NULL);
		tm* tm = localtime(&t); // returns pointer to a static object
		h = tm->tm_hour;
		m = tm->tm_min;
		s = tm->tm_sec;
	}

};

class Time {
	float h, m, s, ms;


public:
	void get() {
		time_t t = time(NULL);
		tm* tm = localtime(&t); // returns pointer to a static object
		h = tm->tm_hour;
		m = tm->tm_min;
		s = tm->tm_sec;
		t = clock() - t;
		ms = t / CLOCKS_PER_SEC;

	}
	float getMS() {
		return this->ms;
	}
};
