#include<stdlib.h>
#include<GL/glut.h>

GLfloat podBase [] [3] = { {0.0,0.0,0.0}, {2.0,0.0,0.0}, {2.0,0.0,-2.0}, {0.0,0.0,-2.0} ,{0.0,0.25,0.0}, {2.0,0.25,0.0}, {2.0,0.25,-2.0}, {0.0,0.25,-2.0}};
GLfloat podTop [] [3] = { {0.0,4.75,0.0}, {2.0,4.75,0.0}, {2.0,4.75,-2.0}, {0.0,4.75,-2.0} ,{0.0,5.0,0.0}, {2.0,5.0,0.0}, {2.0,5.0,-2.0}, {0.0,5.0,-2.0}};
GLfloat podMain [] [3] = { {0.25,0.375,-0.25},{1.75,0.375,-0.25},{1.875,0.375,-2.0},{0.25,0.375,-2.0},{0.25,4.625,-0.25},{1.75,4.625,-0.25},{1.875,4.625,-2.0},{0.25,4.625,-2.0}};

GLfloat tableBase [][3] = {{0.0,0.0,0.0},{5.0,0.0,0.0},{5.0,0.0,-2.0},{0.0,0.0,-2.0},{0.0,0.5,0.0},{5.0,0.5,0.0},{5.0,0.5,-2.0},{0.0,0.5,-2.0}};
GLfloat tableMain [][3] = {{0.25,0.75,-0.25},{4.75,0.75,-0.25},{4.75,0.75,-2.0},{0.25,0.75,-2.0},{0.25,3.75,-0.25},{4.75,3.75,-0.25},{4.75,3.75,-2.0},{0.25,3.75,-2.0}};

GLfloat stageBase [][3] = {{0.0,0.0,0.0},{10.0,0.0,0.0},{12.0,0.0,-3.0},{13,0.0,-5.0},{-3.0,0.0,-5.0},{-2.0,0.0,-3.0}};
GLfloat stageTop [][3] = {{0.0,1.0,0.0},{10.0,1.0,0.0},{12.0,1.0,-3.0},{13,1.0,-5.0},{-3.0,1.0,-5.0},{-2.0,1.0,-3.0}};

