#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void asu()
{
    glLoadIdentity();
       gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}


void init(void){
  glClearColor(204/255.0f, 255/255.0f, 255/255.0f, 0);
   glMatrixMode(GL_PROJECTION);
   glEnable(GL_DEPTH_TEST);
   is_depth=1;
   glMatrixMode(GL_MODELVIEW);
   glEnable(GL_POINT_SMOOTH);
   glPointSize(5.0f);
   glLineWidth(2.0f);
   	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
   }
void reshape(int x, int y){
    if( x == 0 || y == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, (GLdouble)x/(GLdouble)y, 5, 500);
    glMatrixMode(GL_MODELVIEW);
    glViewport(400, 400, x / 5, y / 5);
}
const double PI = 3.141592653589793;
 int i;

void lingkaran(int jari2, int jumlah_titik, int x_tengah, int y_tengah) {
 glBegin(GL_LINE_STRIP);
 for (i=0;i<=360;i++){
 float sudut=i*(2*PI/jumlah_titik);
 float x=x_tengah+jari2*cos(sudut);
 float y=y_tengah+jari2*sin(sudut);
 glVertex3f(x,0.2,y);
 }
 glEnd();
 }

void renderScene(void) {
 glColor3ub(255,255,255);
 lingkaran(10,100,0,0);
 glFlush();
 glColor3ub(255,255,255);
 lingkaran(7,100,-30,0);
 glFlush();
 glColor3ub(255,255,255);
 lingkaran(7,100,30,0);
 glFlush();
 }

