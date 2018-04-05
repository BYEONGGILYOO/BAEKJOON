#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N[100000];
bool visited[100000], finished[100000];
int cnt = 0;

void dfs(int curr)
{
    int next = N[curr];
    visited[curr] = true;

    if(visited[next])
    {
        if(!finished[next])
        {
            for(int i = next; i != curr; i = N[i])
                cnt++;
			cnt++;
        }
    }
    else
        dfs(next);

    finished[curr] = true;
}

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int n;
        scanf("%d",&n);
		
		// initialize
		fill(N, N + n, 0);
		fill(visited, visited + n, false);
		fill(finished, finished + n, false);
		cnt = 0;

		// get the input
        for(int i=0; i<n; i++)
        {
            scanf("%d",&N[i]);
			N[i]--;
        }
		
		// DFS
		for (int i = 0; i < n; i++)
			if(!visited[i])
				dfs(i);

		printf("%d\n", n - cnt);
    }

	return 0;
}
