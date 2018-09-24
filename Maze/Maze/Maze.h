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


void MazePrint(); //打印迷宫
int MazeGetPath(Pos entry,Pos exit); //找出路
int CheckMaze(Pos pos,Pos cur);
void MazeGetPathR(Pos entry);//多路带环迷宫

void TestMaze();