void lapangan(void)
{
    glBegin(GL_POLYGON);
    glColor3ub(0,153,0);
    glVertex3f(-37.5,0.5,10);
    glVertex3f(-30.5,0.5,10);
    glVertex3f(-30.5,0.5,-10);
    glVertex3f(-37.5,0.5,-10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex3f(37.5,0.5,10);
    glVertex3f(30.5,0.5,10);
    glVertex3f(30.5,0.5,-10);
    glVertex3f(37.5,0.5,-10);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(255,255,255);
    glVertex3f(0,15,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(-100,-0.3,70);
    glVertex3f(100,-0.3,70);
    glVertex3f(100,-0.3,-70);
    glVertex3f(-100,-0.3,-70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex3f(-55,0,40);
    glVertex3f(55,0,40);
    glVertex3f(55,0,-40);
    glVertex3f(-55,0,-40);
    glEnd();
    //ijobanget
    glBegin(GL_POLYGON);
    glColor3ub(0,153,0);
    glVertex3f(-37.5,0.1,40);
    glVertex3f(-25,0.1,40);
    glVertex3f(-25,0.1,-40);
    glVertex3f(-37.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-12.5,0.1,40);
    glVertex3f(-0,0.1,40);
    glVertex3f(-0,0.1,-40);
    glVertex3f(-12.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(12.5,0.1,40);
    glVertex3f(25,0.1,40);
    glVertex3f(25,0.1,-40);
    glVertex3f(12.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(37.5,0.1,40);
    glVertex3f(50,0.1,40);
    glVertex3f(50,0.1,-40);
    glVertex3f(37.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-50.5,0.1,40);
    glVertex3f(-55,0.1,40);
    glVertex3f(-55,0.1,-40);
    glVertex3f(-50,0.1,-40);
    glEnd();
}

void lampu (void)
{ //lampu kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(130,130,130);
    glVertex3f(-80,43,-10);
    glVertex3f(-80,43,10);
    glVertex3f(-80,40,10);
    glVertex3f(-80,40,-10);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,43,-15);
    glVertex3f(-80,43,15);
    glVertex3f(-77,55,15);
    glVertex3f(-77,55,-15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,102);
    glVertex3f(-80,43,-15);
    glVertex3f(-80,43,15);
    glVertex3f(-77,55,15);
    glVertex3f(-77,55,-15);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(130,130,130);
    glVertex3f(40,40,70);
    glVertex3f(-40,40,70);
    glVertex3f(-40,45,68);
    glVertex3f(40,45,68);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(41,40,70);
    glVertex3f(-41,40,70);
    glVertex3f(-41,45,68);
    glVertex3f(41,45,68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(30,40,70);
    glVertex3f(-30,40,70);
    glVertex3f(-30,45,68);
    glVertex3f(30,45,68);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(31,40,70);
    glVertex3f(-31,40,70);
    glVertex3f(-31,45,68);
    glVertex3f(31,45,68);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(25,46,68);
    glVertex3f(-25,46,68);
    glVertex3f(-25,45,68);
    glVertex3f(25,45,68);
    glEnd();
    //lampu panjang
    glBegin(GL_POLYGON);
    glColor3ub(255,255,102);
    glVertex3f(31,46,68);
    glVertex3f(-31,46,68);
    glVertex3f(-31,48,67);
    glVertex3f(31,48,67);
    glEnd();
    //lampu panjang
    glBegin(GL_LINE_LOOP);
    glColor3ub(130,130,130);
    glVertex3f(31,46,68);
    glVertex3f(-31,46,68);
    glVertex3f(-31,48,67);
    glVertex3f(31,48,67);
    glEnd();
}
void gawang (void)
{   //kanan
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(47,0.1,4);
    glVertex3f(47,4,4);
    glVertex3f(47,4,-4);
    glVertex3f(47,0.1,-4);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(47,4,4);
    glVertex3f(50,0,4);
    glVertex3f(47,4,-4);
    glVertex3f(50,0,-4);
    glEnd();
    //kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(-47,0.1,4);
    glVertex3f(-47,4,4);
    glVertex3f(-47,4,-4);
    glVertex3f(-47,0.1,-4);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-47,4,4);
    glVertex3f(-50,0,4);
    glVertex3f(-47,4,-4);
    glVertex3f(-50,0,-4);
    glEnd();
}

void garis_lapangan(void)
{
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-47,2.2,32);
    glVertex3f(-47,4.2,32);
    glVertex3f(-48,4.2,33);
    glVertex3f(-48,2.2,33);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(47,2.2,32);
    glVertex3f(47,4.2,32);
    glVertex3f(48,4.2,33);
    glVertex3f(48,2.2,33);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(47,2.2,-32);
    glVertex3f(47,4.2,-32);
    glVertex3f(48,4.2,-33);
    glVertex3f(48,2.2,-33);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-47,2.2,-32);
    glVertex3f(-47,4.2,-32);
    glVertex3f(-48,4.2,-33);
    glVertex3f(-48,2.2,-33);
    glEnd();
    //bendera
    glBegin(GL_LINES);
    glColor3ub(128,42,0);
    glVertex3f(-47,0.2,32);
    glVertex3f(-47,4.2,32);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(47,0.2,32);
    glVertex3f(47,4.2,32);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(47,0.2,-32);
    glVertex3f(47,4.2,-32);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-47,0.2,-32);
    glVertex3f(-47,4.2,-32);
    glEnd();
    //lapangan
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(-47,0.2,32);
    glVertex3f(47,0.2,32);
    glVertex3f(47,0.2,-32);
    glVertex3f(-47,0.2,-32);
    glEnd();
    //sudut corner
    glBegin(GL_LINES);
    glVertex3f(0,0.2,32);
    glVertex3f(0,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-47,0.2,-30);
    glVertex3f(-45,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(47,0.2,-30);
    glVertex3f(45,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-47,0.2,30);
    glVertex3f(-45,0.2,32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(47,0.2,30);
    glVertex3f(45,0.2,32);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-47, 0.2,-20);
    glVertex3f(-30, 0.2,-20);
    glVertex3f(-30, 0.2,20);
    glVertex3f(-47, 0.2,20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-47, 0.2,-8);
    glVertex3f(-40, 0.2,-8);
    glVertex3f(-40, 0.2,8);
    glVertex3f(-47, 0.2,8);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(47, 0.2,-20);
    glVertex3f(30, 0.2,-20);
    glVertex3f(30, 0.2,20);
    glVertex3f(47, 0.2,20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(47, 0.2,-8);
    glVertex3f(40, 0.2,-8);
    glVertex3f(40, 0.2,8);
    glVertex3f(47, 0.2,8);
    glEnd();
}

void tribun_depan(void)
{
    //sponsor kanan
    glBegin(GL_POLYGON);
    glColor3ub(0,204,204);
    glVertex3f(-53,0,-30);
    glVertex3f(-53,0,-15);
    glVertex3f(-53,4,-15);
    glVertex3f(-53,4,-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,204,204);
    glVertex3f(-53,0,30);
    glVertex3f(-53,0,15);
    glVertex3f(-53,4,15);
    glVertex3f(-53,4,30);
    glEnd();
    //sponsor kiri
    glBegin(GL_POLYGON);
    glColor3ub(0,204,204);
    glVertex3f(53,0,-30);
    glVertex3f(53,0,-15);
    glVertex3f(53,4,-15);
    glVertex3f(53,4,-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,204,204);
    glVertex3f(53,0,30);
    glVertex3f(53,0,15);
    glVertex3f(53,4,15);
    glVertex3f(53,4,30);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-55,0,40);
    glVertex3f(55,0,40);
    glVertex3f(55,5,40);
    glVertex3f(-55,5,40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,0,-40);
    glVertex3f(55,0,-40);
    glVertex3f(55,5,-40);
    glVertex3f(-55,5,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,0,-40);
    glVertex3f(-55,0,40);
    glVertex3f(-55,5,40);
    glVertex3f(-55,5,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,0,-40);
    glVertex3f(55,0,40);
    glVertex3f(55,5,40);
    glVertex3f(55,5,-40);
    glEnd();
    //tribun kiri
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,5,40);
    glVertex3f(-55,5,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-70,15,40);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(55,5,40);
    glVertex3f(55,5,-40);
    glVertex3f(70,15,-40);
    glVertex3f(70,15,40);
    glEnd();

    //antar tribun miring
    glBegin(GL_POLYGON);
    glColor3ub(120,0,0);
    glVertex3f(-55,5,40);
    glVertex3f(-70,15,40);
    glVertex3f(-55,15,55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,5,-40);
    glVertex3f(70,15,-40);
    glVertex3f(55,15,-55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,5,40);
    glVertex3f(55,15,55);
    glVertex3f(70,15,40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,5,-40);
    glVertex3f(-55,15,-55);
    glVertex3f(-70,15,-40);
    glEnd();
    //tribun depan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,5,40);
    glVertex3f(55,5,40);
    glVertex3f(55,15,55);
    glVertex3f(-55,15,55);
    glEnd();
    //tribun belakang
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,5,-40);
    glVertex3f(55,5,-40);
    glVertex3f(55,15,-55);
    glVertex3f(-55,15,-55);
    glEnd();

    //tingkat
    //depan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,20,50);
    glVertex3f(55,20,50);
    glVertex3f(55,40,70);
    glVertex3f(-55,40,70);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,20,-50);
    glVertex3f(55,20,-50);
    glVertex3f(55,40,-70);
    glVertex3f(-55,40,-70);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-65,20,40);
    glVertex3f(-65,20,-40);
    glVertex3f(-80,40,-40);
    glVertex3f(-80,40,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(65,20,40);
    glVertex3f(65,20,-40);
    glVertex3f(80,40,-40);
    glVertex3f(80,40,40);
    glEnd();

    //antar tribun tingkat
    glBegin(GL_POLYGON);
    glColor3ub(120,0,0);
    glVertex3f(-80,40,-40);
    glVertex3f(-65,20,-40);
    glVertex3f(-55,20,-50);
    glVertex3f(-55,40,-70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(80,40,-40);
    glVertex3f(65,20,-40);
    glVertex3f(55,20,-50);
    glVertex3f(55,40,-70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(80,40,40);
    glVertex3f(65,20,40);
    glVertex3f(55,20,50);
    glVertex3f(55,40,70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-80,40,40);
    glVertex3f(-65,20,40);
    glVertex3f(-55,20,50);
    glVertex3f(-55,40,70);
    glEnd();

    //penghubung
    //depan
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-55,20,50);
    glVertex3f(55,20,50);
    glVertex3f(55,15,55);
    glVertex3f(-55,15,55);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-55,20,-50);
    glVertex3f(55,20,-50);
    glVertex3f(55,15,-55);
    glVertex3f(-55,15,-55);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-65,20,40);
    glVertex3f(-65,20,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-70,15,40);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(65,20,40);
    glVertex3f(65,20,-40);
    glVertex3f(70,15,-40);
    glVertex3f(70,15,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(65,20,40);
    glVertex3f(70,15,40);
    glVertex3f(55,15,55);
    glVertex3f(55,20,50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-65,20,40);
    glVertex3f(-70,15,40);
    glVertex3f(-55,15,55);
    glVertex3f(-55,20,50);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(65,20,-40);
    glVertex3f(70,15,-40);
    glVertex3f(55,15,-55);
    glVertex3f(55,20,-50);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-65,20,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-55,15,-55);
    glVertex3f(-55,20,-50);
    glEnd();

    //tepi
    //depan
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(55,40,70);
    glVertex3f(-55,40,70);
    glVertex3f(-55,40,75);
    glVertex3f(55,40,75);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(55,40,-70);
    glVertex3f(-55,40,-70);
    glVertex3f(-55,40,-75);
    glVertex3f(55,40,-75);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glVertex3f(-80,40,-40);
    glVertex3f(-80,40,40);
    glVertex3f(-85,40,40);
    glVertex3f(-85,40,-40);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glVertex3f(80,40,-40);
    glVertex3f(80,40,40);
    glVertex3f(85,40,40);
    glVertex3f(85,40,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-80,40,40);
    glVertex3f(-85,40,40);
    glVertex3f(-55,40,75);
    glVertex3f(-55,40,70);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(80,40,40);
    glVertex3f(85,40,40);
    glVertex3f(55,40,75);
    glVertex3f(55,40,70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-80,40,-40);
    glVertex3f(-85,40,-40);
    glVertex3f(-55,40,-75);
    glVertex3f(-55,40,-70);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(80,40,-40);
    glVertex3f(85,40,-40);
    glVertex3f(55,40,-75);
    glVertex3f(55,40,-70);
    glEnd();

     glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(55,40,70);
    glVertex3f(-55,40,70);
    glVertex3f(-55,40,75);
    glVertex3f(55,40,75);
    glEnd();
    //belakang
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,40,-70);
    glVertex3f(-55,40,-70);
    glVertex3f(-55,40,-75);
    glVertex3f(55,40,-75);
    glEnd();
    //kiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,-40);
    glVertex3f(-80,40,40);
    glVertex3f(-85,40,40);
    glVertex3f(-85,40,-40);
    glEnd();
    //kanan
    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,-40);
    glVertex3f(80,40,40);
    glVertex3f(85,40,40);
    glVertex3f(85,40,-40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,40);
    glVertex3f(-85,40,40);
    glVertex3f(-55,40,75);
    glVertex3f(-55,40,70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,40);
    glVertex3f(85,40,40);
    glVertex3f(55,40,75);
    glVertex3f(55,40,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,-40);
    glVertex3f(-85,40,-40);
    glVertex3f(-55,40,-75);
    glVertex3f(-55,40,-70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,-40);
    glVertex3f(85,40,-40);
    glVertex3f(55,40,-75);
    glVertex3f(55,40,-70);
    glEnd();

    //tribun pemain
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(35,3,38);
    glVertex3f(15,3,38);
    glVertex3f(15,3,34);
    glVertex3f(35,3,34);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(35,3,34);
    glVertex3f(35,3,38);
    glVertex3f(35,0,38);
    glVertex3f(35,0,34);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(15,3,34);
    glVertex3f(15,3,38);
    glVertex3f(15,0,38);
    glVertex3f(15,0,34);
    glEnd();

    //tribun pemain 2
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-35,3,38);
    glVertex3f(-15,3,38);
    glVertex3f(-15,3,34);
    glVertex3f(-35,3,34);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-35,3,34);
    glVertex3f(-35,3,38);
    glVertex3f(-35,0,38);
    glVertex3f(-35,0,34);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-15,3,34);
    glVertex3f(-15,3,38);
    glVertex3f(-15,0,38);
    glVertex3f(-15,0,34);
    glEnd();

}
void penonton (void)
{
    //samping_kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-65,20,15);
    glVertex3f(-65,20,-15);
    glVertex3f(-80,40,-15);
    glVertex3f(-80,40,15);
    glEnd();
//samping_kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(65,20,15);
    glVertex3f(65,20,-15);
    glVertex3f(80,40,-15);
    glVertex3f(80,40,15);
    glEnd();
//depan skat
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-35,20,50);
    glVertex3f(-10,20,50);
    glVertex3f(-10,40,70);
    glVertex3f(-35,40,70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(35,20,50);
    glVertex3f(10,20,50);
    glVertex3f(10,40,70);
    glVertex3f(35,40,70);
    glEnd();
//blakang skak
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-35,20,-50);
    glVertex3f(-10,20,-50);
    glVertex3f(-10,40,-70);
    glVertex3f(-35,40,-70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(35,20,-50);
    glVertex3f(10,20,-50);
    glVertex3f(10,40,-70);
    glVertex3f(35,40,-70);
    glEnd();
}
void tribun_depan_garis(void)
{

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-53,0,-30);
    glVertex3f(-53,0,-15);
    glVertex3f(-53,4,-15);
    glVertex3f(-53,4,-30);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-53,0,30);
    glVertex3f(-53,0,15);
    glVertex3f(-53,4,15);
    glVertex3f(-53,4,30);
    glEnd();
    //sponsor kiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(53,0,-30);
    glVertex3f(53,0,-15);
    glVertex3f(53,4,-15);
    glVertex3f(53,4,-30);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(53,0,30);
    glVertex3f(53,0,15);
    glVertex3f(53,4,15);
    glVertex3f(53,4,30);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,0,40);
    glVertex3f(55,0,40);
    glVertex3f(55,5,40);
    glVertex3f(-55,5,40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,0,-40);
    glVertex3f(55,0,-40);
    glVertex3f(55,5,-40);
    glVertex3f(-55,5,-40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,0,-40);
    glVertex3f(-55,0,40);
    glVertex3f(-55,5,40);
    glVertex3f(-55,5,-40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,0,-40);
    glVertex3f(55,0,40);
    glVertex3f(55,5,40);
    glVertex3f(55,5,-40);
    glEnd();
    //tribun kiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,5,40);
    glVertex3f(-55,5,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-70,15,40);
    glEnd();

    //kanan
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,5,40);
    glVertex3f(55,5,-40);
    glVertex3f(70,15,-40);
    glVertex3f(70,15,40);
    glEnd();

    //antar tribun miring
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,5,40);
    glVertex3f(-70,15,40);
    glVertex3f(-55,15,55);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,5,-40);
    glVertex3f(70,15,-40);
    glVertex3f(55,15,-55);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,5,40);
    glVertex3f(55,15,55);
    glVertex3f(70,15,40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,5,-40);
    glVertex3f(-55,15,-55);
    glVertex3f(-70,15,-40);
    glEnd();
    //tribun depan
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,5,40);
    glVertex3f(55,5,40);
    glVertex3f(55,15,55);
    glVertex3f(-55,15,55);
    glEnd();
    //tribun belakang
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,5,-40);
    glVertex3f(55,5,-40);
    glVertex3f(55,15,-55);
    glVertex3f(-55,15,-55);
    glEnd();

    //tingkat
    //depan
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,20,50);
    glVertex3f(55,20,50);
    glVertex3f(55,40,70);
    glVertex3f(-55,40,70);
    glEnd();
    //belakang
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,20,-50);
    glVertex3f(55,20,-50);
    glVertex3f(55,40,-70);
    glVertex3f(-55,40,-70);
    glEnd();
    //kiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(-65,20,40);
    glVertex3f(-65,20,-40);
    glVertex3f(-80,40,-40);
    glVertex3f(-80,40,40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(65,20,40);
    glVertex3f(65,20,-40);
    glVertex3f(80,40,-40);
    glVertex3f(80,40,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,204,204);
    glVertex3f(76,60,10);
    glVertex3f(76,60,-10);
    glVertex3f(80,45,-10);
    glVertex3f(80,45,10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(76.1,60,10);
    glVertex3f(76.1,60,-10);
    glVertex3f(80.1,45,-10);
    glVertex3f(80.1,45,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(76,60,10);
    glVertex3f(76,60,-10);
    glVertex3f(80,45,-10);
    glVertex3f(80,45,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(80,40,7);
    glVertex3f(80,40,-7);
    glVertex3f(80,45,-7);
    glVertex3f(80,45,7);
    glEnd();
    //angka0
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(77,55,6);
    glVertex3f(77,55,4);
    glVertex3f(78.5,50,4);
    glVertex3f(78.5,50,6);
    glEnd();
    //-
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex3f(77.5,52.5,-2);
    glVertex3f(77.5,52.5,2);
    glEnd();
    //angka0
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(77,55,-6);
    glVertex3f(77,55,-4);
    glVertex3f(78.5,50,-4);
    glVertex3f(78.5,50,-6);
    glEnd();

    //antar tribun tingkat
    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,-40);
    glVertex3f(-65,20,-40);
    glVertex3f(-55,20,-50);
    glVertex3f(-55,40,-70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,-40);
    glVertex3f(65,20,-40);
    glVertex3f(55,20,-50);
    glVertex3f(55,40,-70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,40);
    glVertex3f(65,20,40);
    glVertex3f(55,20,50);
    glVertex3f(55,40,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,40);
    glVertex3f(-65,20,40);
    glVertex3f(-55,20,50);
    glVertex3f(-55,40,70);
    glEnd();

    //penghubung
    //depan
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,20,50);
    glVertex3f(55,20,50);
    glVertex3f(55,15,55);
    glVertex3f(-55,15,55);
    glEnd();
    //belakang
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,20,-50);
    glVertex3f(55,20,-50);
    glVertex3f(55,15,-55);
    glVertex3f(-55,15,-55);
    glEnd();
    //kiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(-65,20,40);
    glVertex3f(-65,20,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-70,15,40);
    glEnd();
    //kanan
    glBegin(GL_LINE_LOOP);
    glVertex3f(65,20,40);
    glVertex3f(65,20,-40);
    glVertex3f(70,15,-40);
    glVertex3f(70,15,40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(65,20,40);
    glVertex3f(70,15,40);
    glVertex3f(55,15,55);
    glVertex3f(55,20,50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-65,20,40);
    glVertex3f(-70,15,40);
    glVertex3f(-55,15,55);
    glVertex3f(-55,20,50);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(65,20,-40);
    glVertex3f(70,15,-40);
    glVertex3f(55,15,-55);
    glVertex3f(55,20,-50);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-65,20,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-55,15,-55);
    glVertex3f(-55,20,-50);
    glEnd();

    //tepi
    //depan
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,40,70);
    glVertex3f(-55,40,70);
    glVertex3f(-55,40,75);
    glVertex3f(55,40,75);
    glEnd();
    //belakang
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,40,-70);
    glVertex3f(-55,40,-70);
    glVertex3f(-55,40,-75);
    glVertex3f(55,40,-75);
    glEnd();
    //kiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,-40);
    glVertex3f(-80,40,40);
    glVertex3f(-85,40,40);
    glVertex3f(-85,40,-40);
    glEnd();
    //kanan
    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,-40);
    glVertex3f(80,40,40);
    glVertex3f(85,40,40);
    glVertex3f(85,40,-40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,40);
    glVertex3f(-85,40,40);
    glVertex3f(-55,40,75);
    glVertex3f(-55,40,70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,40);
    glVertex3f(85,40,40);
    glVertex3f(55,40,75);
    glVertex3f(55,40,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-80,40,-40);
    glVertex3f(-85,40,-40);
    glVertex3f(-55,40,-75);
    glVertex3f(-55,40,-70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(80,40,-40);
    glVertex3f(85,40,-40);
    glVertex3f(55,40,-75);
    glVertex3f(55,40,-70);
    glEnd();

    //tribun pemain
    glBegin(GL_LINE_LOOP);
    glVertex3f(35,3,38);
    glVertex3f(15,3,38);
    glVertex3f(15,3,34);
    glVertex3f(35,3,34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(35,3,34);
    glVertex3f(35,3,38);
    glVertex3f(35,0,38);
    glVertex3f(35,0,34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(15,3,34);
    glVertex3f(15,3,38);
    glVertex3f(15,0,38);
    glVertex3f(15,0,34);
    glEnd();

    //tribun pemain 2
    glBegin(GL_LINE_LOOP);
    glVertex3f(-35,3,38);
    glVertex3f(-15,3,38);
    glVertex3f(-15,3,34);
    glVertex3f(-35,3,34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-35,3,34);
    glVertex3f(-35,3,38);
    glVertex3f(-35,0,38);
    glVertex3f(-35,0,34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-15,3,34);
    glVertex3f(-15,3,38);
    glVertex3f(-15,0,38);
    glVertex3f(-15,0,34);
    glEnd();
}

void atap(void)
{   //tiang
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex3f(-55,40,-70);
    glVertex3f(-55,50,-70);
    glVertex3f(55,50,-70);
    glVertex3f(55,40,-70);
    glVertex3f(-30,40,-70);
    glVertex3f(-30,50,-70);
    glVertex3f(30,50,-70);
    glVertex3f(30,40,-70);
    glVertex3f(55,49,-75);
    glVertex3f(55,40,-75);
    glVertex3f(-55,40,-75);
    glVertex3f(-55,49,-75);
    glVertex3f(-30,40,-75);
    glVertex3f(-30,49,-75);
    glVertex3f(30,40,-75);
    glVertex3f(30,49,-75);
    glEnd();
    //atap blakang
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-55,49,-75);
    glVertex3f(55,49,-75);
    glVertex3f(55,51,-65);
    glVertex3f(-55,51,-65);
    glEnd();
    //atap tengah
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(55,51,-65);
    glVertex3f(-55,51,-65);
    glVertex3f(-55,60,-45);
    glVertex3f(55,60,-45);
    glEnd();
    //atap tengah
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-55,60,-45);
    glVertex3f(55,60,-45);
    glVertex3f(55,60,-35);
    glVertex3f(-55,60,-35);
    glEnd();
    //lineloop atap
        //atap blakang
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-55,49,-75);
    glVertex3f(55,49,-75);
    glVertex3f(55,51,-65);
    glVertex3f(-55,51,-65);
    glEnd();
    //atap tengah
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,51,-65);
    glVertex3f(-55,51,-65);
    glVertex3f(-55,60,-45);
    glVertex3f(55,60,-45);
    glEnd();
    //atap tengah
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,60,-45);
    glVertex3f(55,60,-45);
    glVertex3f(55,60,-35);
    glVertex3f(-55,60,-35);
    glEnd();
}

