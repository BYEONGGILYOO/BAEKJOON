#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dir[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};
int back[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int rows, cols;
bool input[50][50];
bool visited[50][50];

// dir def : 0 top, 1 left, 2 bottom, 3 right
int cnt = 0;

void dfs(int curr_r, int curr_c, int curr_dir)
{
    visited[curr_r][curr_c] = true;
    bool flag = false;

    int next_dir = curr_dir;
    for(int i=0; i<4; i++)
    {
        int next_r = curr_r + dir[next_dir][0];
        int next_c = curr_c + dir[next_dir][1];
        next_dir += 1;
        if(next_dir == 4) next_dir = 0;

        if(next_r >= 0 && next_c >= 0 && next_r < rows && next_c < cols)
        {
            if(!visited[next_r][next_c] && !input[next_r][next_c])
            {
                cnt++;
                dfs(next_r, next_c, next_dir);
                flag = true;
                break;
            }
        }
    }
    if(!flag)
    {
        next_dir = curr_dir;
        while(1)
        {
            int next_r = curr_r + back[next_dir][0];
            int next_c = curr_c + back[next_dir][1];
            next_dir += 1;
            if(next_dir == 4) next_dir = 0;

            if(next_r >= 0 && next_c >= 0 && next_r < rows && next_c < cols)
            {
                if(!input[next_r][next_c])
                    dfs(next_r, next_c, next_dir);
                else
                    return;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &rows, &cols);

    int curr_r, curr_c, curr_dir;
    scanf("%d%d%d", &curr_r, &curr_c, &curr_dir);

    for(int y=0; y<rows; y++)
        for(int x=0; x<cols; x++)
            scanf("%d", input[y][x]);

    dfs(curr_r, curr_c, curr_dir);

    printf("%d\n", cnt);
}
