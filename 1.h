#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


GLfloat oldx=500, oldy=800;
void koch(GLdouble dir, GLfloat len, GLint itr)
{
  GLfloat newx;
  GLfloat newy;
  GLdouble rdir = 3.14159265358979323846/180.0 * dir;
  newx = oldx + len * cos(rdir);
  newy = oldy + len * sin(rdir);

  if(itr==0)
  {
    glVertex2f(oldx, oldy);
    glVertex2f(newx, newy);
    oldx = newx;
    oldy = newy;
  }

  else
  {
    itr--;
    koch(dir, len, itr);
    dir+=60;
    koch(dir, len, itr);
    dir-=120;
    koch(dir, len, itr);
    dir+=60;
    koch(dir, len, itr);
  }
}

GLfloat i=3;
void display()
{
  glColor3f(1,0,0);
  glBegin(GL_LINES);
  koch(0,2,i);
  koch(-120,2,i);
  koch(120,2,i);
  glEnd();
  glFlush();
}

void mouse(int button, int state, int x, int y)
{

  if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    i++;
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    oldx=x;
    oldy=fabs(720 - y);
    display();
  }
  if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
  {
    i=3;
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
  }
}