void tembok(void)
{

//  tembokdepan
    glBegin(GL_POLYGON);
    glColor3ub(224,224,224);
    glVertex3f(-55,5,68);
    glVertex3f(55,5,68);
    glVertex3f(55,40,75);
    glVertex3f(-55,40,75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-55,0,68);
    glVertex3f(55,0,68);
    glVertex3f(55,5,68);
    glVertex3f(-55,5,68);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-85,0,40);
    glVertex3f(-55,0,68);
    glVertex3f(-55,5,68);
    glVertex3f(-85,5,40);
    glEnd();

//  tembokbelakang
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f(-55,5,-68);
    glVertex3f(55,5,-68);
    glVertex3f(55,40,-75);
    glVertex3f(-55,40,-75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-55,0,-68);
    glVertex3f(55,0,-68);
    glVertex3f(55,5,-68);
    glVertex3f(-55,5,-68);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,0,-68);
    glVertex3f(-85,0,-40);
    glVertex3f(-85,5,-40);
    glVertex3f(-55,5,-68);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,0,-68);
    glVertex3f(85,0,-40);
    glVertex3f(85,5,-40);
    glVertex3f(55,5,-68);
    glEnd();

//  tembokkiri
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f(-85,5,40);
    glVertex3f(-85,5,-40);
    glVertex3f(-85,40,-40);
    glVertex3f(-85,40,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-85,0,-40);
    glVertex3f(-85,0,40);
    glVertex3f(-85,5,40);
    glVertex3f(-85,5,-40);
    glEnd();


