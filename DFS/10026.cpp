#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N = 0;
int color[100][100] = {0};
bool visited[100][100] = {0};
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int RGB_cnt[4] = {0};

void dfs(int curr_x, int curr_y, bool color_blindness = false)
{
    visited[curr_x][curr_y] = true;
    int curr_color = color[curr_x][curr_y];

    if(color_blindness && curr_color == 2)
        curr_color = 1;

    for(int i=0; i<4; i++)
    {
        int new_x = curr_x + dir[i][0];
        int new_y = curr_y + dir[i][1];

        if(new_x >= 0 && new_y >= 0 && new_x < N && new_y < N)
        {
            int new_color = color[new_x][new_y];
            if(color_blindness && new_color == 2)
                new_color = 1;
            if(!visited[new_x][new_y] && new_color == curr_color)
                dfs(new_x, new_y, color_blindness);
        }
    }
}
int main(int argc, char** argv)
{
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        char* tmp = new char[N+1];
        scanf("%s", tmp);
        for(int j=0; j<N; j++)
        {
            if(tmp[j] == 'R')
                color[i][j] = 1;
            else if(tmp[j] == 'G')
                color[i][j] = 2;
            else if(tmp[j] == 'B')
                color[i][j] = 3;
            else
                printf("ERROR\n");
        }
        delete[] tmp;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(!visited[i][j])
            {
                RGB_cnt[color[i][j]]++;
                dfs(i,j);
            }
    printf("%d\n",RGB_cnt[1]+RGB_cnt[2]+RGB_cnt[3]);

    memset(visited, 0, sizeof(visited));
    memset(RGB_cnt, 0, sizeof(RGB_cnt));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(!visited[i][j])
            {
                RGB_cnt[color[i][j]]++;
                dfs(i,j,true);
            }
    printf("%d\n",RGB_cnt[1]+RGB_cnt[2]+RGB_cnt[3]);

    return 0;
}
