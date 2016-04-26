
class Ledge : public Obstacle{
	public:
		float left, right, top, bottom;
		Ledge()
		{
			left = 2.0;
			right = 2.7;
			top = -0.4;
			bottom = -0.7;

			red = 0.0;
			green = 1.0;
			blue = 0.0;
			dx = -0.001;
		}

		Ledge(float l, float r, float t, float b, float rd, float gn, float bl, float d)
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