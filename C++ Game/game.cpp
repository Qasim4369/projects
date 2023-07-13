//============================================================================
// Name        : N_i201783_project.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include "game.h"
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

class Canvas {
public:
	void SetCanvasSize(int width, int height) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

};

	int xI = 400, yI = 400;
	int cI = 300, vI = 300;
	int dI = 0, dII = 0;
	int aI = 0, aII = 0;

void drawCar() {
	DrawSquare(xI, yI, 30, colors[WHITE]);
	DrawSquare(xI-10, yI+10, 10, colors[WHITE]);
	DrawSquare(xI - 19, yI + 10, 10, colors[WHITE]);
	DrawSquare(xI + 15, yI + 25, 15, colors[WHITE]);
	DrawSquare(xI + 15, yI - 10, 15, colors[WHITE]);
	DrawSquare(xI + 25, yI + 25, 15, colors[WHITE]);
	DrawSquare(xI + 25, yI - 10, 15, colors[WHITE]);
	DrawSquare(xI , yI + 25, 15, colors[WHITE]);
	DrawSquare(xI , yI - 10, 15, colors[WHITE]);
	DrawSquare(xI-10, yI + 25, 15, colors[WHITE]);
	DrawSquare(xI-10, yI - 10, 15, colors[WHITE]);
	DrawCircle(xI+15, yI+15, 10, colors[BLACK]);
	glutPostRedisplay();
}
void drawCar1() {
	
	DrawSquare(cI, vI, 30, colors[WHITE]);
	DrawSquare(cI + 30, vI + 10, 10, colors[WHITE]);
	DrawSquare(cI + 40, vI + 10, 10, colors[WHITE]);
	DrawSquare(cI + 15, vI + 25, 15, colors[WHITE]);
	DrawSquare(cI + 15, vI - 10, 15, colors[WHITE]);
	DrawSquare(cI + 25, vI + 25, 15, colors[WHITE]);
	DrawSquare(cI + 25, vI - 10, 15, colors[WHITE]);
	DrawSquare(cI, vI + 25, 15, colors[WHITE]);
	DrawSquare(cI, vI - 10, 15, colors[WHITE]);
	DrawSquare(cI - 10, vI + 25, 15, colors[WHITE]);
	DrawSquare(cI - 10, vI - 10, 15, colors[WHITE]);
	DrawCircle(cI + 15, vI + 15, 10, colors[BLACK]);
	glutPostRedisplay();
}
void cannon() {
	dI = xI;
	dII = yI;
	DrawSquare(dI - 10, dII + 10, 10, colors[WHITE]);
	glutPostRedisplay();
}
void cannon1() {
	aI = cI;
	aII = vI;
	DrawSquare(aI - 10, aII + 10, 10, colors[WHITE]);
	glutPostRedisplay();
}
bool flag = true;
void movecannon1() {

		if (aI > 10 && flag) {
			aI -= 10;
			cout << "going left";
			if (aI < 100)
	
				flag = false;
	
		}
		else if (aI < 1010 && !flag) {
			cout << "go right";
			aI += 10;
			if (aI > 900)
				flag = true;
		}
}

