
// Ensure the header file is included only once in multi-file projects
#ifndef APP_WINDOW_H
#define APP_WINDOW_H

# include "glut_window.h"
#include "Object.h"
#include "Spike.h"
#include "Ledge.h"
#include "Player.h"
#include <vector>

// The functionality of your application should be implemented inside AppWindow
class AppWindow : public GlutWindow
 { private :
    enum MenuEv { evOption0, evOption1 };
    float _markx, _marky;
    int _w, _h;
     std::vector<Object*> v;

   public :
    AppWindow ( const char* label, int x, int y, int w, int h );
    void windowToScene ( float& x, float &y );

   private : // functions derived from the base class
    virtual void handle ( const Event& e );
    virtual void draw ();
    virtual void resize ( int w, int h );
    virtual void idle();
	virtual void Reset();
 };

#endif // APP_WINDOW_H