GLfloat colors [] [3] = {{1.0,1.0,1.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

int startx, starty, moving;

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glVertex3fv(podBase[a]);
		glVertex3fv(podBase[b]);
		glVertex3fv(podBase[c]);
		glVertex3fv(podBase[d]);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3fv(podMain[a]);
		glVertex3fv(podMain[b]);
		glVertex3fv(podMain[c]);
		glVertex3fv(podMain[d]);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3fv(podTop[a]);
		glVertex3fv(podTop[b]);
		glVertex3fv(podTop[c]);
		glVertex3fv(podTop[d]);
	glEnd();

}

void slantpod(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glVertex3fv(podBase[a]);
		glVertex3fv(podBase[b]);
		glVertex3fv(podMain[c]);
		glVertex3fv(podMain[d]);
	glEnd();
}

void slantpod2(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glVertex3fv(podMain[a]);
		glVertex3fv(podMain[b]);
		glVertex3fv(podTop[c]);
		glVertex3fv(podTop[d]);
	glEnd();
}

void colorcube()
{
	glPushMatrix();
	glRotatef(15.0,0.0,1.0,0.0);
	glTranslatef(-3.25,0.0,-0.25);
	glColor3f(1.0,0.8,1.0);
	polygon(0,1,2,3);
	glColor3f(1.0,0.6,0.1);
	polygon(0,1,5,4);
	glColor3f(1.0,0.6,0.1);
	polygon(1,2,6,5);
	glColor3f(1.0,0.65,0.1);
	polygon(0,3,7,4);
	glColor3f(1.0,0.7,1.0);
	slantpod(4,5,1,0);
	glColor3f(1.0,0.8,1.0);
	slantpod(5,6,2,1);
	glColor3f(1.0,0.8,1.0);
	slantpod(4,7,3,0);
	glColor3f(1.0,0.7,1.0);
	slantpod2(4,5,1,0);
	glColor3f(1.0,0.8,1.0);
	slantpod2(5,6,2,1);
	glColor3f(1.0,0.8,1.0);
	slantpod2(4,7,3,0);
	glPopMatrix();
}

void table(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glVertex3fv(tableBase[a]);
		glVertex3fv(tableBase[b]);
		glVertex3fv(tableBase[c]);
		glVertex3fv(tableBase[d]);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3fv(tableMain[a]);
		glVertex3fv(tableMain[b]);
		glVertex3fv(tableMain[c]);
		glVertex3fv(tableMain[d]);
	glEnd();

	glPushMatrix();
	glTranslatef(0.0,3.75,0.0);
	glBegin(GL_POLYGON);
		glVertex3fv(tableBase[a]);
		glVertex3fv(tableBase[b]);
		glVertex3fv(tableBase[c]);
		glVertex3fv(tableBase[d]);
	glEnd();
	glPopMatrix();

}

void slanttable(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glVertex3fv(tableBase[a]);
		glVertex3fv(tableBase[b]);
		glVertex3fv(tableMain[c]);
		glVertex3fv(tableMain[d]);
	glEnd();
}

void colortable()
{
	glColor3f(0.8,0.6,0.1);
	table(0,1,2,3);
	glColor3f(0.8,0.6,0.1);
	table(4,5,6,7);
	glColor3f(0.8,0.5,0.0);
	table(0,1,5,4);
	glColor3f(0.8,0.4,0.0);
	table(1,2,6,5);
	glColor3f(0.8,0.4,0.0);
	table(0,3,7,4);
	glColor3f(0.8,0.4,0.0);
	table(2,3,7,6);
	glColor3f(0.8,0.6,0.1);
	slanttable(4,5,1,0);
	glColor3f(0.8,0.6,0.1);
	slanttable(5,6,2,1);
	glColor3f(0.8,0.6,0.1);
	slanttable(6,7,3,2);
	glColor3f(0.8,0.6,0.1);
	slanttable(4,7,3,0);
}

void stage(int a, int b, int c, int d,int e,int f)
{
	glBegin(GL_POLYGON);
		glVertex3fv(stageBase[a]);
		glVertex3fv(stageBase[b]);
		glVertex3fv(stageBase[c]);
		glVertex3fv(stageBase[d]);
		glVertex3fv(stageBase[e]);
		glVertex3fv(stageBase[f]);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3fv(stageTop[a]);
		glVertex3fv(stageTop[b]);
		glVertex3fv(stageTop[c]);
		glVertex3fv(stageTop[d]);
		glVertex3fv(stageTop[e]);
		glVertex3fv(stageTop[f]);
	glEnd();
}

void stagefront(int a,int b)
{
	glBegin(GL_POLYGON);
		glVertex3fv(stageBase[a]);
		glVertex3fv(stageBase[b]);
		glVertex3fv(stageTop[b]);
		glVertex3fv(stageTop[a]);
	glEnd();
}

void colorstage()
{
	glPushMatrix();
	glTranslatef(-4.5,-1.0,1.1);
	glColor3f(0.37,0.37,0.37);
	stage(0,1,2,3,4,5);
	glColor3f(0.5,0.5,0.5);
	stagefront(0,1);
	glColor3f(0.45,0.45,0.45);
	stagefront(1,2);
	glColor3f(0.42,0.42,0.42);
	stagefront(2,3);
	stagefront(3,4);
	stagefront(4,5);
	glColor3f(0.45,0.45,0.45);
	stagefront(5,0);
	glPopMatrix();
}


void backwall()
{
	glPushMatrix();
	glTranslatef(-4.0,-1.0,1.0);
	glTranslatef(-6.5,0.0,-5.0);
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,0.0,0.0);
		glColor3f(1.0,0.6,0.5);
		glVertex3f(22.0,0.0,0.0);
		glVertex3f(22.0,13.5,0.0);
		glVertex3f(0.0,13.5,0.0);
	glEnd();
	glPopMatrix();
}

void leftwall()
{
	glPushMatrix();
	glTranslatef(-4.0,-1.0,1.0);
	glTranslatef(-6.5,0.0,-5.0);
	glRotatef(-20.0,0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,3.5);
		glVertex3f(0.0,13.5,3.5);
		glVertex3f(0.0,13.5,0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,0.0,25.0);
		glVertex3f(0.0,13.5,25.0);
		glVertex3f(0.0,13.5,21.5);
		glVertex3f(0.0,0.0,21.5);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,0.0,21.5);
		glVertex3f(0.0,7.0,21.5);
		glVertex3f(0.0,7.0,3.5);
		glVertex3f(0.0,0.0,3.5);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,13.5,21.5);
		glVertex3f(0.0,11.0,21.5);
		glVertex3f(0.0,11.0,3.5);
		glVertex3f(0.0,13.5,3.5);
	glEnd();
	glPopMatrix();
}

