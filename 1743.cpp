#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

#define ROW 100
#define COL 100

int adj[ROW][COL];
int visited[ROW][COL];
int calMatrix[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int row, col, n;
int maxComponents = numeric_limits<int>::min();

int dfs(int x, int y);
void search()
{
    for(int y=0; y<row; y++)
    {
        for(int x=0; x<col; x++)
        {
            if(adj[y][x] && !visited[y][x])
            {
                int comp = 0;
                visited[y][x] = true;
                comp ++;
                comp += dfs(x,y);
                cout << "components: " << comp << endl;
                if(comp > maxComponents)
                    maxComponents = comp;
            }
        }
    }

}

int dfs(int x, int y)
{
    cout << "==========dfs(" << x << "," << y << ")===========" << endl;
    int components = 0;
    for(int i=0; i<4; i++)
    {
        int xx = x + calMatrix[i][1];
        int yy = y + calMatrix[i][0];

        if(xx >= 0 && yy >= 0 && xx < col && yy < row)
        {
            cout << "loop: " << i << " xx: " << xx << " yy: " << yy << endl;
            cout << "adj: " << adj[yy][xx] << " visited: " << visited[yy][xx] << endl;
            if(adj[yy][xx] && !visited[yy][xx])
            {
                visited[yy][xx] = true;
                components++ ;
                dfs(xx,yy);
            }
        }
    }
    return components;
}

int main(int argc, char** argv)
{
    scanf("%d%d%d",&row,&col,&n);

    memset(adj, 0, sizeof adj);
    memset(visited, 0, sizeof visited);

    for(int i=0; i<n; i++)
    {
        int yy, xx;
        scanf("%d%d",&yy, &xx);
        yy--, xx--;

        adj[yy][xx] = true;
    }
    search();

    cout << maxComponents << endl;

    return 0;
}
