#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int K;
int input[1001];
bool visited[1001];
bool finished[1001];
int cnt;
bool overflow;

void dfs(int n)
{
    visited[n] = true;
    int next = input[n];

    //if(cnt > K || overflow)
    //{
    //    overflow = true;
    //    //return;
    //}

    if(visited[next])
    {
        if(!finished[next])
        {
            int temp = next;
            for(int i=1; i!=n; i++)
            {
                if(input[i] == temp)
                {
                    cnt++;
                    temp = 
                }
            }
            for(int i=next; i!=n; i=input[i])
                cnt++;
            cnt++;
            if(cnt > K)
                cnt = 0;
        }
    }
    else
        dfs(next);

    finished[n] = true;
    return;
}

int main()
{
    scanf("%d %d", &N, &K);

    for(int i=1; i<=N; i++)
        scanf("%d", &input[i]);

    memset(visited, 0, sizeof visited);
    memset(finished, 0, sizeof finished);

    int max_components = -N*N-1;
    for(int i=1; i<=N; i++)
    {
        cnt = 0;
        overflow = false;
        if(!visited[i])
        {
            dfs(i);
            printf("index: %d, --> %d\n", i, cnt);
            if(cnt > max_components)
                max_components = cnt;
        }
    }
    printf("%d\n", max_components);

    return 0;
}
