#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int input[100][100];
bool visited[100][100];
int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int water_level = 0;

void dfs(int y, int x)
{
    visited[y][x] = true;

    for(int i=0; i<4; i++)
    {
        int new_y = y + direction[i][0];
        int new_x = x + direction[i][1];

        if(new_y >= 0 && new_x >=0 && new_y < N && new_x < N)
        {
            if(input[new_y][new_x] - water_level > 0 && !visited[new_y][new_x])
                dfs(new_y,new_x);
        }
    }
}

int main()
{
    scanf("%d", &N);

    for(int y=0; y<N; y++)
        for(int x=0; x<N; x++)
            scanf("%d", &input[y][x]);

    int max_components = -N*N+1;
    for(int i=0; i<=100; i++)
    {
        water_level = i;
        memset(visited, 0, sizeof visited);
        int components = 0;
        for(int y=0; y<N; y++)
            for(int x=0; x<N; x++)
            {
                if(!visited[y][x] && input[y][x] - water_level > 0)
                {
                    dfs(y,x);
                    components++;
                }
                visited[y][x] = true;
            }
        if(components > max_components)
            max_components = components;
    }

    printf("%d\n", max_components);

    return 0;
}