//  tembokkanan
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f(85,5,40);
    glVertex3f(85,5,-40);
    glVertex3f(85,40,-40);
    glVertex3f(85,40,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(85,0,-40);
    glVertex3f(85,0,40);
    glVertex3f(85,5,40);
    glVertex3f(85,5,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(85,0,40);
    glVertex3f(55,0,68);
    glVertex3f(55,5,68);
    glVertex3f(85,5,40);
    glEnd();


     //sudut dinding
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f(-85,39.8,-40);
    glVertex3f(-85,5,-40);
    glVertex3f(-55,5,-68);
    glVertex3f(-54.9,40,-75.4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(85,39.8,-40);
    glVertex3f(85,5,-40);
    glVertex3f(55,5,-68);
    glVertex3f(54.9,40,-75.4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(85,39.8,40);
    glVertex3f(85,5,40);
    glVertex3f(55,5,68);
    glVertex3f(54.9,40,75.4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-85,39.8,40);
    glVertex3f(-85,5,40);
    glVertex3f(-55,5,68);
    glVertex3f(-54.9,40,75.4);
    glEnd();

    //line loop
    //  tembokdepan
    glBegin(GL_LINE_LOOP);
    glColor3ub(169,169,169);
    glVertex3f(-55,5,68);
    glVertex3f(55,5,68);
    glVertex3f(55,40,75);
    glVertex3f(-55,40,75);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,0,68);
    glVertex3f(55,0,68);
    glVertex3f(55,5,68);
    glVertex3f(-55,5,68);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-85,0,40);
    glVertex3f(-55,0,68);
    glVertex3f(-55,5,68);
    glVertex3f(-85,5,40);
    glEnd();

//  tembokbelakang
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,5,-68);
    glVertex3f(55,5,-68);
    glVertex3f(55,40,-75);
    glVertex3f(-55,40,-75);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,0,-68);
    glVertex3f(55,0,-68);
    glVertex3f(55,5,-68);
    glVertex3f(-55,5,-68);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-55,0,-68);
    glVertex3f(-85,0,-40);
    glVertex3f(-85,5,-40);
    glVertex3f(-55,5,-68);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(55,0,-68);
    glVertex3f(85,0,-40);
    glVertex3f(85,5,-40);
    glVertex3f(55,5,-68);
    glEnd();

