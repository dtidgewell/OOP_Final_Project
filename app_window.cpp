
# include <iostream>
# include "app_window.h"
#include <chrono>
#include <string.h>
//#include "Player.h"


typedef std::chrono::high_resolution_clock Clock;

Rect full(-1.0, 1, 1, 1);
Player* p = new Player();
Object * check;
int CD;

AppWindow::AppWindow ( const char* label, int x, int y, int w, int h )
          :GlutWindow ( label, x, y, w, h )
 {
   _markx = -.5;
   _marky = -0.6;
   addMenuEntry ( "Option 0", evOption0 );
   addMenuEntry ( "Option 1", evOption1 );

   Reset();
 }

// mouse events are in window coordinates, but your scene is in [0,1]x[0,1],
// so make here the conversion when needed
void AppWindow::windowToScene ( float& x, float &y )
 {
   x = (2.0f*(x/float(_w))) - 1.0f;
   y = 1.0f - (2.0f*(y/float(_h)));
 }

// Called every time there is a window event
void AppWindow::handle ( const Event& e )
 {
	 auto prev = Clock::now();
	 auto curr = Clock::now();
	 auto elapsed = (curr - prev);

   bool rd=true;


   if ( e.type==Keyboard ) 
    switch ( e.key )
    { case ' ': // space bar
	   std::cout << "Space pressed.\n";
	   Reset();
	   break;

	  case 27: // Esc was pressed
	   exit(1);
	}

   if ( e.type==MouseDown || e.type==Motion)
    { //_markx=(float)e.mx;
      //_marky=(float)e.my;
      //windowToScene(_markx,_marky);
    }

   if ( e.type==Menu )
    { std::cout<<"Menu Event: "<<e.menuev<<std::endl;
      rd=false; // no need to redraw
    }

   //const float incx = 0.002;// *full.width;
   const float incx = 0.02;// *full.width;
   const float incy = 0.03;// *full.height;
     const float JUMP_HEIGHT = 0.8;
     if ( e.type==SpecialKey ){
       float currentPosition = p->top;
    switch ( e.key )
     {//case GLUT_KEY_LEFT:  _markx-=incx; break;
      //case GLUT_KEY_RIGHT: _markx+=incx; break;
      case GLUT_KEY_UP:


		  prev = Clock::now();

            while(p->top < currentPosition+JUMP_HEIGHT){

				curr = Clock::now();

			//std::cout << "curr: " << curr << " prev: " << prev <<"\n";

				elapsed = (curr - prev);

				//std::cout << elapsed.count() << std::endl;
				if (elapsed.count() >= 10000000) {
					p->top += incy;
                    p->bottom += incy;
					//std::cout << _marky << std::endl;
					draw();

					prev = Clock::now();
				}
		
            }
	

			prev = Clock::now();
             while(p->top > currentPosition){

				curr = Clock::now();
				elapsed = (curr - prev);
				//std::cout << elapsed.count() << std::endl;
				 if (elapsed.count() >= 10000000) {
					 p->top -= incy;
                     p->bottom -= incy;
					// std::cout << _marky << std::endl;
					draw();
					 prev = Clock::now();
				 }
             }
            break;
      //case GLUT_KEY_DOWN:  _marky-=incy; break;
      default: rd=false; // no redraw
	 }
    }
   if (rd) redraw(); // ask the window to be rendered when possible
}

void AppWindow::resize ( int w, int h )
 {
   // Define that OpenGL should use the whole window for rendering
   glViewport( 0, 0, w, h );
   _w=w; _h=h;
 }

// here we will redraw the scene according to the current state of the application.
void AppWindow::draw ()
 {

	CD = check->contains(*p);

	std::cout << CD;

   // Clear the rendering window
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Clear the trasnformation stack
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
     
     glColor3d(1.0,0.0,0.0);

	
     
     glColor3d(0.0, 1.0, 0.0);
     
     //Ground
     glBegin(GL_POLYGON);
     glVertex2d ( -1.0, -0.7 );
     glVertex2d ( 1.0, -0.7 );
     glVertex2d ( 1.0, -1.0);
     glVertex2d ( -1.0, -1.0 );
     glEnd();
     
     for (int i = 0; i < v.size(); i++) {
         (v[i])->draw();
         //if(typeid(v[i]).name() == "Spike"){((Spike)*v[i])->edges.clear();}
     }
   // Swap buffers
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}

void AppWindow::idle(){
	auto prev = Clock::now();
	auto curr = Clock::now();
	auto elapsed = (curr - prev);

	while (true) {
		if (elapsed.count() >= 10000000) {
			draw();
			break;
		}
		else {
			curr = Clock::now();
			elapsed = (curr - prev);
		}

	}
}

void AppWindow::Reset() {
	if (v.size() > 0) {
		for (int i = 0; i < v.size();i++) {
			v.pop_back();
		}
	}

	v.push_back(new Spike());
	v.push_back(new Ledge());
	v.push_back(new Ledge(5.0, 5.3, -0.5, -0.7, 0.0, 1.0, 0.0, -0.01));
	v.push_back(new Spike(6.0, 6.2, -0.5, 6.1, -0.7, 0.0, 0.0, 1.0, -0.01));
	v.push_back(new Spike(6.7, 6.9, -0.5, 6.8, -0.7, 0.0, 0.0, 1.0, -0.01));
	v.push_back(p);
	check = v[0];
}
