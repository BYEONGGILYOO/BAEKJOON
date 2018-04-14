#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CW 1
#define CCW -1
#define SWAP(a) a == 1 ? -1 : 1

// N:0, S:1
vector<vector<bool>> topni(4);
vector<pair<int, int>> info;
int K;
bool visited[4];

void rotation(vector<bool>& t, int dir)
{
	if (dir == CW)
	{
		int right = *t.rbegin();
		t.pop_back();
		t.insert(t.begin(), right);
	}
	else if (dir == CCW)
	{
		int left = *t.begin();
		t.erase(t.begin());
		t.push_back(left);
	}
}

bool isDiff(vector<bool>& t1, vector<bool>& t2)
{
	if (t1[2] != t2[6])
		return true;
	else
		return false;
}

void dfs(int curr, int dir)
{
	visited[curr] = true;
	int prev = curr - 1;
	if (prev >= 0)
	{
		if (!visited[prev])
		{
			if (isDiff(topni[prev], topni[curr]))
			{
				dfs(prev, SWAP(dir));
			}
		}
	}

	int next = curr + 1;
	if (next < 4)
	{
		if (!visited[next])
		{
			if (isDiff(topni[curr], topni[next]))
			{
				dfs(next, SWAP(dir));
			}
		}
	}
	rotation(topni[curr], dir);

	return;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		vector<bool> _topni(8);
		for (int j = 0; j < 8; j++)
		{
			int tmp;
			scanf("%1d", &tmp);
			_topni[j] = (bool)tmp;
		}
		topni[i] = _topni;
	}
	scanf("%d", &K);
	info.resize(K);
	for (int i = 0; i < K; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		info[i] = make_pair(tmp1-1, tmp2);
	}

	//
	for (vector<pair<int,int>>::iterator itr = info.begin();
		itr != info.end(); ++itr)
	{
		memset(visited, 0, sizeof visited);
		dfs(itr->first, itr->second);
	}
	
	int results = *topni[0].begin() + *topni[1].begin() * 2 + *topni[2].begin() * 4 + *topni[3].begin() * 8;
	printf("%d\n", results);

	return 0;	
}