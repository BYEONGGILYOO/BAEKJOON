#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N = 0;
bool adj[100][100] = {0};
bool visited[100][100] = {0};

bool dfs(int curr_from, int curr_to)
{
    if(adj[curr_from][curr_to] || visited[curr_from][curr_to])
        return true;
    else return false;

    int next_to = curr_to;
    for(int i=0; i<N; i++)
    {
        if(i == curr_from || i == curr_to)
            continue;

        if(dfs(i,next_to))
        {
            visited[i][next_to] = true;
            next_to = i;

            if(i == curr_from)
                return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &adj[i][j]);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            if(dfs(i,j))
                visited[i][j] = true;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            printf("%d ", visited[i][j]);
        printf("\n");
    }

    return 0;
}
