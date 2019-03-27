#include "1.h"



int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(1280, 720);


  glutCreateWindow("Fractal");
  gluOrtho2D(0,1280,0,720);
  glClearColor(1,1,1,0);

  glClearDepth(1);
  glClear(GL_COLOR_BUFFER_BIT);
  cout<<"Left mouse button to draw Koch's Snowflake.\nRight Mouse button to increase the iterations.\nMiddle mouse button to clear the screen.\n";
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