//  tembokkiri
    glBegin(GL_LINE_LOOP);
    glVertex3f(-85,5,40);
    glVertex3f(-85,5,-40);
    glVertex3f(-85,40,-40);
    glVertex3f(-85,40,40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-85,0,-40);
    glVertex3f(-85,0,40);
    glVertex3f(-85,5,40);
    glVertex3f(-85,5,-40);
    glEnd();


//  tembokkanan
    glBegin(GL_LINE_LOOP);
    glVertex3f(85,5,40);
    glVertex3f(85,5,-40);
    glVertex3f(85,40,-40);
    glVertex3f(85,40,40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(85,0,-40);
    glVertex3f(85,0,40);
    glVertex3f(85,5,40);
    glVertex3f(85,5,-40);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(85,0,40);
    glVertex3f(55,0,68);
    glVertex3f(55,5,68);
    glVertex3f(85,5,40);
    glEnd();


     //sudut dinding
    glBegin(GL_LINE_LOOP);
    glVertex3f(-85,39.8,-40);
    glVertex3f(-85,5,-40);
    glVertex3f(-55,5,-68);
    glVertex3f(-54.9,40,-75.4);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(85,39.8,-40);
    glVertex3f(85,5,-40);
    glVertex3f(55,5,-68);
    glVertex3f(54.9,40,-75.4);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(85,39.8,40);
    glVertex3f(85,5,40);
    glVertex3f(55,5,68);
    glVertex3f(54.9,40,75.4);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-85,39.8,40);
    glVertex3f(-85,5,40);
    glVertex3f(-55,5,68);
    glVertex3f(-54.9,40,75.4);
    glEnd();
}

