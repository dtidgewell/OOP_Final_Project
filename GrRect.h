#ifndef GRS_H
#define GRS_H

#define _USE_MATH_DEFINES

#include <iostream> 
#include <string> 
#include <fstream> 
#include <iomanip> 
#include <stdlib.h> 
#include <bitset> 
#include <vector> 
#include <math.h> 
#include <algorithm> 
#include <cassert>

#include "app_window.h"

//#include "stdafx.h" //for Visual Studios 

using namespace std;

class GrTime {
public:
	int sec;
	int min;
	int hr;

	GrTime()
	{
		hr = 0;
		min = 0;
		sec = 0;
	}

	GrTime(int hours, int minutes, int seconds) {
		hr = hours;
		min = minutes;
		sec = seconds;
	}
	void add(GrTime temp) {
		sec += temp.sec;
		if (sec > 60) {
			min += 1;
			sec -= 60;
		}
		min += temp.min;
		if (min > 60) {
			hr += 1;
			min -= 60;
		}
		hr += temp.hr;
		if (hr > 24) {
			hr -= 24;
		}
	}

	int getHours() { return this->hr; }
	int getMinutes() { return this->min; }
	int getSeconds() { return this->sec; }

	void setHours(int h) { this->hr = h; }
	void setMinutes(int m) { this->min = m; }
	void setSeconds(int s) { this->sec = s; }

	void getAngles(float& a, float& b, float& c) {
		c = M_PI / 2 - M_PI / 30 * this->sec;
		//if (c <= 0) { c += 2 * M_PI; }
		b = M_PI / 2 - M_PI / 30 * this->min;
		//while (this->hr >= 12){this->hr += - 12;} // use while incase "24"
		//float offset = M_PI / 180 * (30 * this->min / 60);
		a = M_PI / 2 - M_PI / 6 * this->hr - M_PI / 180 * (30 * this->min / 60); //30 degree =1/12 of a circle
		if (a <= -M_PI) { a = 2 * M_PI + a; }

	}
	void getHourCoords(float& hx, float& hy) {
		//float a = M_PI / 2 - M_PI / 6 * this->hr - M_PI / 180 * (30 * this->min / 60); //30 degree =1/12 of a circle
		float a = M_PI / 2 - M_PI / 6 * this->hr - (M_PI / 6 * this->min / 60);
		//if (a <= -M_PI) { a = 2 * M_PI + a; }
		hx = cos(a);
		hy = sin(a);
	}

	void getMinuteCoords(float& mx, float& my) {
		float b = M_PI / 2 - M_PI / 30 * this->min;
		mx = cos(b);
		my = sin(b);
	}

	void getSecondsCoords(float& sx, float& sy) {
		float c = M_PI / 2 - M_PI / 30 * this->sec;
		sx = cos(c);
		sy = sin(c);
	}

	void get() {
		time_t t = time(NULL);
		tm* tm = localtime(&t); // returns pointer to a static object
		hr = tm->tm_hour;
		min = tm->tm_min;
		sec = tm->tm_sec;
	}
};


struct Vec
{
	float x;
	float y;

	Vec()
	{
		x = 0;
		y = 0;
	}


	Vec(float w, float h)
	{
		x = w;
		y = h;

	}
	void add(Vec u)
	{
		x += u.x;
		y += u.y;
	}
	void print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

};


class GrRect
{
public:

	float Ux = 0;
	float Uy = 0;
	float x = 0;
	float y = 0;

	float r;
	float g;
	float b;

	float plotA;
	float plotB;
	float plotC;
	float plotD;

	int plotCheck;

	bool focused;

	vector<Vec*> points;

	GrRect(float UX, float UY, float X, float Y) {
		Ux = UX;
		Uy = UY;
		x = X;
		y = Y;
		r = 1;
		g = 1;
		b = 1;

		plotCheck = 0;

		focused = false;
	}

	GrRect(float UX, float UY, float X, float Y, float R, float G, float B) {
		Ux = UX;
		Uy = UY;
		x = X;
		y = Y;
		r = R;
		g = G;
		b = B;

		plotCheck = 0;

		focused = false;
	}
	GrRect(float UX, float UY, float X, float Y, float R, float G, float B, float Aq, float Bq, float Cq) {
		Ux = UX;
		Uy = UY;
		x = X;
		y = Y;
		r = R;
		g = G;
		b = B;

		plotA = Aq;
		plotB = Bq;
		plotC = Cq;

		plotCheck = 1;
		
		focused = false;
	}

