#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N = 0;
bool house[25][25] = {0};
bool visited[25][25] = {false};
int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

int dfs(int curr_x, int curr_y)
{
    int cnt = 1;
    visited[curr_x][curr_y] = true;
    if(!house[curr_x][curr_y])
        return 0;

    for(int i=0; i<4; i++)
    {
        int new_x = curr_x + dir[i][0];
        int new_y = curr_y + dir[i][1];

        if(new_x >= 0 && new_y >= 0 && new_x < N && new_y < N)
            if(!visited[new_x][new_y] && house[new_x][new_y])
            {
                cnt += dfs(new_x, new_y);
            }
    }
    return cnt;
}

int main(int argc, char** argv)
{
    scanf("%d",&N);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%1d", &house[i][j]);

    vector<int> results;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(!visited[i][j])
            {
                int score = dfs(i,j);
                if(score != 0)
                    results.push_back(score);
            }
        }

    sort(results.begin(), results.end());
    printf("%d\n", (int)results.size());
    for(vector<int>::iterator itr = results.begin();
            itr != results.end(); ++itr)
        printf("%d\n", *itr);

    return 0;
}
