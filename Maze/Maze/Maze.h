#pragma once

#include "Stack.h"

#define N 6
static int maze[N][N] = {
	{0,0,0,0,0,0},
	{0,0,1,1,1,1},
	{0,0,1,0,1,0},
	{0,0,1,1,1,1},
	{0,0,1,0,0,0},
	{0,0,1,0,0,0},
};

//static int maze[N][N] = {{0,0,0,0,0,0},  
//                         {0,0,1,1,0,1},
//                         {0,0,1,0,0,0},
//                         {0,0,1,1,1,0}, 
//	                     {0,0,1,0,1,1}, 
//	                     {0,0,1,0,0,0}};


void MazePrint(); //��ӡ�Թ�
int MazeGetPath(Pos entry,Pos exit); //�ҳ�·
int CheckMaze(Pos pos,Pos cur);
void MazeGetPathR(Pos entry);//��·�����Թ�

void TestMaze();