void window()
{
	glPushMatrix();
	glTranslatef(-4.0,-1.0,1.0);
	glTranslatef(-6.5,0.0,-5.0);
	glRotatef(-20.0,0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glColor4f(0.9,0.9,1.0,0.2);
		glVertex3f(0.0,11.0,21.5);
		glColor4f(0.2,0.2,0.2,0.4);
		glVertex3f(0.0,11.0,3.5);
		glVertex3f(0.0,7.0,3.5);
		glVertex3f(0.0,7.0,21.5);
	glEnd();
	glPopMatrix();
}

void kettle()
{
	glPushMatrix();
	glTranslatef(1.0,4.5,-1.0);
	glColor3f(1.0,1.0,1.0);
	glutSolidTeapot(0.5);
	glPopMatrix();
}

void rightwall()
{
	glPushMatrix();
	glTranslatef(-4.0,-1.0,1.0);
	glTranslatef(15.5,0.0,-5.0);
	glRotatef(20.0,0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,0.75);
		glVertex3f(0.0,13.5,0.75);
		glVertex3f(0.0,13.5,0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,13.5,4.0);
		glVertex3f(0.0,13.5,25.0);
		glVertex3f(0.0,0.0,25.0);
		glVertex3f(0.0,0.0,4.0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.4);
		glVertex3f(0.0,6.0,0.75);
		glVertex3f(0.0,13.5,0.75);
		glVertex3f(0.0,13.5,4.0);
		glVertex3f(0.0,6.0,4.0);
	glEnd();
	glPopMatrix();
}

void flooring()
{
	glPushMatrix();
	glTranslatef(-4.5,-1.0,1.0);
	glTranslatef(-6.0,0.0,-5.0);
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.6,0.6);
		glVertex3f(0.0,0.0,0.0);
		glColor3f(0.4,0.4,0.4);
		glVertex3f(22.0,0.0,0.0);
		glVertex3f(30.55,0.0,23.49);
		glVertex3f(-8.55,0.0,23.49);
	glEnd();
	glPopMatrix();
}

void board()
{
	glPushMatrix();
	glTranslatef(-4.5,-1.0,1.0);
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.3,0.0);
		glVertex3f(-1.0,4.0,-4.9);
		glVertex3f(11.0,4.0,-4.9);
		glVertex3f(11.0,9.0,-4.9);
		glVertex3f(-1.0,9.0,-4.9);
	glEnd();
	glPopMatrix();
}

void dustbin(){
	//Left face
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(-0.85,0.9,0.0);
		glScalef(0.2,2.0,1.9);
		glutSolidCube(1);
	glPopMatrix();
	//Right Face
	glPushMatrix();
		glTranslatef(0.85,0.9,0.0);
		glScalef(0.2,2.0,1.9);
		glutSolidCube(1);
	glPopMatrix();
	// BackFace
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
		glTranslatef(0.0,0.9,-0.85);
		glScalef(1.5,2.0,0.2);
		glutSolidCube(1);
	glPopMatrix();
	// Front Face
	glPushMatrix();
		glTranslatef(0.0,0.9,0.85);
		glScalef(1.5,2.0,0.2);
		glutSolidCube(1);
	glPopMatrix();
	//Bottom Face
	glColor3f(1.0,0.9,0.9);
	glPushMatrix();
		glScalef(1.5,0.2,1.5);
		glutSolidCube(1);
	glPopMatrix();
}

void movedustbin()
{
	glPushMatrix();
	glTranslatef(-9.0,-0.9,-2.5);
	dustbin();
	glPopMatrix();
}

void door()
{
	glColor3f(0.9,0.8,0.0);
	glPushMatrix();
		glTranslatef(11.59,2.0,-3.25);
		glRotatef(-45.0,0.0,1.0,0.0);
		glTranslatef(0.0,0.0,2.0);
		glScalef(0.5,6.0,4.0);
		glutSolidCube(1);
	glPopMatrix();
}

void ceiling()
{
	glPushMatrix();
	glTranslatef(-4.5,-1.0,1.0);
	glTranslatef(-6.0,0.0,-5.0);
	glTranslatef(0.0,13.5,0.0);
	glBegin(GL_POLYGON);
		glColor4f(0.9,0.9,1.0,0.2);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(22.0,0.0,0.0);
		glVertex3f(30.55,0.0,23.49);
		glVertex3f(-8.55,0.0,23.49);
	glEnd();
	glPopMatrix();
}