	GrRect(float UX, float UY, float X, float Y, float R, float G, float B, float Ac, float Bc, float Cc, float Dc) {
		Ux = UX;
		Uy = UY;
		x = X;
		y = Y;
		r = R;
		g = G;
		b = B;

		plotA = Ac;
		plotB = Bc;
		plotC = Cc;
		plotD = Dc;

		plotCheck = 2;

		focused = false;
	}

	GrRect(float UX, float UY, float X, float Y, float R, float G, float B, float clock) {
		Ux = UX;
		Uy = UY;
		x = X;
		y = Y;
		r = R;
		g = G;
		b = B;

		plotCheck = 3;

		focused = false;
	}

	bool contains(Vec z) {
		if (z.x > Ux && z.x < Ux + x && z.y>Uy - y && z.y < Uy)
		{
			//cout << "True" << endl;
			return true;
		}
		else
		{
			//cout << "False" << endl;
			return false;
		}

	}

	void GrPlotQuadratic(float a, float b, float c)
	{
		float xOrgin = Ux + x / 2;
		float yOrgin = Uy - y / 2;
		float resultY;
		float URx = Ux + x;
		float width = abs(URx - Ux);
		float start = 0 - width / 2;
		float end = width / 2;



		glBegin(GL_POINTS);

		glColor3f(1.0, 1.0, 1.0);

		for (float i = start; i < end; i += .01)
		{
			resultY = a*i*i + b*i + c;
			if ((i + xOrgin > Ux && i + xOrgin < Ux + x) && (resultY + yOrgin>Uy - y && resultY + yOrgin< Uy - 0.1))
			{
				glVertex2f(i + xOrgin, resultY + yOrgin);
			}

		}
		//cout << "start = " << start;
		//cout << "end = " << end << endl;
		//cout << "width = "<<width<<endl;
		//cout << "t.Ux = " << t.Ux << endl;
		//cout << "t.x = " << t.x << endl;
		glEnd();
	};

	void GrPlotCubic(float a, float b, float c, float d)
	{
		float xOrgin = Ux + x / 2;
		float yOrgin = Uy - y / 2;
		float resultY;
		float URx = Ux + x;
		float width = abs(URx - Ux);
		float start = 0 - width / 2;
		float end = width / 2;



		glBegin(GL_POINTS);

		glColor3f(1.0, 1.0, 1.0);

		for (float i = start; i < end; i += .01)
		{
			resultY = a*i*i*i + b*i*i + c*i+d;
			if ((i + xOrgin > Ux && i + xOrgin < Ux + x) && (resultY + yOrgin>Uy - y && resultY + yOrgin< Uy - 0.1))
			{
				glVertex2f(i + xOrgin, resultY + yOrgin);
			}

		}
		//cout << "start = " << start;
		//cout << "end = " << end << endl;
		//cout << "width = "<<width<<endl;
		//cout << "t.Ux = " << t.Ux << endl;
		//cout << "t.x = " << t.x << endl;
		glEnd();
	};

//-------------------------------------------------------------------------------------------------------------------//

	void Clock() {
		float xOrgin = Ux + x / 2;
		float yOrgin = Uy - y / 2 -.05;
		float URx = Ux + x;
		float URy = Uy + y -.05;
		float width = abs(URx - Ux);
		float height = abs(URy - Uy);
		float start = 0 - width / 2;
		float endW = width / 2;
		float endH = height / 2 -.025;
		float ratioX = endW;
		float ratioY = endH;
		/*
		glBegin(GL_LINES);

		glColor3f(1.0, 1.0, 1.0);

		glVertex2f(xOrgin, yOrgin+endH);
		glVertex2f(xOrgin + endW, yOrgin);

		glVertex2f(xOrgin + endW, yOrgin);
		glVertex2f(xOrgin, yOrgin - endH);

		glVertex2f(xOrgin, yOrgin - endH);
		glVertex2f(xOrgin - endW, yOrgin);

		glVertex2f(xOrgin - endW, yOrgin);
		glVertex2f(xOrgin, yOrgin + endH);
		*/
		GrTime temp;
		float hx, hy, mx, my, sx, sy;

		//draw circle
		glBegin(GL_POINTS);

		for (int i = 0; i <= 60; i ++)
		{
			temp.setMinutes(i);
			temp.getMinuteCoords(mx, my);
			if (i%5 == 0) {
				glColor3f(0.0, 0.0, 1.0);
				glVertex2f(mx*ratioX + xOrgin, my*ratioY + yOrgin);
			}
			else {
				glColor3f(1.0, 1.0, 1.0);
				glVertex2f(mx*ratioX + xOrgin, my*ratioY + yOrgin);
			}
		}

		glEnd();

		GrTime real;
		real.get();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		real.getHourCoords(hx, hy);
		real.getMinuteCoords(mx, my);
		real.getSecondsCoords(sx, sy);

		glBegin(GL_LINES);
		glVertex2f(xOrgin, yOrgin);
		glVertex2f(sx*ratioX + xOrgin, sy*ratioY + yOrgin);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrgin, yOrgin);
		glVertex2f((mx*ratioX*.75 + xOrgin), (my*ratioY*.75 + yOrgin));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrgin, yOrgin);
		glVertex2f((hx*ratioX*.5 + xOrgin), (hy*ratioY*.5 + yOrgin));
		glEnd();


	//cout << "hrs: " << real.hr << " min: " << real.min<< " sec: "<< real.sec << endl;
	};


