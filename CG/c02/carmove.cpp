#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<time.h>
#include<sys/timeb.h>
#define ESCAPE 27
int window;
float rtri=0.0f;
float rquad=0.0f;
//GLdouble radius=2;
void InitGL(int width,int height)
{
glClearColor(0.0f,0.0f,0.0f,0.0f);
glClearDepth(1.0);
glDepthFunc(GL_LESS);
glEnable(GL_DEPTH_TEST);
glShadeModel(GL_SMOOTH);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
glMatrixMode(GL_MODELVIEW);
}
void ReSizeGLScene(int width,int height)
{
if(height==0)

height=1;
glViewport(0,0,width,height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
glMatrixMode(GL_MODELVIEW);
}

float ballX=-0.5f;
float ballY=0.0f;
float ballZ=0.0f;
void drawBall(void)
{
glColor3f(0.0,1.0,0.0);
glTranslatef( ballX, ballY, ballZ);
glutSolidSphere(0.3,20,20);
glTranslatef( ballX+1.5, ballY, ballZ);
glutSolidSphere(0.3,20,20);
}
void DrawGLScene()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef( rtri,0.0f,-6.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(-1.0f,1.0f,0.0f);
glVertex3f(0.4f,1.0f,0.0f);
glVertex3f(1.0f,0.4f,0.0f);
glColor3f(0.0f,1.0f,0.0f);
glVertex3f(1.0f,0.0f,0.0f);
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(-1.0f,0.0f,0.0f);
glEnd();
drawBall();
rtri+=0.005f;
if(rtri>2)
rtri=-2.0f;
rquad-=15.0f;
glutSwapBuffers();
}

void keyPressed(unsigned char key,int x,int y)
{
if(key==ESCAPE)
{
glutDestroyWindow(window);
exit(0);
}
}


int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the 
       program */
    glutInit(&argc,argv);

 glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |GLUT_ALPHA |GLUT_DEPTH );
 glutInitWindowSize(640,480);

glutInitWindowPosition(0,0);

  window=glutCreateWindow("moving car");
 glutDisplayFunc(&DrawGLScene);
glutIdleFunc(&DrawGLScene);
glutReshapeFunc(&ReSizeGLScene);

glutKeyboardFunc(&keyPressed);
 
   InitGL(640,480);
glutMainLoop();
return 1;

}
    
//To compile & run


//admin1@admin:~$ cd Desktop
//admin1@admin:~/Desktop$ g++ carmove.cpp -o gl -lGL -lGLU -lglut
//admin1@admin:~/Desktop$ ./gl