void bench()
{
	glPushMatrix();
	glScalef(1.5, 2.5, 1.5);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.2, 0.1);

	//
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, -0.5);
	glVertex3f(-2.0, 0.0, -0.5);

	//Right
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, -0.5);
	glVertex3f(2.0, 1.0, -0.5);
	glVertex3f(2.0, 1.0, 1.0);
	glVertex3f(2.0, 0.8, 1.0);
	glVertex3f(2.0, 0.8, 0.2);
	glVertex3f(2.0, 0.6, 0.0);

	//Left
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.0, -0.5);
	glVertex3f(-2.0, 1.0, -0.5);
	glVertex3f(-2.0, 1.0, 1.0);
	glVertex3f(-2.0, 0.8, 1.0);
	glVertex3f(-2.0, 0.8, 0.2);
	glVertex3f(-2.0, 0.6, 0.0);

	//Front
	glVertex3f(-2.0, 0.0, -0.5);
	glVertex3f(2.0, 0.0, -0.5);
	glVertex3f(2.0, 1.0, -0.5);
	glVertex3f(-2.0, 1.0, -0.5);

	//Top
	glVertex3f(-2.0, 1.0, -0.5);
	glVertex3f(-2.0, 1.0, 1.0);
	glVertex3f(2.0, 1.0, 1.0);
	glVertex3f(2.0, 1.0, -0.5);

	/*Seat*/
	glColor3f(0.6, 0.3, 0.2);
	//Right
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 1.0, 2.0);
	glVertex3f(2.0, 1.0, 1.5);
	glVertex3f(2.0, 0.5, 1.5);
	glVertex3f(2.0, 0.5, 1.0);
	glVertex3f(2.0, 0.0, 1.0);

	//Left
	glVertex3f(-2.0, 0.0, 2.0);
	glVertex3f(-2.0, 1.0, 2.0);
	glVertex3f(-2.0, 1.0, 1.5);
	glVertex3f(-2.0, 0.5, 1.5);
	glVertex3f(-2.0, 0.5, 1.0);
	glVertex3f(-2.0, 0.0, 1.0);

	//Back
	glVertex3f(-2.0, 1.0, 2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 1.0, 2.0);

	//Front
	glVertex3f(-2.0, 1.0, 1.5);
	glVertex3f(-2.0, 0.0, 1.5);
	glVertex3f(2.0, 0.0, 1.5);
	glVertex3f(2.0, 1.0, 1.5);

	//Base - bottom
	glVertex3f(-2.0, 0.0, 1.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, 1.0);

	//Base - seat
	glVertex3f(-2.0, 0.5, 1.0);
	glVertex3f(-2.0, 0.5, 2.0);
	glVertex3f(2.0, 0.5, 2.0);
	glVertex3f(2.0, 0.5, 1.0);

	glEnd();
	glPopMatrix();
}

void fillSeats ()
{
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.5);
	for (int i = 1; i < 4 ; i++)
	{
		glTranslatef(0.0, 0.0,  5);
		bench();
		glTranslatef(7.5, 0.0, 0.0);
		bench();
		glTranslatef(-15.0, 0.0, 0.0);
		bench();
		glTranslatef(7.5, 0.0, 0.0);
	}
	glPopMatrix();
}

GLfloat theta [] = {0.0, 0.0, 0.0};
GLint axis = 2;
//GLdouble viewer [] = {0.0, 0.0, 30.0};
GLdouble viewer [] = {0.0, 0.5, 5.0};

void display(void)
{
	glClearColor(0.3, 0.2, 1.0, 0.1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	glTranslatef(-0.0,-5.0,0.0);
	colorcube();
	colortable();
	colorstage();
	backwall();
	rightwall();
	leftwall();
	flooring();
	door();
	kettle();
	movedustbin();
	board();
	fillSeats();
	window();
	ceiling();
	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
  	if (button == GLUT_LEFT_BUTTON)
  	{
		if (state == GLUT_DOWN) {
		  moving = 1;
		  startx = x;
		  starty = y;
		}
		if (state == GLUT_UP) {
		  moving = 0;
		}
  	}
	display();
}

void motion(int x, int y)
{
  if (moving) {
    theta[1] = theta[1] + (x - startx);
    theta[0] = theta[0] + (y - starty);
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
}

void myReshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0,25.0,-20.0 * (GLfloat) h/ (GLfloat) w,20.0 * (GLfloat) h/ (GLfloat) w,-20.0,20.0);
	//glFrustum(-20.0,20.0,-20.0 * (GLfloat) h/ (GLfloat) w,20.0 * (GLfloat) h/ (GLfloat) w,20.0,40.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900,700);
	glutCreateWindow("classroom");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutMainLoop();
}
