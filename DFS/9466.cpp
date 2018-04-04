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
            for(int i = next; i !=  curr; i = N[i])
                cnt++;
        }
        cnt++;
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
        for(int i=0; i<n; i++)
        {
            scanf("%d",&N[i]);
        }

    }
}
