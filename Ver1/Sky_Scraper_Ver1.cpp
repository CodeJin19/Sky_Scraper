#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int top[4];
int bot[4];
int lft[4];
int rgt[4];
int fld[4][4];

bool check()
{
	int max, cnt;

	//top 검사
	for (int x = 0; x < 4; x++)
	{
		max = 0;
		cnt = 0;
	
		if (top[x] != 0)
		{
			for (int y = 0; y < 4; y++)
			{
				if (max < fld[y][x])
				{
					cnt++;
					max = fld[y][x];
				}
			}
		}

		if (top[x] != cnt)
		{
			cout << "wrong!\n";
			cout << "top[" << x << "] != " << cnt << endl;
			return false;
		}
	}

	//bot 검사
	for (int x = 0; x < 4; x++)
	{
		max = 0;
		cnt = 0;

		if (bot[x] != 0)
		{
			for (int y = 3; 0 <= y; y--)
			{
				if (max < fld[y][x])
				{
					cnt++;
					max = fld[y][x];
				}
			}
		}

		if (bot[x] != cnt)
		{
			cout << "wrong!\n";
			cout << "bot[" << x << "] != " << cnt << endl;
			return false;
		}
	}

	//left 검사
	for (int y = 0; y < 4; y++)
	{
		max = 0;
		cnt = 0;

		if (lft[y] != 0)
		{
			for (int x = 0; x < 4; x++)
			{
				if (max < fld[y][x])
				{
					cnt++;
					max = fld[y][x];
				}
			}
		}

		if (lft[y] != cnt)
		{
			cout << "wrong!\n";
			cout << "lft[" << y << "] != " << cnt << endl;
			return false;
		}
	}

	//right 검사
	for (int y = 0; y < 4; y++)
	{
		max = 0;
		cnt = 0;

		if (rgt[y] != 0)
		{
			for (int x = 3; 0 <= x; x--)
			{
				if (max < fld[y][x])
				{
					cnt++;
					max = fld[y][x];
				}
			}
		}

		if (rgt[y] != cnt)
		{
			cout << "wrong!\n";
			cout << "rgt[" << y << "] != " << cnt << endl;
			return false;
		}
	}
	return true;
}

void printFld()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << fld[i][j];
		}
		cout << endl;
	}
}

void fill (int y, int x, int left)
{
	int cache[5];
	int t;

	cout << "fill (" << x << ", " << y << ", " << left << ")\n";

	if (left == 0)
	{
		if (check())
		{
			printFld();
			cin >> t;
		}

		return;
	}

	for (int i = 1; i < 5; i++)
	{
		cache[i] = 0;
	}

	for (int i = 0; i < x; i++)
	{
		cache[fld[y][i]] = 1;
	}

	for (int i = 0; i < y; i++)
	{
		cache[fld[i][x]] = 1;
	}

	for (int i = 1; i < 5; i++)
	{
		if (cache[i] == 0)
		{
			fld[y][x] = i;
			/*
			printFld();
			cin >> t;
			*/
			if (x == 3)
			{
				fill(y + 1, 0, left - 1);
			}
			else
			{
				fill(y, x + 1, left - 1);
			}
		}
	}
}

int main()
{
	//빈칸은 0으로 입력
	cout << "enter top\n";
	for (int i = 0; i < 4; i++)
	{
		cin >> top[i];
	}

	cout << "enter bottom\n";
	for (int i = 0; i < 4; i++)
	{
		cin >> bot[i];
	}

	cout << "enter left\n";
	for (int i = 0; i < 4; i++)
	{
		cin >> lft[i];
	}

	cout << "enter right\n";
	for (int i = 0; i < 4; i++)
	{
		cin >> rgt[i];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fld[i][j] = 0;
			//fld[i][j][1] = 0;
		}
	}

	fill(0, 0, 16);

	return 0;
}
