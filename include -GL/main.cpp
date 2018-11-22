#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include "game.h"
#include <stdlib.h>

#define COLUMNS 40
#define ROWS 40
#define FPS 10


static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

extern short sDirection;
bool gameOver=false;

int score=0;

void timer_callback(int);
void display_callback();
void display_callback2();
void reshape_callback(int,int);
void keyboard_callback(int,int,int);
void keyboard_callback2(int,int,int);
void display_menu();
void createMenu();



void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    initGrid(COLUMNS,ROWS);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    window = glutCreateWindow("snake");
    createMenu();
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display_menu);
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();
    return EXIT_SUCCESS;
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawSnake2();
    drawFood();
    glutSwapBuffers();
    if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="Wynik: ";
        strcat(text,_score);
        MessageBox(NULL,text,"Koniec Gry",0);
        exit(0);
    }
display_callback2();
}

void display_callback2()
{

   drawSnake2();

}
void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void keyboard_callback(int key, int, int)
{
    switch(key)
    {
    case GLUT_KEY_UP:
            if(sDirection!=DOWN)
                sDirection=UP;
            break;
     case GLUT_KEY_DOWN:
             if(sDirection!=UP)
                sDirection=DOWN;
            break;
      case GLUT_KEY_RIGHT:
             if(sDirection!=LEFT)
                sDirection=RIGHT;
            break;
      case GLUT_KEY_LEFT:
             if(sDirection!=RIGHT)
                sDirection=LEFT;
            break;
    }
}

void keyboard_callback2(int key, int, int)
{
 switch(key)
    {
    case GLUT_KEY_F1:
            if(sDirection!=DOWN)
                sDirection=UP;
            break;
     case GLUT_KEY_F2:
             if(sDirection!=UP)
                sDirection=DOWN;
            break;
      case GLUT_KEY_F4:
             if(sDirection!=LEFT)
                sDirection=RIGHT;
            break;
      case GLUT_KEY_F3:
             if(sDirection!=RIGHT)
                sDirection=LEFT;
            break;
    }
}

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();

} void createMenu(void){
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("1", 1);
    glutAddSubMenu("2", 2);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display_menu(void){
  glClear(GL_COLOR_BUFFER_BIT);   if(value == 1){
    return; //glutPostRedisplay();
  }else if(value == 1){
    glPushMatrix();
////
    glPopMatrix();
  }else if(value == 2){
    glPushMatrix();
////
    glPopMatrix();

  }
  glFlush();
}




