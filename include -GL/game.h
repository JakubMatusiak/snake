#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define F1 1
#define F2 -1
#define F4 2
#define F3 -2


#define MAX 60

void initGrid(int,int);
void drawGrid();
void drawSnake();
void drawSnake2();
void drawFood();
void random(int&,int&);

#endif
