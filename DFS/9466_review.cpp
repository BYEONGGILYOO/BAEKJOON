#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T, N;
int input[100001];
bool visited[100001], finished[100001];

int cnt = 0; // count the vertexes on the cycle
void dfs(int curr)
{
    visited[curr] = true;
    int next = input[curr];

    if(visited[next])
    {
        if(!finished[next])
        {
            // 4->7->6 curr:6, next:4
            // i=4,7
            for(int i=next; i!=curr; i=input[i])
                cnt++;
            cnt++;
        }
    }else
        dfs(next);
    finished[curr] = true;
}

int main()
{
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        scanf("%d", &N);
        for(int j=1; j<=N; j++)
            scanf("%d", &input[j]);

        memset(visited, 0, sizeof visited);
        memset(finished, 0, sizeof finished);
        cnt = 0;

        for(int j=1; j<=N; j++)
        {
            if(!visited[j])
                dfs(j);
        }
        printf("%d\n", N-cnt);
    }
    return 0;
}