void movecannon() {

		if (dI > 10 && flag) {
			dI -= 10;
			cout << "going left";
			if (dI < 100)
	
				flag = false;
	
		}
		else if (dI < 1010 && !flag) {
			cout << "go right";
			dI += 10;
			if (dI > 900)
				flag = true;
		}
}
//void moveCar() {
//
//	if (xI > 10 && flag) {
//		xI -= 10;
//		cout << "going left";
//		if (xI < 100)
//
//			flag = false;
//
//	}
//	else if (xI < 1010 && !flag) {
//		cout << "go right";
//		xI += 10;
//		if (xI > 900)
//			flag = true;
//	}
//}
//void movecannon1() {
//	dI -= 10;
//}
//void movecannon() {
//	aI += 10;
//}
//void PrintableKeys(unsigned char key, int x, int y) {
//	if (key == 27/* Escape key ASCII*/) {
//		exit(1); // exit the program when escape key is pressed.
//	}
//	if (key == 'p' || key == 'P') {
//		movecannon1();
//	}
//	if (key == 'b' || key == 'B') //Key for placing the bomb
//	{
//		movecannon();
//
//	}
//	glutPostRedisplay();
//}
/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/ {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.1/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
		0.2/*Blue Component*/, 2 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	DrawSquare(0, 300, 60, colors[WHITE]);

	//Green Square
	DrawSquare(745, 300, 60, colors[WHITE]);

	//Display Score
	DrawString(50, 800, "Score=0", colors[MISTY_ROSE]);

	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	/*DrawTriangle(300, 450, 340, 450, 320, 490, colors[MISTY_ROSE]);*/



	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	int x = 20;
	for (int i = 0; i < 40; i++) {
		DrawLine(x, 0, x, 600, 1, colors[MISTY_ROSE]);
		x += 20;
	}
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	//
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	//
	drawCar();
	drawCar1();
	cannon();
	cannon1();
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
		== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	}
	else if (key
		== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	}
	else if (key
		== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
		== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

void NonPrintableKey(unsigned char key, int x, int y) {
	if (key
		== 'a' /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		cI -= 10;

	}
	else if (key
		== 'd' /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		cI += 10;
	}
	else if (key
		== 'w'/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		vI += 10;
	}

	else if (key
		== 's'/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		vI -= 10;
	}
	else if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	else if (key == 1/* Escape key ASCII*/) {
		
	}
	else if (key == 13)
	{
		glutDisplayFunc(GameDisplay);
	}
	else if (key == 'p' || key == 'P') {
		cannon();
		for (int i = 0; i < 200; i++)
		{
			movecannon();
			cout << "p is pressed";
			dI -= 2;
		}
		
	}
	else if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		cannon1();
		for (int i = 0; i < 200; i++)
		{
			movecannon1();
			cout << "b is pressed";
			aI += 2;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (key == 'p' || key == 'P') {
		cout << "p is pressed" << endl;
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		cout << " b is pressed";
	}
	if (key== 1)
	{
		cout << "Enter is pressed" << endl;
		glutDisplayFunc(GameDisplay);
	}
	//if (x == '2')
	//{
	//	cout << "2 is pressed" << endl;
	//}
	//if (x == '3')
	//{
	//	cout << "3 is pressed" << endl;
	//}

}
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

 void Timer(int m) {
 
 	//// implement your functionality here
	 movecannon();
	 movecannon1();
 	// once again we tell the library to call our Timer function after next 1000/FPS
 	glutTimerFunc(100, Timer, 0);
 }

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
void menu_display()
{
	glClearColor(1/*Red Component*/, 1, //148.0/255/*Green Component*/,
		1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
  //Red Square
	DrawString(100, 300, "Start game(press 1)", colors[BLACK]);
	DrawString(100, 400, "Exit game(press Escape)", colors[BLACK]);
	glutSwapBuffers();

}

void stop() {//when game is paused


	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(330, 400, "Pause", colors[GREEN]);
	DrawString(330, 350, "1.Continue", colors[RED]);
	DrawString(330, 320, "2.See High-Score", colors[RED]);
	DrawString(330, 290, "3.Help", colors[RED]);
	DrawString(330, 260, "4.Exit", colors[RED]);
	DrawString(330, 230, "5.Start a New Game", colors[RED]);
	glutSwapBuffers();

}

int main(int argc, char* argv[]) {
	int width = 800, height = 600; // i have set my window size to be 800 x 600
	cout << "************************" << endl;
	Canvas c1;



	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Combat"); // set the title of our game window
	c1.SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(menu_display); // tell library which function to call for drawing Canvas.
//	glutDisplayFunc(); // tell library which function to call for drawing Canvas.
	
	
	glutDisplayFunc(GameDisplay);
	glutDisplayFunc(menu_display);

	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	glutKeyboardFunc(NonPrintableKey);
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
