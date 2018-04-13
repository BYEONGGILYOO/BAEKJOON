#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, L;
int input[100][100];
int visited[100][100];
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};

void dfs(int curr_y, int curr_x)
{
    visited[curr_y][curr_x] = true;
    int curr_height = input[curr_y][curr_x];

    for(int i=0; i<4; i++)
    {
        int next_y = curr_y + dir[i][0];
        int next_x = curr_x + dir[i][0];

        if(next_y >= 0 && next_x >= 0 && next_y < N && next_x < N)
        {
            int next_height = input[next_y][next_x];
            if(curr_height == next_height)
                dfs(next_y, next_x);
            else if(abs(curr_height - next_height) == 1)
            {

            }
        }
    }

}

int main()
{
    scanf("%d%d", &N, &L);

    for(int y=0; y<N; y++)
        for(int x=0; x<N; x++)
            scanf("%d", &input[y][x]);

    for(int y=0; y<N; y++)
    {
        int slope_cnt = 0;
        for(int x=0; x<N-1; x++)
        {
            int now = input[y][x];
            int next = input[y][x+1];

            if(abs(now-next) == 1)
            {
                if(slope_cnt == L)
                {

                }
            }

        }
    }

}
