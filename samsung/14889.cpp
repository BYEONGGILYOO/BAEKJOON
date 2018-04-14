#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>

using namespace std;

int N;
int input[20][20];
int visited[20];
int cnt = 0;
int res = numeric_limits<int>::max();

int getSum(vector<int> v)
{
	int m = N / 2;
	int sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			sum += input[v[i]][v[j]];
	return sum;
}
void dfs(int curr)
{
	visited[curr] = true;
	cnt++;

	if (cnt == N / 2)
	{
		vector<int> a, b;
		for (int i = 0; i < N; i++)
		{
			if (visited[i])
				a.push_back(i);
			else
				b.push_back(i);
		}
		int aa = getSum(a);
		int bb = getSum(b);

		if (abs(aa - bb) < res)
			res = abs(aa - bb);
	}
	else
	{
		for (int i = curr + 1; i < N; i++)
		{
			if (!visited[i])
				dfs(i);
		}
	}
	cnt--;
	visited[curr] = false;	
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			scanf("%d", &input[y][x]);

	dfs(0);
	printf("%d\n", res);

	return 0;
}