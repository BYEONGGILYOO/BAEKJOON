#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <limits>

using namespace std;

int N, M;
int input[8][8];
int copy_input[8][8];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int visited[8][8];

int dfs(int curr_y, int curr_x)
{
	int cnt = 1;
	visited[curr_y][curr_x] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_y = curr_y + dir[i][0];
		int next_x = curr_x + dir[i][1];

		if (next_y >= 0 && next_x >= 0 && next_y < N && next_x < M)
		{
			if (copy_input[next_y][next_x] == 0 && !visited[next_y][next_x])
				cnt += dfs(next_y, next_x);
		}
	}
	return cnt;
}

int main()
{
	scanf("%d %d", &N, &M);
	vector<pair<int, int>> empty;
	vector<pair<int, int>> virus;
	int nWall = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			int tmp;
			scanf("%d", &tmp);
			input[y][x] = tmp;
			if (tmp == 0)
				empty.push_back(make_pair(y, x));
			else if (tmp == 2)
				virus.push_back(make_pair(y, x));
			else
				nWall++;
		}
	
	int max_safe = numeric_limits<int>::min();

	for (int i = 0; i < empty.size(); i++)
	{
		for (int j = i+1; j < empty.size(); j++)
		{
			for (int k = j+1; k < empty.size(); k++)
			{
				memcpy(copy_input, input, sizeof input);
				copy_input[empty[i].first][empty[i].second] = 1;
				copy_input[empty[j].first][empty[j].second] = 1;
				copy_input[empty[k].first][empty[k].second] = 1;

				memset(visited, 0, sizeof visited);
				int nVirus = 0;
				for(int v = 0; v < virus.size(); v++)
				{
					if (!visited[virus[v].first][virus[v].second])
						nVirus += dfs(virus[v].first, virus[v].second);
				}
				int rCnt = (N*M) - (nWall + 3 + nVirus);
				if (rCnt > max_safe)
					max_safe = rCnt;
			}
		}
	}
	printf("%d\n", max_safe);

	return 0;

}