//-------------------------------------------------------------------------------------------------------------------//

	void focus(bool on) {
		focused = on;
	}

	bool isFocused() {
		return focused;
	}

	void setUX(float X) {
		Ux = X;
	}

	void setUY(float Y) {
		Uy = Y;
	}
	void setX(float X) {
		x = X;
	}

	void setY(float Y) {
		y = Y;
	}


	float getX() {
		return Ux;
	}

	float getY() {
		return Uy;
	}


	virtual void draw() {
		//axis
		glBegin(GL_LINES);


		glColor3f(0.0, 0.0, 1.0);

		glVertex3f(-0.33333, -1.0, 0.0);
		glVertex3f(-0.33333, 1.0, 0.0);


		glVertex3f(.33333, -1.0, 0.0);
		glVertex3f(.33333, 1.0, 0.0);

		glEnd();

	

		//range check

		
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(-.5, 0.0);
		glVertex2f(0.5, 0.0);

		glVertex2f(0.0,0.5);
		glVertex2f(0.0,-.5);

		glEnd();
		

		if (plotCheck == 1)
		{
			GrPlotQuadratic(plotA, plotB, plotC);
		}
		if (plotCheck == 2)
		{
			GrPlotCubic(plotA, plotB, plotC, plotD);
		}
		if (plotCheck == 3)
		{
			Clock();
		}
		Vec tl, tr, br, bl;
		//GrRect * curr = *i;
		tl = Vec(Ux, Uy);
		tr = Vec(Ux + x, Uy);
		br = Vec(Ux + x, Uy - y);
		bl = Vec(Ux, Uy - y);

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(tl.x, tl.y - 0.1);
		glVertex2f(tr.x, tr.y - 0.1);
		glEnd();

		//drag corner
		glBegin(GL_LINES);
		glVertex2f(br.x- x*.0625, br.y + y*.08333);
		glVertex2f(br.x, br.y + y*.08333);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(br.x - x*.0625, br.y + y*.08333);
		glVertex2f(br.x- x*.0625, br.y);
		glEnd();

		if (plotCheck == 2 || plotCheck == 1)
		{
			//Y axis Rect
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
			glVertex2f(tl.x + x / 2, tl.y - .1);
			glVertex2f(bl.x + x / 2, bl.y);
			glEnd();

			//X axis Rect
				glBegin(GL_LINES);
				glVertex2f(tl.x, tl.y - y / 2);
				glVertex2f(tr.x, tl.y - y / 2);
				glEnd();

			/*	else {//this is to offset the top draggable area for a perfect circle
					glBegin(GL_LINES);
					glVertex2f(tl.x, tl.y - y / 2-.05);
					glVertex2f(tr.x, tl.y - y / 2 - .05);
					glEnd();
				}*/
		}


		//Draw points

		if (plotCheck == 0) {
			glColor3f(1.0, 1.0, 1.0);

					glBegin(GL_POINTS);

					for (vector<Vec*>::iterator i = points.begin(); i != points.end(); ++i) {
						if ((Uy - (*i)->y)<Uy - 0.1) {
							glVertex2f(Ux + (*i)->x, Uy - (*i)->y);
						}
					}

					glEnd();

			
		}

		float r, g, b;

		r = this->r;
		g = this->g;
		b = this->b;

		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		glVertex2f(tl.x, tl.y);
		glVertex2f(tr.x, tr.y);
		glVertex2f(br.x, br.y);
		glVertex2f(bl.x, bl.y);

		glEnd();

		//White shading of selected box
		if (focused) {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);

			glVertex2f(tl.x, tl.y);
			glVertex2f(tr.x, tr.y);

			glVertex2f(tr.x, tr.y);
			glVertex2f(br.x, br.y);

			glVertex2f(br.x, br.y);
			glVertex2f(bl.x, bl.y);

			glVertex2f(bl.x, bl.y);
			glVertex2f(tl.x, tl.y);

			glEnd();
		}

	}

	virtual void handle(float mx, float my) {
		points.push_back(new Vec(mx - Ux, Uy-my));
		}

};



#endif


