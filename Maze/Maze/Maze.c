#include "Maze.h"


void MazePrint()
{
	int i = 0;
	int j = 0;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int CheckMaze(Pos next,Pos cur)
{
	if((next.row >= 0 && next.row < N && next.col >= 0 && next.col < N)
		&& (maze[next.row][next.col] == 1 || maze[next.row][next.col] > maze[cur.row][cur.col] + 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int MazeGetPath(Pos entry,Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	while(StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
		maze[cur.row][cur.col] = 2;//����߹��� ��ֹ�߻�ͷ·

		if(cur.row == exit.row
			&& cur.col == exit.col) //�ҵ����ڷ���1
		{
			StackDestory(&path);
			return 1;
			printf("\n");
		}
		//��
		next = cur;
		next.row--;
		if (CheckMaze(next, cur))
		{
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next.row++;
		if (CheckMaze(next, cur))
		{
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next.col--;
		if (CheckMaze(next, cur))
		{
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next.col++;
		if (CheckMaze(next, cur))
		{
			StackPush(&path, next);
			continue;
		}

		StackPop(&path);  //���� �Ҳ���·�ͻ���
	}
	return 0;
}

int pathsize = 0;

void MazeGetPathR(Pos entry)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	maze[entry.row][entry.col] = 2;

	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
	
		if (cur.col == 5)
		{
			if(pathsize == 0 
				|| StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}

		// ��
		next = cur;
		next.row--;
		if (CheckMaze(next,cur))
		{
			maze[next.row][next.col] = maze[cur.row][cur.col] + 1;//ÿ�μ�1 
			StackPush(&path, next);
			continue;
		}

		// ��
		next = cur;
		next.row++;
		if (CheckMaze(next,cur))
		{
			maze[next.row][next.col] = maze[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}

		// ��
		next = cur;
		next.col--;
		if (CheckMaze(next,cur))
		{
			maze[next.row][next.col] = maze[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}

		// ��
		next = cur;
		next.col++;
		if (CheckMaze(next,cur))
		{
			maze[next.row][next.col] = maze[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}
		// ����
		StackPop(&path);
	}
}




void TestMaze()
{
	Pos exit;
	Pos entry;
	entry.row  = 5;
	entry.col = 2;
	exit.row = 3;
	exit.col = 5;
	/*MazePrint(&path);*/
	/*printf("\n");
	printf("%d \n",MazeGetPath(entry,exit));*/
	
	MazePrint();
	MazeGetPathR(entry);
	MazePrint();
	printf("���·���� %d ",pathsize);
}
