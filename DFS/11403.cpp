#include <iostream>

using namespace std;

int input[100][100];
bool visited[100][100];
int N;

void dfs(int top, int x, int y)
{
	input[top][y] = 1;
	visited[top][y] = true;

	for (int i = 0; i < N; i++)
	{
		if (!visited[top][i] && input[y][i])
			dfs(top, y, i);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &input[i][j]);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][i] && input[i][j])
				dfs(i, i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", input[i][j]);
		printf("\n");
	}

	return 0;
}