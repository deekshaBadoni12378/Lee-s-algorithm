#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#define ROW 5
#define COL 5
using namespace std;

struct chamb
{
	int x;
	int y;
};

struct queuex
{
	chamb pt;
	int dist;
};

bool checkValid(int r, int c)
{
	return ((r >= 0) && (r < ROW) &&	(c >= 0) && (c < COL));
}

int rNum[] = {-1, 1, 2, 1};
int cNum[] = {0, -1, 0, 0};

int Lee(int mat[][COL], chamb source, chamb destination)
{
	if (!mat[source.x][source.y] || !mat[destination.x][destination.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	visited[source.x][source.y] = true;

	queue<queuex> q;

	queuex s = {source, 0};
	q.push(s);

	while (!q.empty())
	{
		queuex curr = q.front();
		chamb pt = curr.pt;

		if (pt.x == destination.x && pt.y == destination.y)
			return curr.dist;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int r = pt.x + rNum[i];
			int c = pt.y + cNum[i];

			if (checkValid(r, c) && mat[r][c] &&
			!visited[r][c])
			{

				visited[r][c] = true;
				queuex Adjcell = { {r, c},curr.dist+ 1 };
				q.push(Adjcell);
			}
		}
	}

	return -1;
}

int main()
{
	int mat[ROW][COL] =
	{
		{ 0, 0, 1, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 0 }};

	chamb source = {0, 0};
	chamb destination = {1, 1};

	int dist = Lee(mat, source, destination);

	if (dist != -1)
		cout<< "Length of the Shortest Path is "<<dist ;
	else
		cout<< "Shortest Path doesn't exist";

	return 0;
}