void pintu (void)
{
    //belakang
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-50,0,-68.1);
    glVertex3f(-49,0,-68.1);
    glVertex3f(-49,3,-68.1);
    glVertex3f(-50,3,-68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-26,0,-68.1);
    glVertex3f(-25,0,-68.1);
    glVertex3f(-25,3,-68.1);
    glVertex3f(-26,3,-68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-2,0,-68.1);
    glVertex3f(-1,0,-68.1);
    glVertex3f(-1,3,-68.1);
    glVertex3f(-2,3,-68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(22,0,-68.1);
    glVertex3f(23,0,-68.1);
    glVertex3f(23,3,-68.1);
    glVertex3f(22,3,-68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(46,0,-68.1);
    glVertex3f(47,0,-68.1);
    glVertex3f(47,3,-68.1);
    glVertex3f(46,3,-68.1);
    glEnd();



    //depan
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-50,0,68.1);
    glVertex3f(-49,0,68.1);
    glVertex3f(-49,3,68.1);
    glVertex3f(-50,3,68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-26,0,68.1);
    glVertex3f(-25,0,68.1);
    glVertex3f(-25,3,68.1);
    glVertex3f(-26,3,68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-2,0,68.1);
    glVertex3f(-1,0,68.1);
    glVertex3f(-1,3,68.1);
    glVertex3f(-2,3,68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(22,0,68.1);
    glVertex3f(23,0,68.1);
    glVertex3f(23,3,68.1);
    glVertex3f(22,3,68.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(46,0,68.1);
    glVertex3f(47,0,68.1);
    glVertex3f(47,3,68.1);
    glVertex3f(46,3,68.1);
    glEnd();

}

    void display(void)
   {
       if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
    lapangan();
    tribun_depan_garis();
    gawang();
    renderScene();
    garis_lapangan();
    tribun_depan();
    atap();
    lampu();
    penonton();
    tembok();
    pintu();

    glPopMatrix();
    glutSwapBuffers();
   }

    void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;


}

void mouseMotion(int x, int y)
{
    asu();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }

}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi =1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, lebar / tinggi, 50, 500);
    glTranslated(0, -50, -150);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, lebar / 1, tinggi / 1);

}

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            glTranslated(0,0,3);
            break;
        case 'd':
        case 'D':
            glTranslated(3,0,0);
            break;
        case 's':
        case 'S':
            glTranslated(0,0,-3);
            break;
        case 'a':
        case 'A':
            glTranslated(-3,0,0);
            break;
        case '7':
            glTranslated(0,3,0);
            break;
        case '9':
            glTranslated(0,-3,0);
            break;
        case '2':
            glRotated(2,1,0,0);
            break;
        case '8':
            glRotated(-2,1,0,0);
            break;
        case '6':
            glRotated(2,0,1,0);
            break;
        case '4':
            glRotated(-2,1,0,0);
            break;
        case '1':
            glRotated(2,0,0,1);
            break;
        case '3':
            glRotated(-2,0,0,1);
            break;
        case '5':
            if (is_depth)
            {
                is_depth = 0;
                glEnable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glDisable(GL_DEPTH_TEST);
            }
    }
    display();


}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(250, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("PENYU - 672018114_672018132");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();

    return 0;
}
